import java.util.*;
import java.io.*;

public class _1070_C_CloudComputing {

	static class Node{
		int l, r;
		long sum, cnt;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
	}

	static Node seg[];

	static void build(int l, int r, int idx) {
		seg[idx] = new Node(l, r);
		if(l == r) {
			return;
		}
		int mid = (l+r)/2;
		build(l, mid, 2*idx);
		build(mid+1, r, 2*idx+1);
	}

	static void upd(int p, int v, int idx) {
		if(seg[idx].l == seg[idx].r) {
			seg[idx].cnt += v;
			seg[idx].sum += 1L*seg[idx].r*v;
			return;
		}
		int mid = (seg[idx].l + seg[idx].r)/2;
		if(p <= mid) {
			upd(p, v, 2*idx);
		}
		else {
			upd(p, v, 2*idx+1);
		}
		seg[idx].cnt = seg[2*idx].cnt + seg[2*idx+1].cnt;
		seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
	}

	static long query(long n, int idx) {
		if(seg[idx].l == seg[idx].r) {
			return seg[idx].r*n;
		}
		else if(seg[2*idx].cnt >= n) {
			return query(n, 2*idx);
		}
		else {
			return query(n-seg[2*idx].cnt, 2*idx+1) + seg[2*idx].sum;
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt(), M = readInt();
		ArrayList<Integer> add[] = new ArrayList[N+1], del[] = new ArrayList[N+1];
		for(int  i = 1; i<=N; i++) {
			add[i] = new ArrayList<>();
			del[i] = new ArrayList<>();
		}
		int val[] = new int[M+1], num[] = new int[M+1];
		for(int i = 1; i<=M; i++) {
			add[readInt()].add(i);
			del[readInt()].add(i);
			num[i] = readInt();
			val[i] = readInt();
		}
		seg = new Node[4000001];
		build(1, 1000000, 1);
		long sum = 0;
		for(int i = 1; i<=N; i++) {
			for(int idx : add[i]) {
				upd(val[idx], num[idx], 1);
			}
			if(seg[1].cnt >= K) {
				sum += query(K, 1);
			}
			else {
				sum += seg[1].sum;
			}
			for(int idx : del[i]) {
				upd(val[idx], -num[idx], 1);
			}
		}
		println(sum);
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