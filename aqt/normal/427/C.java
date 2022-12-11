import java.util.*;
import java.io.*;

public class _0427_C_Checkposts {

	static int N, val[], par[], low[], time = 0; static long MOD = (long) 1e9+7, cnt = 1, tot = 0;
	static boolean vis[]; static ArrayList<Integer> graph[]; static Stack<Integer> stk = new Stack<>();

	public static void main(String[] args) throws IOException {
		N = readInt(); val = new int[N+1]; for(int i =1; i<=N; i++) val[i] = readInt();
		graph = new ArrayList[N+1]; for(int i = 1; i<=N; i++) graph[i] = new ArrayList<>();
		int M = readInt(); for(int i = 1; i<=M; i++) graph[readInt()].add(readInt());
		par = new int[N+1]; low = new int[N+1]; vis = new boolean[N+1]; for(int i = 1; i<=N; i++) if(!vis[i]) dfs(i);
		println(tot + " " + cnt); exit();
	}

	public static void dfs(int n) {
		vis[n] = true; low[n] = ++time; stk.add(n); boolean isRoot = true; for(int e : graph[n]) {
			if(!vis[e]) dfs(e); if(low[n] > low[e]) {isRoot = false; low[n] = low[e];}
		}
		if(isRoot) {
			int min = val[n], count = 1; low[n] = Integer.MAX_VALUE; while(!stk.isEmpty()) {
				int x = stk.pop(); if(x == n) break; 
				if(min > val[x]) {min = val[x]; count = 1;} else if(min == val[x]) count++;
				low[x] = Integer.MAX_VALUE; 
			}
			tot += min; cnt = (count*cnt)%MOD;
		}
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