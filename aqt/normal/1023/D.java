import java.util.*;


import java.io.*;

public class _1023_D {

	public static class Node{
		int l, r, val;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
	}

	public static int min(int start, int end, int idx) {
		if(seg[idx].r == end && seg[idx].l == start) return seg[idx].val;
		int mid = (seg[idx].r + seg[idx].l)/2;
		if(end <= mid) return min(start, end, 2*idx);
		else if(start > mid) return min(start, end, 2*idx+1);
		else return Math.min(min(start, mid, 2*idx), min(mid+1, end, 2*idx+1));
	}

	public static void update(int pos, int val, int idx) {
		if(seg[idx].l == pos && seg[idx].r == pos) {
			seg[idx].val = val;
			return;
		}
		int mid = (seg[idx].l + seg[idx].r)/2;
		if(pos <= mid) update(pos, val, 2*idx);
		else update(pos, val, 2*idx+1);
		seg[idx].val = Math.min(seg[2*idx].val, seg[2*idx+1].val);
	}

	static Node seg[];
	public static void build(int l, int r, int idx) {
		seg[idx] = new Node(l, r);
		if(l == r) {
			return;
		}
		int mid = (l + r)/2;
		build(l, mid, 2*idx);
		build(mid + 1, r, 2*idx+1);
		seg[idx].val = Math.min(seg[2*idx].val, seg[2*idx+1].val);
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt();
		int arr[] = new int[N+1]; arr[0] = 1;
		int first[] = new int[Q+1]; Arrays.fill(first, Integer.MAX_VALUE);
		int zeroidx = 0;
		int max = 0;
		seg = new Node[4*N+1]; build(1, N, 1);
		for(int i =1 ; i<=N; i++) {
			max = Math.max(arr[i] = readInt(), max);
			if(arr[i] == 0) {
				arr[i] = arr[i-1];
				zeroidx = i;
			}
			update(i, arr[i], 1);
			first[arr[i]] = Math.min(i, first[arr[i]]);
			if(min(first[arr[i]], i, 1) < arr[i]) {
				println("NO");
				exit();
			}
		}
		if(max < Q && zeroidx != 0) {
			arr[zeroidx] = Q;
		}
		else if(max < Q) {
			println("NO");
			exit();
		}

		println("YES");
		for(int i = 1; i<=N; i++) print(arr[i] + " ");

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