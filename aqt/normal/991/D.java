import java.util.*;
import java.io.*;

public class _991_D {

	public static void main(String[] args) throws IOException {
		String one = read(), two = read(); int N = one.length(); int DP[][] = new int[N+1][4]; 
		int mask[] = new int[N+1]; for(int i = 1; i<=N; i++) mask[i] = (one.charAt(i-1) == '0' ? 0 : 2) + (two.charAt(i-1) == '0' ? 0 : 1);
		int type[][] = new int[5][2]; type[0][0] = type[0][1] = 0; type[1][0] = 2; type[1][1] = 3;
		type[2][0] = 1; type[2][1] = 3; type[3][0] = 3; type[3][1] = 1; type[4][0] = 3; type[4][1] = 2;
		boolean vis[][] = new boolean[N+1][4]; vis[1][mask[1]] = true;
		for(int i = 1; i<N; i++) for(int j = 0; j<4; j++) if(vis[i][j]) {
			for(int k = 0; k<5; k++) { 
				if((type[k][0]&j) == 0 && (type[k][1]&mask[i+1]) == 0) {
					DP[i+1][type[k][1]|mask[i+1]] = Math.max(DP[i+1][type[k][1]|mask[i+1]], DP[i][j] + (k == 0 ? 0 : 1)); 
					vis[i+1][type[k][1]|mask[i+1]] = true;
				}
			}
		}
		int max = 0; for(int i = 0; i<4; i++) max = Math.max(DP[N][i], max); println(max);
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