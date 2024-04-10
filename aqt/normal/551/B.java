import java.util.*;
import java.io.*;

public class _0551_B_ZgukistringZ {

	public static void main(String[] args) throws IOException {
		String s = read(), a = read(), b = read(); int cs[] = new int[26], ca[] = new int[26], cb[] = new int[26];
		f(s, cs); f(a, ca); f(b, cb); int bestidx = 0, bestval = 0; boolean bool = true;for(int i = 0; bool; i++) {
			int cnt = Integer.MAX_VALUE; for(int j = 0; j<26 && bool; j++) if(cs[j] < ca[j]*i) bool = false; 
			else if(cb[j] != 0) cnt = Math.min(cnt, (cs[j]-ca[j]*i)/cb[j]);
			if(bool && bestval < cnt + i) {bestval = cnt + i; bestidx = i;}
		}
		char ans[] = new char[s.length()]; int idx = 0;
		for(int i = 0; i<bestidx; i++) for(int j = 0; j<a.length(); j++) ans[idx++] = a.charAt(j);
		for(int i = bestidx; i<bestval; i++) for(int j = 0; j<b.length(); j++) ans[idx++] = b.charAt(j);
		for(int i = 0; i<26; i++) {
			cs[i] -= ca[i]*bestidx + cb[i]*(bestval-bestidx);
			for(int j = 0; j<cs[i]; j++) ans[idx++] = (char) (i + 'a');
		}
		for(int i = 0; i<idx; i++) print(ans[i]); exit();
	}
	
	public static void f(String s, int c[]) {
		for(int i = 0; i<s.length(); i++) c[s.charAt(i)-'a']++;
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
		byte[] ret = new byte[100001];
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