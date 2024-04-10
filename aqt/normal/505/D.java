import java.util.*;
import java.io.*;

public class _0505_D_MrKitayutasTechnology {
	
	static ArrayList<Integer> dgraph[];
	
	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt();
		dgraph = new ArrayList[N+1];
		ArrayList<Integer> graph[] = new ArrayList[N+1];
		for(int i=  1; i<=N; i++) {
			graph[i] = new ArrayList<>();
			dgraph[i] = new ArrayList<>();
		}
		for(int i = 1; i<=M; i++) {
			int a = readInt(), b = readInt();
			graph[a].add(b); graph[b].add(a);
			dgraph[a].add(b);
		}
		vis = new boolean[N+1];
		instk = new boolean[N+1];
		int sz[] = new int[N+1];
		int clr[] = new int[N+1];
		int cnt = 0;
		for(int i =1; i<=N; i++) if(!vis[i]) {
			cnt++;
			LinkedList<Integer> ll = new LinkedList<>();
			ll.add(i);
			while(!ll.isEmpty()) {
				int n = ll.pop();
				vis[n] = true;
				clr[n] = cnt;
				sz[cnt]++;
				for(int e : graph[n]) if(!vis[e]) {
					ll.add(e);
					vis[e] = true;
				}
			}
		}
		vis = new boolean[N+1];
		boolean cycle[] = new boolean[cnt+1];
		for(int i = 1; i<=N; i++) {
			if(cycle[clr[i]]) continue;
			if(!vis[i]) cycle[clr[i]] = cycle(i);
		}
		int tot = 0;
		for(int i = 1; i<=cnt; i++) {
			tot += sz[i]-1;
			if(cycle[i])tot++;
		}
		println(tot);
		exit();
	}
	
	static boolean vis[];
	static boolean instk[];
	
	static boolean cycle(int n) {
		vis[n] = instk[n] = true;
		for(int e : dgraph[n]) {
			if(instk[e]) return true;
			if(!vis[e] && cycle(e)) return true;
		}
		instk[n] = false;
		return false;
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