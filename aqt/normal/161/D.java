import java.util.*;
import java.io.*;

public class _0161_D_DistanceInTree {

	public static void main(String[] args) throws IOException {
		N = readInt(); K = readInt();
		par = new int[N+1]; sz = new int[N+1]; dist = new int[N+1]; vis = new boolean[N+1];
		graph = new ArrayList[N+1];
		for(int i= 1; i<=N; i++) graph[i] = new ArrayList<>();
		for(int i = 1; i<N; i++) {
			int a = readInt(), b = readInt();
			graph[a].add(b); graph[b].add(a);
		}
		solve(1);
		println(ans);
		exit();
	}

	static ArrayList<Integer> graph[];
	static int par[], sz[], dist[];
	static boolean vis[];
	static int N, K;
	static long ans = 0;

	static int getcentroid(int n) {
		par[n] = 0; 
		dfs(n);
		int size = sz[n];
		while(true) {
			int maxidx = 0;
			for(int e : graph[n]) {
				if(!vis[e] && par[n] != e) {
					maxidx = sz[maxidx] < sz[e] ? e : maxidx;
				}
			}
			if(sz[maxidx]*2 > size) n = maxidx;
			else return n;
		}
	}

	static void dfs(int n) {
		sz[n] = 1;
		for(int e : graph[n]) {
			if(par[n] != e && !vis[e]) {
				par[e] = n;
				dfs(e);
				sz[n] += sz[e];
			}
		}
	}

	static void solve(int n) {
		n = getcentroid(n); 
		vis[n] = true;
		int totdist[] = new int[K+1];
		dist[n] = 0;
		totdist[0]++;
		for(int s : graph[n]) {
			if(vis[s]) continue;
			par[s] = n;
			LinkedList<Integer> ll = new LinkedList<>();
			ll.add(s);
			ArrayList<Integer> al = new ArrayList<>();
			dist[s] = 1;
			while(!ll.isEmpty()) {
				int crnt = ll.pop();
				al.add(crnt);
				ans += totdist[K-dist[crnt]];
				if(dist[crnt] == K) continue;
				for(int e : graph[crnt]) {
					if(!vis[e] && par[crnt] != e) {
						dist[e] = dist[crnt] + 1;
						ll.add(e);
						par[e] = crnt;
					}
				}
			}
			for(int v : al) totdist[dist[v]]++;
		}
		for(int e : graph[n]) 
			if(!vis[e])
				solve(e);
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