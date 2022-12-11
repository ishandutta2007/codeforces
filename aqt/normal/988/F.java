import java.util.*;
import java.io.*;

public class _988_F_RainAndUmbrellas {

	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt(), M = readInt(); boolean rain[] = new boolean[N+1];
		for(int i = 1; i<=K; i++) {int a = readInt()+1, b = readInt(); for(; a<=b; a++) rain[a] = true;}
		int ubra[] = new int[N+1]; Arrays.fill(ubra, Integer.MAX_VALUE);
		for(int i = 1; i<=M; i++) {int idx = readInt(); ubra[idx] = Math.min(ubra[idx], readInt());}
		int DP[][] = new int[N+1][N+1]; for(int i = 0; i<=N; i++) for(int j = 0; j<=N; j++) DP[i][j] = Integer.MAX_VALUE;
		DP[0][0] = 0; for(int i = 0; i<N; i++) for(int j = 0; j<N;j++) if(DP[i][j] != Integer.MAX_VALUE){
			if(j == 0) { 
				if(ubra[i] != Integer.MAX_VALUE) DP[i+1][i+1] = Math.min(ubra[i] + DP[i][j], DP[i+1][i+1]);
				if(!rain[i+1]) DP[i+1][0] = Math.min(DP[i+1][0], DP[i][j]);
			}
			else {
				if(ubra[i] != Integer.MAX_VALUE) DP[i+1][i+1] = Math.min(ubra[i] + DP[i][j], DP[i+1][i+1]);
				DP[i+1][j] = Math.min(DP[i+1][j], DP[i][j] + ubra[j-1]);
				if(!rain[i+1]) DP[i+1][0] = Math.min(DP[i+1][0], DP[i][j]);
			}
		}
		int min = Integer.MAX_VALUE; for(int i = 0; i<=N; i++) min = Math.min(DP[N][i], min); 
//		for(int i = 0; i<=N; i++) {for(int j = 0; j<=N; print(DP[i][j++] + " ")); println(); }
		println(min == Integer.MAX_VALUE ? -1 : min);
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