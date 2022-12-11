import java.util.*;
import java.io.*;

public class _546_E_SoldierAndTraveling {

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), a[] = new int[N+1], b[] = new int[N+1], graph[][] = new int[2*N+2][2*N+2];
		for(int i = 1; i<=N; i++) a[i] = readInt(); for(int i = 1; i<=N; i++) b[i] = readInt();
		for(int i = 1; i<=N; i++) {graph[0][i] = a[i]; graph[N+i][2*N+1] = b[i]; graph[i][N+i] = 1000000;}
		for(int i = 1; i<=M; i++) {int u = readInt(), v = readInt(); graph[u][N+v] = graph[v][N+u] = 1000000;}
		int sum1 = 0, sum2 = 0; for(int i = 1; i<=N; i++) sum1 += a[i]; for(int i = 1; i<=N; i++) sum2 += b[i];
		if(sum1 != sum2) {println("NO"); exit();}
		int flow = 0, tot = 0, par[] = new int[2*N+2];  LinkedList<Integer> ll = new LinkedList<>(); do {
			ll.add(0); Arrays.fill(par, -1); par[0]--;while(!ll.isEmpty()) {
				int n = ll.pop(); for(int e = 0; e<=2*N+1; e++) if(par[e] == -1 && graph[n][e] > 0) {
					par[e] = n; ll.add(e);
				}
			}
			if(par[2*N+1] == -1) break;
			flow = Integer.MAX_VALUE; int crnt = 2*N+1; 
			while(crnt != 0) {flow = Math.min(graph[par[crnt]][crnt], flow); crnt = par[crnt]; }
			crnt = 2*N+1; tot += flow; while(crnt != 0) {
				graph[par[crnt]][crnt] -= flow; graph[crnt][par[crnt]] += flow; crnt = par[crnt];
			}
		} while(flow > 0); 
		if(tot != sum1) {println("NO"); exit();} println("YES");
		for(int i = 1; i<=N; i++) {for(int j = 1; j<=N; j++) {
			if(graph[i][j+N] == 0) print(0 + " "); else print(1000000-graph[i][j+N] + " ");} println();}
		
		
		exit();
	}
	
	

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

	public void close() throws IOException {
		if (din == null)
			return;
		din.close();
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