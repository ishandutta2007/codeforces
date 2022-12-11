import java.util.*;
import java.io.*;

public class _888_E_MaximumSubsequence {

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), mid = N/2; int a1[] = new int[mid], a2[] = new int[N-mid];
		for(int i = 0; i<mid; i++) a1[i] = readInt(); for(int i = mid; i<N; i++) a2[i-mid] = readInt(); 
		Integer arr1[] = new Integer[1<<mid], arr2[] = new Integer[1<<(N-mid)]; Arrays.fill(arr1, 0); Arrays.fill(arr2, 0);
		for(int i = 0; i<(1<<mid); i++) for(int j = 0; j<mid; j++) if(((1<<j)&i) != 0) arr1[i] = (arr1[i] + a1[j])%M;
		for(int i = 0; i<(1<<(N-mid)); i++) for(int j = 0; j<N-mid; j++) if(((1<<j)&i) != 0) arr2[i] = (arr2[i] + a2[j])%M;
		Arrays.sort(arr1); Arrays.sort(arr2); int max = 0; 
		for(int i = 0, j = (1<<(N-mid))-1; i<(1<<mid); i++) {
			while(arr1[i] + arr2[j] >= M) j--; max = (int) Math.max(max, arr1[i] + arr2[j]);
		}
		println(max);
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