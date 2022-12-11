import java.util.*;
import java.io.*;

public class _0833_B_TheBackery {
	
	static class Node{
		int l, r, val, lazy;
		public Node(int l, int r) {
			this.l = l; this.r = r;
		}
	}
	
	static Node seg[];
	
	static void build(int l, int r, int idx, int val[]) {
		seg[idx] = new Node(l , r);
		if(l == r) {
			seg[idx].val = val[l];
			return;
		}
		int mid = (l + r)/2;
		build(l, mid, 2*idx, val); build(mid+1, r, 2*idx+1, val);
		seg[idx].val = Math.max(seg[2*idx+1].val, seg[2*idx].val);
	}
	
	static void upd(int l, int r, int val, int idx) {
		if(seg[idx].l == l && seg[idx].r == r) {
			seg[idx].val += val;
			seg[idx].lazy += val;
			return;
		}
		if(seg[idx].lazy != 0) pushdown(idx);
		int mid = (seg[idx].l + seg[idx].r)/2;
		if(r <= mid) upd(l, r, val, 2*idx); 
		else if(l > mid) upd(l, r, val, 2*idx+1);
		else {upd(l, mid, val, 2*idx); upd(mid+1, r, val, 2*idx+1);}
		seg[idx].val = Math.max(seg[2*idx].val, seg[2*idx+1].val);
	}
	
	static int query(int l, int r, int idx) {
		if(seg[idx].l == l && seg[idx].r == r) return seg[idx].val;
		int mid = (seg[idx].l + seg[idx].r)/2;
		if(seg[idx].lazy != 0) pushdown(idx);
		if(r <= mid) return query(l ,r , 2*idx);
		else if(l > mid) return query(l, r, 2*idx+1);
		else return Math.max(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
	}
	
	static void pushdown(int idx) {
		seg[2*idx].val += seg[idx].lazy;
		seg[2*idx+1].val += seg[idx].lazy;
		seg[2*idx].lazy += seg[idx].lazy;
		seg[2*idx+1].lazy += seg[idx].lazy;
		seg[idx].lazy = 0;
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt();
		boolean has[] = new boolean[N+1];
		int dp[][] = new int[K+1][N+1];
		int val[] = new int[N+1];
		for(int i =1; i<=N; i++) {
			val[i] = readInt();
			dp[1][i] = dp[1][i-1];
			if(!has[val[i]]) dp[1][i]++;
			has[val[i]] = true;
		}
		for(int k = 2; k<=K; k++) {
			seg = new Node[4*(N+1)+1];
			build(0, N, 1, dp[k-1]);
			int occ[] = new int[N+1];
//			Arrays.fill(occ, -1);
			for(int i = 1; i<=N; i++) {
				upd(occ[val[i]], i-1, 1, 1);
				occ[val[i]] = i;
				dp[k][i] = query(0, i-1, 1);
//				println(k + " " + i + " " + dp[k][i]);
			}
		}
		println(dp[K][N]);
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