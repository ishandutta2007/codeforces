import java.util.*;
import java.io.*;

public class _342_E_XeniaAndTree {
	
	static ArrayList<Integer> graph[]; static int N, cent[][], dist[][], mindist[], dep[], sz[], par[];
	static boolean vis[];

	public static void main(String[] args) throws IOException {
		N= readInt(); int Q = readInt(); graph = new ArrayList[N+1]; for(int i = 1; i<=N; i++) graph[i] = new ArrayList<Integer>();
		for(int i = 1; i<N; i++) {int a = readInt(), b = readInt(); graph[a].add(b); graph[b].add(a);}
		dist = new int[N+1][20]; for(int i = 1; i<=N; i++) for(int d = 1; d<=19; d++) dist[i][d] = Integer.MAX_VALUE; 
		cent = new int[N+1][20]; dep = new int[N+1]; sz = new int[N+1]; par = new int[N+1]; vis = new boolean[N+1];
		mindist = new int[N+1]; Arrays.fill(mindist, Integer.MAX_VALUE); getCentroid(1, 1);
		for(int i = dep[1]; i>0; i--) mindist[cent[1][i]] = Math.min(mindist[cent[1][i]], dist[1][i]);
		for(int q = 0; q<Q; q++) {
			if(readInt() == 2) {
				int n = readInt(), ans = Integer.MAX_VALUE;
				for(int i = dep[n]; i>0; i--) if(mindist[cent[n][i]] != Integer.MAX_VALUE) 
					ans = Math.min(ans, mindist[cent[n][i]] + dist[n][i]); 
				println(ans);
			}
			else {
				int n = readInt();
				for(int i = dep[n]; i>0; i--) mindist[cent[n][i]] = Math.min(mindist[cent[n][i]], dist[n][i]);
			}
		}
		exit();
	}
	
	public static void getCentroid(int n, int d) {
		par[n] = 0; dfs1(n); int size = sz[n]; //System.out.println(n);
		while(true) {
			int hvy = 0; for(int e : graph[n]) if(!vis[e] && par[n] != e) hvy = sz[hvy] < sz[e] ? e : hvy;
			if(sz[hvy]*2 > size) n = hvy; else break; 
		}
		par[n] = 0; dep[n] = d; cent[n][d] = n; dist[n][d] = 0; dfs2(n, d); vis[n] = true;
		for(int e : graph[n]) if(!vis[e]) getCentroid(e, d + 1);
	}
	
	public static void dfs1(int n) {
		sz[n] = 1; for(int e : graph[n]) if(!vis[e] && e != par[n]){
			par[e] = n; dfs1(e); sz[n] += sz[e];
		}
	}
	
	public static void dfs2(int n, int d) {
		for(int e : graph[n]) if(!vis[e] && e != par[n]) {
			par[e] = n; dist[e][d] = dist[n][d] + 1; cent[e][d] = cent[n][d]; dfs2(e, d);
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