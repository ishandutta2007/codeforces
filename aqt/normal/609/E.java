import java.util.*;
import java.io.*;

public class _609_E_MinimumSpanningTreeForEachEdge {

	public static class Edge implements Comparable<Edge>{
		int u, v, val, idx;
		public Edge(int u, int v, int val, int idx) {
			this.u = u; this.v = v; this.val = val; this.idx = idx;
		}
		public int compareTo(Edge e) {
			return Integer.compare(this.val, e.val);
		}
	}
	
	static int par[], dep[], top[], id[], hvy[], sz[], val[], time = 0;
	static ArrayList<Edge> graph[];
	
	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(); graph = new ArrayList[N+1]; Edge list[] = new Edge[M];
		for(int i = 1; i<=N; i++) graph[i] = new ArrayList<Edge>();
		for(int i = 0; i<M; i++) list[i] = new Edge(readInt(), readInt(), readInt(), i);
		boolean tkn[] = new boolean[M]; PriorityQueue<Edge> pq = new PriorityQueue<Edge>(); for(Edge e: list) pq.add(e);
		par = new int[N+1]; for(int i = 1; i<=N; i++) par[i] = i; long totwt = 0; while(!pq.isEmpty()) {
			Edge e = pq.poll(); if(find(e.u) == find(e.v)) continue;	
			totwt += e.val; par[find(e.u)] = find(e.v); tkn[e.idx] = true;
			graph[e.u].add(new Edge(e.u, e.v, e.val, 0)); graph[e.v].add(new Edge(e.v, e.u, e.val, 0));
		}	
		par = new int[N+1]; dep = new int[N+1]; hvy = new int[N+1]; sz = new int[N+1]; val = new int[N+1]; dfs(1);
		seg = new Node[4*N+1]; build(1, N, 1); top = new int[N+1]; id = new int[N+1]; hld(1,1); 
		for(int i = 0; i<M; i++) println(totwt - max(list[i].u, list[i].v) + list[i].val);
		exit();
	}
	
	public static void dfs(int n) {
		sz[n] = 1; for(Edge e : graph[n]) if(e.v != par[n]) {
			par[e.v] = n; dep[e.v] = dep[n] + 1; val[e.v] = e.val; dfs(e.v); sz[n] += sz[e.v];
			hvy[n] = sz[e.v] > sz[hvy[n]] ? e.v : hvy[n];
		}
 	}
	
	public static void hld(int n, int t) {
		id[n] = ++time; top[n] = t; upd(id[n], val[n], 1);
		if(hvy[n] != 0) hld(hvy[n], t); 
		for(Edge e : graph[n]) if(e.v != par[n] && e.v != hvy[n]) hld(e.v, e.v);
	}
	
	public static int max(int u, int v) {
		int max = Integer.MIN_VALUE; while(top[u] != top[v]) {
			if(dep[top[u]] < dep[top[v]]) {int temp = u; u = v; v = temp;}
			max = Math.max(max(id[top[u]], id[u], 1), max); u = par[top[u]];
		}
		if(dep[u] < dep[v]) {int temp = u; u = v; v = temp;}
		if(u != v) max = Math.max(max(id[v] + 1, id[u], 1), max); return max;
	}
	
	public static class Node{
		int l, r, val;
		public Node(int l, int r) {
			this.l = l; this.r = r; 
		}
	}
	
	static Node seg[];
	
	public static void build(int l, int r, int idx) {
		seg[idx] = new Node(l, r); if(l == r) return;
		int mid = (l+r)/2; build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
	}
	
	public static int max(int l,int r, int idx) {
		if(seg[idx].l == l && seg[idx].r == r) return seg[idx].val;
		int mid = (seg[idx].l + seg[idx].r)/2;
		if(r <= mid) return max(l, r, 2*idx); else if(l > mid) return max(l,r,2*idx+1);
		else return Math.max(max(l, mid, 2*idx), max(mid+1,r,2*idx+1));
	}
	
	public static void upd(int p, int v, int idx) {
		if(seg[idx].l == p && seg[idx].r == p) {seg[idx].val = v; return;}
		int mid = (seg[idx].l + seg[idx].r)/2; if(p <= mid) upd(p, v, 2*idx); else upd(p, v, 2*idx+1);
		seg[idx].val = Math.max(seg[2*idx].val, seg[2*idx+1].val);
	}
	
	public static int find(int n) {return par[n] = par[n] ==n ? n : find(par[n]);}

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