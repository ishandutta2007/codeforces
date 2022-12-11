import java.util.*;
import java.io.*;

public class _989_C_AMistOfFlorescence {

	public static void main(String[] args) throws IOException {
		int A = readInt()-1, B = readInt()-1, C = readInt()-1, D = readInt()-1;
		char arr[][] = new char[51][51]; println(50 + " " + 50);
		for(int i = 1; i<=50; i++) for(int j = 1; j<=50; j++) {
			if(i <= 25 && j <= 25) arr[i][j] = 'A';
			if(i > 25 && j <= 25) arr[i][j] = 'B';
			if(i > 25 && j > 25) arr[i][j] = 'C';
			if(i <= 25 && j > 25) arr[i][j] = 'D';
		}
		for(int i = 1; i<=23 && C > 0; i+=2) for(int j = 1; j<=23 && C > 0; j+=2) {arr[i][j] = 'C'; C--;}
		for(int i = 27; i<=50 && A > 0; i+=2) for(int j = 27; j<=50 && A > 0; j+=2) {arr[i][j] = 'A'; A--;}
		for(int i = 27; i<=50 && D > 0; i+=2) for(int j = 1; j<=23 && D > 0; j+=2) {arr[i][j] = 'D'; D--;}
		for(int i = 1; i<=23 && B > 0; i+=2) for(int j = 27; j<=50 && B > 0; j+=2) {arr[i][j] = 'B'; B--;}
		for(int i = 1; i<=50; i++) {for(int j = 1; j<=50; j++) print(arr[i][j]); println();}
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