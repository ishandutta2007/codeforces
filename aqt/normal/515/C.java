import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class _0515_C_DrazilAndFactorial {

	public static void main(String[] args) throws IOException {
		int K= readInt(); long N = readLong();
		long fact[] = new long[10];fact[0] = 1;
		for(int i = 1; i<10; i++) fact[i] = fact[i-1] * i;
		BigInteger find = BigInteger.ONE;
		while(N>0) {find = find.multiply(BigInteger.valueOf(fact[(int)(N%10)])); N /= 10;}
		LinkedList<Integer> ll = new LinkedList<>();
		while(find.mod(BigInteger.valueOf(fact[7])).equals(BigInteger.ZERO)) {
			ll.add(7);
			find = find.divide(BigInteger.valueOf(fact[7]));
		}
		while(find.mod(BigInteger.valueOf(fact[5])).equals(BigInteger.ZERO)) {
			ll.add(5);
			find = find.divide(BigInteger.valueOf(fact[5]));
		}
		while(find.mod(BigInteger.valueOf(fact[3])).equals(BigInteger.ZERO)) {
			ll.add(3);
			find = find.divide(BigInteger.valueOf(fact[3]));
		}
		while(find.mod(BigInteger.valueOf(fact[2])).equals(BigInteger.ZERO)) {
			ll.add(2);
			find = find.divide(BigInteger.valueOf(fact[2]));
		}
		for(int n : ll) print(n);
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