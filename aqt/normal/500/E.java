import java.util.*;
import java.io.*;

public class _0500_E_NewYearDomino {

	static class Node{
		int l, r, val; Node left, right;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
		Node copy() {
			Node x = new Node(l, r);
			x.val = val;
			x.left = left;
			x.right = right;
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
	
	static Node upd(int p, int v, Node x) {
		Node n = x.copy();
		if(n.l == p && n.r == p) {
			n.val = v;
			return n;
		}
		int mid = (n.l + n.r)/2;
		if(p <= mid) n.left = upd(p, v, n.left);
		else n.right = upd(p, v, n.right);
		n.val = n.left.val + n.right.val;
		return n;
	}
	
	static int query(int l, int r, Node n) {
		if(n.l == l && n.r == r) return n.val;
		int mid = (n.l + n.r)/2;
		if(r <= mid) return query(l, r, n.left);
		else if(l > mid) return query(l, r, n.right);
		else return query(l, mid, n.left) + query(mid+1, r, n.right);
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt();
		int h[] = new int[N+2];
		int p[] = new int[N+2];
		p[N+1] = Integer.MAX_VALUE;
		for(int i = 1; i<=N; i++) {
			p[i] = readInt();
			h[i] = readInt();
		}
		Node rt[] = new Node[N+2];
		rt[N+1] = build(1, N+1);
		int BIT[] = new int[N+2];
		for(int i = N; i>0; i--) {
			BIT[N+1] = N+1;
			int l = i, r = N+1, idx = 0;
			while(l <= r) {
				int mid = (l+r)/2;
				if(p[mid] <= p[i]+h[i]) {
					idx = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			for(int j = i; j<=N+1; j+=j&-j) {
				BIT[j] = p[BIT[j]] + h[BIT[j]] > p[i] + h[i] ? BIT[j] : i;
			}
			for(int j = idx; j>0; j-=j&-j) {
				idx = p[BIT[j]] + h[BIT[j]] > p[idx] + h[idx] ? BIT[j] : idx;
			}
			if(idx == i) {
				l = i; r = N+1; idx = 0;
				while(l <= r) {
					int mid = (l+r)/2;
					if(p[mid] <= p[i]+h[i]) {
						idx = mid;
						l = mid + 1;
					}
					else r = mid - 1;
				}
				rt[i] = upd(idx+1, p[idx+1]-p[i]-h[i], rt[idx+1]);
			}
			else rt[i] = rt[idx];
		}
		int Q = readInt(); for(int q = 0; q<Q; q++) {
			int x = readInt(), y = readInt();
			println(query(x, y, rt[x]));
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