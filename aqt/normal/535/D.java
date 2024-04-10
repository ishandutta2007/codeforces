import java.util.*;
import java.io.*;

public class _535_D_TavasAndMalekas {

	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt(); String s = read(); long mod = (long) (1e9+7), seed = 31;
		char sent[] = new char[N+1]; int st[] = new int[K+1]; int next = 0; Arrays.fill(sent, '?');
		long hashval = 0; for(int i = 0; i<s.length(); i++) hashval = hashval*seed + s.charAt(i);
		for(int i = 1; i<=K; i++) {
			st[i] = readInt(); int index = Math.max(0, next - st[i]); next = st[i] + s.length()-1;
			for(int j = index; j<s.length(); j++) sent[st[i] + j] = s.charAt(j); 
		}
		long pow[] = new long[N+1]; pow[0] = 1; for(int i = 1; i<=N; i++) pow[i] = pow[i-1] * seed;
		long hsh[] = new long[N+1]; for(int i = 1; i<=N; i++) hsh[i] = hsh[i-1]*seed + sent[i];
		for(int i = 1; i<=K; i++) {
			if(hsh[st[i] + s.length() - 1] - hsh[st[i] - 1] * pow[s.length()] != hashval) {println(0); exit();}
		}
		long ans = 1; 
		for(int i = 1; i<=N; i++) {
			if(sent[i] == '?') ans = (ans*26)%mod;
		}
		println(ans);
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
		byte[] ret = new byte[1000005];
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