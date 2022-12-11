import java.util.*;
import java.io.*;

public class _0786_C_TillICollapse {

	static class Node{
		int l, r, val, idx; Node left, right;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
		Node copy() {
			Node x = new Node(l, r);
			x.val = val;
			x.left = left; x.right = right;
			return x;
		}
	}
		
	static Node build(int l, int r) {
		Node n = new Node(l, r);
		if(l == r) return n;
		int mid = (l+r)/2; 
		n.left = build(l, mid);
		n.right = build(mid+1, r);
		return n;
	}
	
	static Node upd(Node x, int p, int val) {
		Node n = x.copy();
		if(n.l == p && n.r == p) {
			n.val = val;
			return n;
		}
		int mid = (n.l + n.r)/2;
		if(p <= mid) n.left = upd(x.left, p, val);
		else n.right = upd(x.right, p, val);
		n.val = n.left.val + n.right.val;
		return n;
	}
	
	static int query(Node n, int val, int sum) {
		if(n.l == n.r) return n.l;
//		println(n.left.val + " " + n.left.l + " " + n.left.r + " " + val);
		if(sum + n.left.val >= val) return query(n.left, val, sum);
		else return query(n.right, val, sum + n.left.val);
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt();
		int arr[] = new int[N+1];
		for(int i = 1; i<=N; i++) arr[i] = readInt();
		Node seg[] = new Node[N+2];
		seg[N+1] = build(1, N+1);
		int occ[] = new int[N+1]; 
		for(int i = N; i>=1; i--) {
			seg[i] = seg[i+1];
			if(occ[arr[i]] != 0) seg[i] = upd(seg[i], occ[arr[i]], 0);
			seg[i] = upd(seg[i], occ[arr[i]] = i, 1);
		}
		for(int len = 1; len<=N; len++) {
			int idx = 1, cnt = 0;
			while(idx <= N) {
				idx = query(seg[idx], len + 1, 0);
				cnt++;
			}
			print(cnt + " ");
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