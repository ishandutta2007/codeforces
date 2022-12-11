import java.util.*;
import java.io.*;

public class _0027_C_UnorderedSubsequence {

	public static void main(String[] args) throws IOException {
		int N = readInt();
		int arr[] = new int[N+2];
		for(int i = 1; i<=N; i++) {
			arr[i] = readInt();
		}
		if(N <= 2) {
			println(0);
			exit();
		}
		if(true) {
			int inc[] = new int[N+1], dec[] = new int[N+1];
			int min = 0;
			arr[0] = Integer.MAX_VALUE;
			for(int i = 1; i<=N; i++) {
				if(arr[i] > arr[min]) {
					inc[i] = min;
				}
				min = arr[i] < arr[min] ? i : min;
			}
			int max = N+1;
			arr[N+1] = Integer.MAX_VALUE;
			for(int i = N; i>=1; i--) {
				if(arr[i] > arr[max]) {
					dec[i] = max;
				}
				max = arr[i] < arr[max] ? i : max;
			}
			for(int i = 1; i<=N; i++) {
				if(inc[i] != 0 && dec[i] != 0) {
					println(3);
					println(inc[i] + " " + i + " " + dec[i]);
					exit();
				}
			}
		}
		int inc[] = new int[N+1], dec[] = new int[N+1];
		int min = N+1;
		arr[N+1] = Integer.MIN_VALUE;
		for(int i = 1; i<=N; i++) {
			if(arr[i] < arr[min]) {
				inc[i] = min;
			}
			min = arr[i] > arr[min] ? i : min;
		}
		int max = 0;
		arr[0] = Integer.MIN_VALUE;
		for(int i = N; i>=1; i--) {
			if(arr[i] < arr[max]) {
				dec[i] = max;
			}
			max = arr[i] > arr[max] ? i : max;
		}
		for(int i = 1; i<=N; i++) {
			if(inc[i] != 0 && dec[i] != 0) {
				println(3);
				println(inc[i] + " " + i + " " + dec[i]);
				exit();
			}
		}
		println(0);
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