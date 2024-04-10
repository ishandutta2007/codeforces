import java.util.*;
import java.io.*;

public class _182_D_CommonDivisors {

	public static void main(String[] args) throws IOException {
		String s = read(), t = read(); long hshs[] = new long[s.length()+1], hsht[] = new long[t.length()+1];
		long seed = 31; long pow[] = new long[200001]; pow[0] = 1; 
		for(int i = 1; i<=200000; i++) pow[i] = pow[i-1] * seed;
		for(int i = 1; i<=s.length(); i++) hshs[i] = hshs[i-1]*seed + s.charAt(i-1);
		for(int i = 1; i<=t.length(); i++) hsht[i] = hsht[i-1]*seed + t.charAt(i-1);
		int lim = gcd(s.length(), t.length()), cnt = 0; //println(lim);
		for(int i = 1; i<=lim; i++) if(lim%i == 0) {
			boolean chk = true;
			for(int j = i; j<=s.length() && chk; j+=i) if(hshs[i] != hshs[j] - hshs[j-i] * pow[i]) chk = false;
			for(int j = i; j<=t.length() && chk; j+=i) if(hshs[i] != hsht[j] - hsht[j-i] * pow[i]) chk = false;
			if(chk) cnt++;
		}
		println(cnt);
		exit();
	}
	
	public static int gcd(int a, int b) {
		return a*b == 0 ? a+b : gcd(b, a%b);
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
		byte[] ret = new byte[1000001];
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

	public void close() throws IOException {
		if (din == null)
			return;
		din.close();
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