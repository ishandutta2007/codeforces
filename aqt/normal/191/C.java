import java.util.*;
import java.io.*;

public class _191_C_FoolsAndRoads {

	static ArrayList<Integer> graph[]; static int id[], dep[], par[], top[], hvy[], sz[], time = 0;
	
	public static class Node{
		int l, r, val, lazy;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
	}
	
	static Node seg[];
	
	static void build(int l, int r, int idx) {
		seg[idx] = new Node(l, r); if(l == r) return;
		int mid = (l + r) / 2; build(l , mid, 2*idx); build(mid+1, r, 2*idx+1);
	}
	
	static void upd(int l, int r, int val, int idx) {
		if(seg[idx].l == l && seg[idx].r == r) {seg[idx].val += val; seg[idx].lazy += val; return;}
		int mid = (seg[idx].l + seg[idx].r)/2; pushdown(idx);
		if(r <= mid) upd(l, r, val, 2*idx); else if(l > mid) upd(l, r, val, 2*idx+1);
		else {upd(l, mid, val, 2*idx); upd(mid+1, r, val, 2*idx+1);}
	}
	
	static void pushdown(int idx) {
		seg[2*idx].val += seg[idx].lazy; seg[2*idx+1].val += seg[idx].lazy;
		seg[2*idx].lazy += seg[idx].lazy; seg[2*idx+1].lazy += seg[idx].lazy;
		seg[idx].lazy  = 0;
	}
	
	static int query(int pos, int idx) {
		if(seg[idx].l == pos && seg[idx].r == pos) return seg[idx].val;
		int mid = (seg[idx].l + seg[idx].r)/2; pushdown(idx);
		if(pos <= mid) return query(pos, 2*idx); else return query(pos, 2*idx+1); 
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt(); graph = new ArrayList[N+1]; int a[] = new int[N+1], b[] = new int[N+1];
		for(int i = 1; i<=N; i++) graph[i] = new ArrayList<Integer>();
		for(int i = 1; i<N; i++) {a[i] = readInt(); b[i] = readInt(); graph[a[i]].add(b[i]); graph[b[i]].add(a[i]);}
		dep = new int[N+1]; par = new int[N+1]; hvy = new int[N+1]; sz = new int[N+1]; dfs(1);
		top = new int[N+1]; id = new int[N+1]; hld(1,1); seg = new Node[4*N+1]; build(1, N, 1);
		int Q = readInt(); for(int q = 0; q<Q; q++) upd(readInt(), readInt());
		for(int i = 1; i<N; i++) if(dep[a[i]] > dep[b[i]]) print(query(id[a[i]], 1) + " "); else print(query(id[b[i]], 1) + " ");
		exit();
	}
	
	public static void dfs(int n){
		sz[n] = 1; for(int e : graph[n]) if(e != par[n]) {
			dep[e] = dep[n] + 1; par[e] = n; dfs(e); sz[n] += sz[e];
			hvy[n] = sz[hvy[n]] > sz[e] ? hvy[n] : e;
		}
	}
	
	public static void hld(int n, int t) {
		id[n] = ++time; top[n] = t;
		if(hvy[n] != 0) hld(hvy[n], t);
		for(int e : graph[n]) if(e != par[n] && e != hvy[n]) hld(e, e);
	}
	
	public static void upd(int u, int v) {
		while(top[u] != top[v]) {
			if(dep[top[u]] < dep[top[v]]) {int temp = u; u = v; v = temp;}
			upd(id[top[u]], id[u], 1, 1); u = par[top[u]];
		}
		if(dep[u] < dep[v]) {int temp = u; u = v; v = temp;}
		if(u != v) upd(id[v] + 1, id[u], 1, 1);
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