import java.util.*;
import java.io.*;

public class _0762_C_TwoStrings {

	public static void main(String[] args) throws IOException {
		String s = read(), t = read();
		int pre[] = new int[t.length()+1], suf[] = new int[t.length()+1];
		suf[t.length()] = t.length();
		pre[0] = -1;
		for(int i = 1, idx = 0; i<=t.length(); i++) {
			while(idx < s.length() && s.charAt(idx) != t.charAt(i-1)) idx++;
			pre[i] = idx;
			idx = Math.min(idx+1, s.length());
		}
		int bidx = -1, blen = Integer.MAX_VALUE;
		for(int i = t.length()-1, idx = s.length()-1; i>= 0; i--) {
			while(idx >= 0 && s.charAt(idx) != t.charAt(i)) idx--;
			suf[i] = idx;
			idx = Math.max(-1, idx-1);
		}
//		for(int n : pre) print(n + " ");
//		println();
//		for(int n : suf) print(n + " ");
//		println();
		for(int i = 0; i<=t.length(); i++) {
			if(pre[i] == s.length()) break;
			int l = i, r = t.length(), b = t.length();
			while(l <= r) {
				int mid = (l+r)/2;
				if(suf[mid] <= pre[i]) l = mid + 1;
				else {
					r = mid - 1;
					b = mid;
				}
			}
			if(blen > b-i && b-i >= 0) {
				blen = b-i;
				bidx = i;
			}
//			println(b + " " + (b-i));
		}
//		println(blen + " " + t.length() + " " + bidx); flush();
		if(blen == Integer.MAX_VALUE || 
				(t.substring(0, bidx) + t.substring(bidx+blen)).length() == 0) {
			println('-');
		}
		else println(t.substring(0, bidx) + t.substring(bidx+blen));
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
		byte[] ret = new byte[100005];
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