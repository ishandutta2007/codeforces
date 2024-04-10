import java.util.*;
import java.io.*;

public class _0087_D_BeautifulRoad {

	static class Edge implements Comparable<Edge>{
		int u, v, val, id;
		public Edge(int u, int v, int val, int id) {
			this.u = u;
			this.v = v;
			this.val = val;
			this.id = id;
		}
		public int compareTo(Edge e) {
			return Integer.compare(this.val, e.val);
		}
	}
	
	static int par[];
	static long dpsz[], sz[];
	static int clr[];
	static ArrayList<Integer> graph[];
	static int find(int n) {
		return par[n] = par[n] == n ? n : find(par[n]);
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt();
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		for(int i = 1; i<N; i++) pq.add(new Edge(readInt(), readInt(), readInt(), i));
		par = new int[N+1];
		for(int i = 1; i<=N; i++) par[i] = i;
		long cnt[] = new long[N];
		dpsz = new long[N+1];
		sz = new long[N+1];
		Arrays.fill(sz, 1);
		clr = new int[N+1];
		graph = new ArrayList[N+1];
		int last[] = new int[N+1];
		while(!pq.isEmpty()) {
			int v = pq.peek().val;
			ArrayList<Edge> al = new ArrayList<>();
			ArrayList<Integer> nodes = new ArrayList<>();
			while(!pq.isEmpty() && pq.peek().val == v) al.add(pq.poll());
			for(Edge e : al) {
				int pu = Math.min(find(e.u), find(e.v)), pv = Math.max(find(e.v), find(e.u));
//				println(e.u + " " + e.v + " " + pu + " " + pv);
				if(last[pu] != v) {
					last[pu] = v;
					graph[pu] = new ArrayList<>();
					dpsz[pu] = -1;
					nodes.add(pu);
				}	
				if(last[pv] != v) {
					last[pv] = v;
					graph[pv] = new ArrayList<>();
					dpsz[pv] = -1;
					nodes.add(pv);
				}
				graph[pu].add(pv);
				graph[pv].add(pu);
			}
			for(int n : nodes) if(dpsz[n] == -1) sz(n, 0, n);
			for(Edge e : al) {
				int pu = Math.min(find(e.u), find(e.v)), pv = Math.max(find(e.v), find(e.u));
				if(dpsz[pu] == dpsz[pv]) {
					println("ERROR");
					exit();
				}
				if(dpsz[pu] < dpsz[pv]) {
					cnt[e.id] = dpsz[pu]*(dpsz[clr[pu]] - dpsz[pu]);
				}
				else {
					cnt[e.id] = dpsz[pv]*(dpsz[clr[pv]] - dpsz[pv]);
				}
			}
			for(Edge e : al) {
				int pu = Math.min(find(e.u), find(e.v)), pv = Math.max(find(e.v), find(e.u));
				par[pv] = pu;
				sz[pu] += sz[pv];
			}
		}
		LinkedList<Integer> ll = new LinkedList<>();
		long msize = 0;
		for(int i = 1; i<N; i++) {
			if(cnt[i] > msize) {
				ll.clear();
				ll.add(i);
				msize = cnt[i];
			}
			else if(cnt[i] == msize) ll.add(i);
		}
		println(2*msize + " " + ll.size());
		for(int n : ll) print(n + " ");
		exit();
	}
	
	static void sz(int n, int p, int t) {
		dpsz[n] = sz[n];
		clr[n] = t;
//		println(n);
		for(int e : graph[n]) if(e != p) {
			sz(e, n, t); 
			dpsz[n] += dpsz[e];
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