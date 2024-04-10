import java.util.*;
import java.io.*;

public class _0461_C_ApplemanAndASheetOfPaper {

	static class Node{
		int l, r, val;
		public Node(int l, int r) {
			this.l = l; this.r =r;
		}
	}

	static Node seg[];

	static int build(int l, int r, int idx) {
		seg[idx] = new Node(l, r);
		if(l == r) {
			seg[idx].val = 1;
			return 1;
		}
		int mid = (l+r)/2;
		return seg[idx].val = build(l, mid, 2*idx) + build(mid+1, r, 2*idx+1);
	}

	static void upd(int p, int v, int idx) {
//		println(p + " " + v + " " + idx); flush();
		if(seg[idx].l == p && seg[idx].r == p) {
			seg[idx].val += v;
			return;
		}
		int mid = (seg[idx].l + seg[idx].r)/2;
		if(p <= mid) upd(p, v, 2*idx);
		else upd(p, v, 2*idx+1);
		seg[idx].val = seg[2*idx].val + seg[2*idx+1].val;
	}

	static int query(int l, int r, int idx) {
//		println(" " + l + " " + r); flush();
		if(seg[idx].l == l && seg[idx].r ==r) {
			return seg[idx].val;
		}
		int mid = (seg[idx].l + seg[idx].r)/2;
		if(r <= mid) return query(l, r, 2*idx);
		else if(l > mid) return query(l, r, 2*idx+1);
		else return query(l, mid, 2*idx) + query(mid+1, r, 2*idx+1);
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt();
		seg = new Node[4*N+1];
		build(1, N, 1);
		int L = 0, R = N;
		boolean flip = false;
		while(Q-- > 0) {
//			println(L + " " + R + " LR");
//			flush();
			if(readInt() == 1) {
				int p = readInt();
				if(R-L-p < p) {
					int temp = p;
					p = R-L-p;
					if(!flip) {
						for(int i = 1; i<=p; i++) {
							upd(R-p-i+1, query(R-p+i, R-p+i, 1), 1);
//							println(" " + (R-p+i) + "\n");
//							flush();
						}
						R = L+temp;
					}
					else {
						for(int i = 1; i<=p; i++) {
							upd(p+L+i, query(p+L-i+1, p+L-i+1, 1), 1);
//							println("  " + (p+L-i+1) + "\n");
//							flush();
						}
						L = R-temp;
					}
					flip = !flip;
				}
				else {
					if(!flip) {
						for(int i = 1; i<=p; i++) {
							upd(p+L+i, query(p+L-i+1, p+L-i+1, 1), 1);
//							println((p+L-i+1) + "\n");
//							flush();
						}
						L = L+p;
					}
					else {
						for(int i = 1; i<=p; i++) {
							upd(R-p-i+1, query(R-p+i, R-p+i, 1), 1);
//							println("   " + (R-p+i) + "\n");
//							flush();
						}
						R = R-p;
					}
				}
			}
			else {
				int l = readInt(), r = readInt();
				if(flip) {
					println(query(R-r+1, R-l, 1));
				}
				else {
					println(query(L+l+1, L+r, 1));
				}
			}
//			println("END");
//			flush();
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