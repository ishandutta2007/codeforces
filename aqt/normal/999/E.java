import java.util.*;
import java.io.*;

public class _999_E_ReachilityFromTheCaptial {

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), C = readInt(); ArrayList<Integer> graph[] = new ArrayList[N+1];
		for(int i = 1; i<=N; i++) graph[i] = new ArrayList<>();
		for(int i = 1; i<=M; i++) {int a = readInt(), b = readInt(); graph[b].add(a);}
		boolean canReach[][] = new boolean[N+1][N+1]; LinkedList<Integer> ll = new LinkedList<>(); 
		int par[] = new int[N+1]; for(int i =1; i<=N; i++) par[i] = i; for(int i = 1; i<=N; i++) {
			ll.add(i); canReach[i][i] = true; while(!ll.isEmpty()) {
				int n = ll.pop(); for(int e : graph[n]) if(!canReach[i][e]) {canReach[i][e] = true; ll.add(e);}
			}
		}
		for(int i = 1; i<=N; i++) for(int j = i+1; j<=N; j++) if(find(i, par) != find(j, par)) {
			if(canReach[i][j] && canReach[j][i]) par[find(j, par)] = find(i, par);
		}
		int cnt = 1, fatnode[] = new int[N+1]; for(int i = 1; i<=N; i++) if(par[i] == i) {fatnode[i] = cnt++;} 
		boolean outdegree[] = new boolean[cnt]; for(int i =1; i<=N; i++) for(int e : graph[i]) {
			if(find(e, par) != find(i, par)) {outdegree[fatnode[find(i, par)]] = true; break;}
		}
		int tot = 0; for(int i = 1; i<cnt; i++) tot += !outdegree[i] ? 1 : 0;
		if(!outdegree[fatnode[find(C, par)]]) tot--; println(tot);
		exit();
	}
	
	public static int find(int n, int par[]) {
		return  par[n] = n == par[n] ? n : find(par[n], par);
	}

	
//	39 40 38
//	4 8
//	24 28
//	16 17
//	7 25
//	4 29
//	34 35
//	16 24
//	21 10
//	23 36
//	36 14
//	28 16
//	34 19
//	15 21
//	22 38
//	22 37
//	37 27
//	28 33
//	3 29
//	32 22
//	12 30
//	9 15
//	5 19
//	23 27
//	19 17
//	25 17
//	24 11
//	39 10
//	6 20
//	16 6
//	3 18
//	34 21
//	15 38
//	11 19
//	11 3
//	32 4
//	15 13
//	16 11
//	11 7
//	33 7
//	3 33
	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static String readLine() throws IOException {
		byte[] buf = new byte[64]; // line length
		int cnt = 0, c;
		while ((c = Read()) != -1) {
			if (c == '\n')
				break;
			buf[cnt++] = (byte) c;
		}
		return new String(buf, 0, cnt);
	}

	public static String read() throws IOException {
		byte[] ret = new byte[1024];
		int idx = 0;
		byte c = Read();
		while (c <= ' ') {
			c = Read();
		}
		do {
			ret[idx++] = c;
			c = Read();
		} while (c != -1 && c != ' ' && c != '\n' && c != '\r');
		return new String(ret, 0, idx);
	}

	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (neg)
			return -ret;
		return ret;
	}

	public static long readLong() throws IOException {
		long ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
		if (neg)
			return -ret;
		return ret;
	}

	public static double readDouble() throws IOException {
		double ret = 0, div = 1;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();

		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (c == '.') {
			while ((c = Read()) >= '0' && c <= '9') {
				ret += (c - '0') / (div *= 10);
			}
		}

		if (neg)
			return -ret;
		return ret;
	}

	private static void fillBuffer() throws IOException {
		bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesRead == -1)
			buffer[0] = -1;
	}

	private static byte Read() throws IOException {
		if (bufferPointer == bytesRead)
			fillBuffer();
		return buffer[bufferPointer++];
	}

	static void print(Object o) {
		pr.print(o);
	}

	static void println(Object o) {
		pr.println(o);
	}

	static void flush() {
		pr.flush();
	}

	static void println() {
		pr.println();
	}

	static void exit() throws IOException {
		din.close();
		pr.close();
		System.exit(0);
	}
}