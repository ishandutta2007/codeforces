import java.util.*;
import java.io.*;

public class _766_E_MahmoudAndAXORTrip {

	static int val[], N, par[], sz[], dist[]; static ArrayList<Integer> graph[]; static boolean vis[];

	public static void main(String[] args) throws IOException {
		N = readInt(); val = new int[N+1]; for(int i= 1; i<=N; i++) val[i] = readInt();
		graph=new ArrayList[N+1]; for(int i= 1; i<=N; i++) graph[i] = new ArrayList<Integer>();
		for(int i = 1; i<N; i++){int a=readInt(), b=readInt(); graph[a].add(b); graph[b].add(a);}
		vis = new boolean[N+1]; par = new int[N+1]; sz = new int[N+1]; dist = new int[N+1]; println(solve(1));
		exit();
	}

	public static int getCentroid(int n) {
		par[n] = 0; dfs(n); int size = sz[n];
		while(true) {
			int mx = 0; for(int e : graph[n]) if(!vis[e] && e != par[n]) {
				mx = sz[e] > sz[mx] ? e : mx; 
			}
			if(sz[mx]*2 > size) n = mx;
			else return n;
		}
	}

	public static void dfs(int n) {
		sz[n] = 1; for(int e : graph[n]) if(!vis[e] && par[n] != e) {
			par[e] = n; dfs(e); sz[n] += sz[e];
		}
	}

	public static long solve(int n) {
		long tot = 0, paths = 1; n = getCentroid(n); vis[n] = true; par[n] = 0; tot = val[n];
		long bit[] = new long[22]; for(int i = 0; i<22; i++) if(((1<<i)&val[n]) != 0) bit[i]++;
		Stack<Integer> ll = new Stack<Integer>(), stk = new Stack<Integer>(); 
		for(int edge : graph[n]) if(!vis[edge]){
			ll.add(edge); dist[edge] = val[edge]; par[edge] = n;
			while(!ll.isEmpty()) {
				int crnt = ll.pop(); stk.add(dist[crnt]); int mask = dist[crnt];
				for(int i = 0; i<22; i++) {
					if(((1<<i)&mask) != 0) tot += (paths-bit[i])*(1<<i);
					else tot += bit[i]*(1<<i);
				}
				for(int e : graph[crnt]) if(!vis[e] && par[crnt] != e) {
					dist[e] = dist[crnt] ^ val[e]; par[e] = crnt; ll.add(e);
				}
			}
			paths += stk.size(); while(!stk.isEmpty()) {
				int mask = stk.pop()^val[n]; for(int i = 0; i<22; i++) if(((1<<i)&mask) != 0) bit[i]++;
			}
		}
		for(int e : graph[n]) if(!vis[e]) tot += solve(e); return tot;
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