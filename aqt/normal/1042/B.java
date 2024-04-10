import java.util.*;
import java.io.*;

public class _1042_B {

	public static void main(String[] args) throws IOException {
		int N = readInt();
		int best = 1000000;
		int arr[][] = new int[2][3];
		for(int i = 0; i<2; i++) for(int j = 0; j<3; j++) arr[i][j] = 1000000;
		for(int i = 1; i<=N; i++) {
			int val = readInt();
			String cmd = read();
			if(cmd.length() == 1) {
				arr[0][cmd.charAt(0)-'A'] = Math.min(arr[0][cmd.charAt(0)-'A'], val);
			}
			else if(cmd.length() == 3) {
				best = Math.min(best, val);
			}
			else if(!cmd.contains("C")) {
				arr[1][2] = Math.min(arr[1][2], val);
			}
			else if(!cmd.contains("B")) {
				arr[1][1] = Math.min(arr[1][1], val);
			}
			else {
				arr[1][0] = Math.min(arr[1][0], val);
			}
		}
		for(int i = 0; i<3; i++) {
			best = Math.min(arr[1][i] + arr[0][i], best);
			best = Math.min(arr[1][i] + arr[1][(i+1)%3], best);
		}
		best = Math.min(best, arr[0][0] + arr[0][1] + arr[0][2]);
		println(best >= 1e6 ? -1 : best);
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
		byte[] ret = new byte[5];
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