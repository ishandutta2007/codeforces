import java.util.*;
import java.io.*;

public class _0762_B_USBVSPS2 {

	static class Pair implements Comparable<Pair>{
		boolean usb;
		int val;
		public Pair(int v, boolean b) {
			this.usb = b; this.val = v;
		}
		public int compareTo(Pair p) {
			return Integer.compare(this.val, p.val);
		}
	}
	
	public static void main(String[] args) throws IOException {
		int A = readInt(), B = readInt(), C = readInt();
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		int Q = readInt();
		long tot = 0; int cnt = 0;
		for(int q = 0; q<Q; q++) pq.add(new Pair(readInt(), read().equals("USB")));
		while(!pq.isEmpty()) {
			cnt++;
			if(pq.peek().usb) {
				if(A > 0) {
					A--;
					tot += pq.poll().val;
				}
				else if(C > 0) {
					C--;
					tot += pq.poll().val;
				}
				else {
					pq.poll();
					cnt--;
				}
			}
			else {
				if(B > 0) {
					B--;
					tot += pq.poll().val;
				}
				else if(C > 0) {
					C--;
					tot += pq.poll().val;
				}
				else {
					pq.poll();
					cnt--;
				}
			}
		}
		println(cnt + " " + tot);
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