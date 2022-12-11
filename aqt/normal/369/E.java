import java.util.*;
import java.io.*;

public class _0369_E_ValeraAndQueries {
	
	static class Pair implements Comparable<Pair>{
		int n, v;
		public Pair(int v, int n) {
			this.n = n; this.v = v;
		}
		public int compareTo(Pair p) {
			return Integer.compare(this.v, p.v);
		}
	}
	
	static Node crnt;
	
	static class Node{
		int l, r, val;
		Node left, right;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
		Node copy() {
			Node x = new Node(this.l, this.r);
			x.val = this.val;
			x.left = this.left;
			x.right = this.right;
			return x;
		}
	}
	
	static Node build(int l, int r) {
		Node n = new Node(l, r);
		if(l == r) return n;
		int mid = (l + r)/2;
		n.left = build(l, mid);
		n.right = build(mid+1, r);
		return n;
	}
	
	static void upd(int p, int v, Node n) {
		if(n.l == p && n.r == p) {
			n.val += v;
			return ;
		}
		int mid = (n.l + n.r)/2;
		if(p <= mid) upd(p, v, n.left);
		else upd(p, v, n.right);
		n.val = n.left.val + n.right.val;
	}
	
	static int query(int l, int r, Node n) {
		if(n.l == l && n.r == r) return n.val;
		int mid = (n.l + n.r)/2;
		if(r <= mid) return query(l, r, n.left);
		else if (l > mid) return query(l, r, n.right);
		else return query(l, mid, n.left) + query(mid+1, r, n.right);
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt();
		Pair pql[] = new Pair[N], pqr[] = new Pair[N];
		for(int i = 0; i<N; i++) {
			pql[i] = new Pair(readInt(), readInt()+1);
			pqr[i] = new Pair(pql[i].n, pql[i].v);
		}
		Arrays.sort(pql);
		Arrays.sort(pqr);
		int idxl = 0, idxr = 0;
		int tot = 0;
		int ans[] = new int[Q+1];
		Node rt = build(0, 1000000);
		ArrayList<Integer> qu[] = new ArrayList[Q+1];
		ArrayList<Pair> al[] = new ArrayList[1000001];
		for(int i = 1; i<=1000000; i++) al[i] = new ArrayList<>();
		for(int q = 1; q<=Q; q++) {
			qu[q] = new ArrayList<>();
			int n = readInt();
			qu[q].add(0);
			for(int i = 1; i<=n; i++) {
				int p = readInt();
				qu[q].add(p);
				al[p].add(new Pair(i, q));
			}
		}
		for(int i = 1; i<=1000000; i++) {
			while(idxl < N && pql[idxl].v == i) {
				upd(i, 1, rt);
				idxl++;
				tot++;
			}
			while(idxr < N && pqr[idxr].v == i) {
				upd(pqr[idxr].n, -1, rt);
				idxr++;
				tot--;
			}
			for(Pair p : al[i]) {
				ans[p.n] += tot - query(0, qu[p.n].get(p.v-1), rt);
			}
		}
		for(int i = 1; i<=Q; i++) println(ans[i]);
		exit();
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		if (c <= ' ')
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
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

	static void println() {
		pr.println();
	}

	static void exit() throws IOException {
		din.close();
		pr.close();
		System.exit(0);
	}
}