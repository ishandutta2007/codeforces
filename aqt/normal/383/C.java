import java.util.*;
import java.io.*;

public class _383_C_PropagatingTree {

	static int N, time = 0, s[], e[], order[], org[], dist[];
	static ArrayList<Integer> graph[] = new ArrayList[N+1];
	
	
	
	public static class SegmentTree{
		Node seg[];
		
		public class Node{
			int l, r, val, lazy;
			public Node(int l, int r) {
				this.l = l; this.r = r;
			}
		}
		
		public SegmentTree(int sz) {
			seg = new Node[sz];
			build(1, sz/4, 1);
		}
		
		void build(int l, int r, int idx) {
			seg[idx] = new Node(l, r); if(l == r) {seg[idx].val = org[order[l]]; return;}
			int mid = (l+r)/2; build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
			seg[idx].val = seg[2*idx].val + seg[2*idx+1].val;
		}
		
		void upd(int l, int r, int val, int idx) {
			if(seg[idx].l == l && seg[idx].r == r) {seg[idx].val += val; seg[idx].lazy += val; return;}
			int mid = (seg[idx].l + seg[idx].r)/2; 
			if(r <= mid) upd(l, r, val, 2*idx); else if(l > mid) upd(l, r, val, 2*idx+1);
			else {upd(l, mid, val, 2*idx); upd(mid+1, r, val, 2*idx+1);}
			seg[idx].val = seg[2*idx].val + seg[2*idx+1].val;
		}
		
		void pushdown(int idx) {
			seg[2*idx].val += seg[idx].lazy; seg[2*idx+1].val += seg[idx].lazy;
			seg[2*idx].lazy += seg[idx].lazy; seg[2*idx+1].lazy += seg[idx].lazy;
			seg[idx].lazy = 0;
		}
		
		int query(int pos, int idx) {
			if(seg[idx].l == pos && seg[idx].r == pos) return seg[idx].val;
			int mid = (seg[idx].l + seg[idx].r)/2; pushdown(idx);
			if(pos <= mid) return query(pos, 2*idx); else return query(pos, 2*idx+1);
		}
	}
	
	public static void main(String[] args) throws IOException {
		N = readInt(); int Q = readInt(); org = new int[N+1]; for(int i = 1; i<=N; i++) org[i] = readInt();
		graph = new ArrayList[N+1]; for(int i = 1; i<=N; i++) graph[i] = new ArrayList<Integer>();
		for(int i = 1; i<N; i++) {int a = readInt(), b = readInt(); graph[a].add(b); graph[b].add(a);}
		s = new int[N+1]; e = new int[N+1]; order = new int[2*N+1]; dist = new int[N+1]; dfs(1, 0);
		SegmentTree seg1 = new SegmentTree(8*N); SegmentTree seg2 = new SegmentTree(8*N);
		for(int q = 0; q<Q; q++) {
			if(readInt() == 1) {
				int n = readInt(), v = readInt();
				if(dist[n]%2 == 0) {seg2.upd(s[n], e[n], v, 1); seg1.upd(s[n], e[n], -v, 1);}
				else {seg2.upd(s[n], e[n], -v, 1); seg1.upd(s[n], e[n], v, 1);}
			}
			else {int n = readInt(); 
				if(dist[n]%2 == 1) println(seg1.query(s[n], 1)); else println(seg2.query(s[n], 1));
			}
		}
		exit();
	}
	
	public static void dfs(int n, int p) {
//		System.out.println(n + " " + p);
		s[n] = ++time; order[time] = n;
		for(int e : graph[n]) if(e!=p) {dist[e] = dist[n] + 1; dfs(e, n); } 
		e[n] = ++time; order[time] = n;
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