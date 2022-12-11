import java.util.*;
import java.io.*;

public class _1005_F {
	
	public static class Edge{
		int to, id;
		public Edge(int to, int id) {
			this.to= to; this.id = id;
		}
	}
	
	static boolean tkn[], vis[]; static int cnt, ans = 0; static ArrayList<Integer> DAG[]; static int N;

	public static void main(String[] args) throws IOException {
		N = readInt(); int M = readInt(), K = readInt(); 
		ArrayList<Edge> graph[] = new ArrayList[N+1]; DAG = new ArrayList[N+1]; 
		for(int i = 1; i<=N; i++) {graph[i] = new ArrayList<>(); DAG[i] = new ArrayList<>();}
		for(int i = 1;i<=M; i++) {int a = readInt(), b = readInt(); graph[a].add(new Edge(b, i));graph[b].add(new Edge(a, i));}
		int dist[] = new int[N+1]; long way[] = new long[N+1]; Arrays.fill(dist, Integer.MAX_VALUE); dist[1] = 0; way[1] = 1;
		LinkedList<Integer> ll = new LinkedList<>(); ll.add(1);while(!ll.isEmpty()) {
			int n = ll.pop(); boolean last = true; for(Edge e : graph[n]) {
				if(dist[e.to] > dist[n] + 1) {dist[e.to] = dist[n] + 1; ll.add(e.to);}
				if(dist[e.to] == dist[n] + 1) {DAG[e.to].add(e.id); way[e.to] = Math.min(way[n] + way[e.to], K); last = false;}
			}
		}
		long tot = 1; for(int i = 2; i<=N; i++) { tot *= DAG[i].size(); if(tot > K) break;}
		println(Math.min(tot, K));
		                                                  tkn = new boolean[M+1]; ans = K; rec(2);
		exit();
	}
	
	public static void rec(int n) throws IOException {
		if(n == N+1) {
			ans--;
			for(int i = 1; i<tkn.length; i++) print(tkn[i] ? 1 : 0);
			println();
			if(ans == 0) exit(); return;
		}
		for(int i : DAG[n]) {
			tkn[i] = true; rec(n+1); tkn[i] = false;
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