import java.util.*;
import java.io.*;

public class _1006_E {

	static Stack<Integer> graph[]; static Stack<Integer> stk = new Stack<>();
	static int par[], sz[], arr[], time = 0, oc[];
	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt(); graph = new Stack[N+1]; for(int i = 1; i<=N; i++) graph[i] = new Stack<>();
		par = new int[N+1]; sz = new int[N+1]; for(int i = 2; i<=N; i++) graph[par[i] = readInt()].add(i); arr = new int[N+1];
		oc = new int[N+1]; dfs(1); for(int i = N; i>1; i--) sz[par[i]] += sz[i];
		for(int i = 1; i<=Q; i++) {
			int n = readInt(), p = readInt(); if(p > sz[n]) println(-1); else {
				try{println(arr[oc[n]+p-1]);}catch(Exception e) {println(-1);}
			}
		}
		exit();
	}

	public static void dfs(int n) {
		stk.add(n); while(!stk.isEmpty()) {
			n = stk.pop(); sz[n]++; arr[++time] = n; oc[n] = time; while(!graph[n].isEmpty()) stk.add(graph[n].pop());
		}
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
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