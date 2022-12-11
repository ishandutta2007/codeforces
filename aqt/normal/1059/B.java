import java.util.*;
import java.io.*;

public class _1059_B {

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt();
		char tbl[][] = new char[N+4][M+4];
		boolean tkn[][] = new boolean[N+4][M+4];
		for(int i = 2; i<N+2; i++) {
			String s = read();
			for(int j = 0; j<M; j++) {
				tbl[i][j+2] = s.charAt(j);
			}
		}
		for(int i= 0 ; i<N+2; i++) {
			for(int j = 0; j<M+2; j++) {
				boolean b = true;
				for(int i1 = 0; i1<3; i1++) {
					for(int j1 = 0; j1<3; j1++) {
						if(i1 != 1 || j1 != 1) {
							if(tbl[i+i1][j+j1] != '#') {
								b = false;
							}
						}
					}
				}
				if(b) {
					for(int i1 = 0; i1<3; i1++) {
						for(int j1 = 0; j1<3; j1++) {
							if(i1 != 1 || j1 != 1) {
								tkn[i+i1][j+j1] = true;
							}
						}
					}
				}
			}
		}
		for(int i= 0; i<N+4; i++) {
			for(int j= 0; j<M+4; j++) {
				if(tbl[i][j] == '#' && !tkn[i][j]) {
					println("NO");
					exit();
				}
			}
		}
		println("YES");
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