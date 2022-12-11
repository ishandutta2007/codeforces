import java.util.*;
import java.io.*;

public class _0803_E_RomaAndPoker {

	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt();
		boolean dp[][] = new boolean[N+1][2*K+1];
		char b[][] = new char[N+1][2*K+1];
		dp[0][K] = true;
		String s = read();
		for(int i = 0; i<N; i++) {
			for(int j = 1; j<2*K; j++) {
				if(dp[i][j]) {
					if(s.charAt(i) == 'W') {
						dp[i+1][j+1] = true;
						b[i+1][j+1] = 'W';
					}
					else if(s.charAt(i) == 'D') {
						dp[i+1][j] = true;
						b[i+1][j] = 'D';
					}
					else if(s.charAt(i) == 'L') {
						dp[i+1][j-1] = true;
						b[i+1][j-1] = 'L';
					}
					else {
						dp[i+1][j+1] = true;
						b[i+1][j+1] = 'W';
						dp[i+1][j] = true;
						b[i+1][j] = 'D';
						dp[i+1][j-1] = true;
						b[i+1][j-1] = 'L';
					}
				}
			}
		}
		char ans[] = new char[N+1];
		if(dp[N][0]) {
			int crnt = 0;
			for(int i = N; i>0; i--) {
				ans[i] = b[i][crnt];
				if(ans[i] == 'W') crnt--;
				if(ans[i] == 'L') crnt++;
			}
		}
		else if(dp[N][2*K]) {
			int crnt = 2*K;
			for(int i = N; i>0; i--) {
				ans[i] = b[i][crnt];
				if(ans[i] == 'W') crnt--;
				if(ans[i] == 'L') crnt++;
			}
		}
		else {
			println("NO");
			exit();
		}
		for(int i = 1; i<=N; i++) print(ans[i]);
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