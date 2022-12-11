import java.util.*;
import java.io.*;

public class _276_E_LittleGirlAndProblemOnTrees {

	public static class Node{
		int l, r, val, lazy; Node left, right;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
	}

	public static Node build(int l, int r) {
		Node n = new Node(l, r); if(l == r) return n;
		int mid = (l+r)/2; n.left = build(l, mid); n.right = build(mid+1, r); return n;
	}

	public static void upd(Node n, int l, int r, int val) {
		if(n.l == l && n.r == r) {n.lazy += val; n.val += val; return;}
		int mid = (n.l + n.r)/2; pushdown(n);
		if(r <= mid) upd(n.left, l, r, val); else if(l > mid) upd(n.right, l, r, val);
		else {upd(n.left, l, mid, val); upd(n.right, mid+1, r, val);}
		n.val += n.left.val + n.right.val;
	}

	public static int query(Node n, int pos) {
//		System.out.println(n.l + " " + n.r);
		if(n.l == pos && n.r == pos) return n.val;
		int mid = (n.l + n.r)/2; pushdown(n);
		if(pos <= mid) return query(n.left, pos); else return query(n.right, pos);
	}

	public static void pushdown(Node n) {
		n.left.val += n.lazy; n.right.val += n.lazy;
		n.left.lazy += n.lazy; n.right.lazy += n.lazy;
		n.lazy = 0;
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt(); ArrayList<Integer> graph[] = new ArrayList[N+1];
		for(int i = 1; i<=N; i++) graph[i] = new ArrayList<Integer>();
		for(int i= 1; i<N; i++) {
			int a = readInt(), b = readInt();
			graph[a].add(b); graph[b].add(a);
		}
		int dist[] = new int[N+1], treenum[] = new int[N+1]; Arrays.fill(dist, -1); dist[1] = 0; 
		LinkedList<Integer> ll = new LinkedList<Integer>(); int cnt = 0;
		for(int e : graph[1]) {
			treenum[e] = ++cnt; dist[e] = 1; ll.add(e);
		}
		int deepest[] = new int[cnt+1]; Arrays.fill(deepest, 1);
		while(!ll.isEmpty()) {
			int n = ll.pop(); for(int e : graph[n]) if(dist[e] == -1){
				dist[e] = dist[n] + 1; ll.add(e); treenum[e] = treenum[n]; deepest[treenum[n]] = dist[e];
			}
		}
		Node paths[] = new Node[cnt+1]; int maxdep = 0;for(int i =1; i<=cnt; i++) {
			paths[i] = build(1, deepest[i]); 
			maxdep = Math.max(maxdep, deepest[i]);
//			println(deepest[i]);	
		}
		Node dis = build(0, maxdep);
		for(int q  = 0; q<Q; q++) {
			if(readInt() == 0) {
				int n = readInt(), val = readInt(), d = readInt(); 
				if(n == 1) {
					upd(dis, 0, Math.min(maxdep, d), val);
				}
				else {
					upd(paths[treenum[n]], Math.max(dist[n] - d, 1), Math.min(dist[n] + d, deepest[treenum[n]]), val);
					if(dist[n] - d <= 0) {
						upd(dis, 0, Math.min(d - dist[n], maxdep), val);
						if(dist[n] - d < 0) 
							upd(paths[treenum[n]], 1, Math.min(d - dist[n], deepest[treenum[n]]), -val);
					}
				}
			}
			else {
				int n = readInt(); if(n == 1) println(query(dis, 0));
				else {
//					println(query(paths[treenum[n]], dist[n]) + " L");
					println(query(paths[treenum[n]], dist[n]) + query(dis, dist[n]));
				}
			}
		}
		exit();
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