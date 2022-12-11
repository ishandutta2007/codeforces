import java.util.*;
import java.io.*;

public class _0919_C_SeatArrangments {

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), K = readInt(), cnt = 0; int Up[][] = new int[N+1][M+1], Down[][] = new int[N+1][M+1];
		if(K == 1) {
			for(int i = 1; i<=N; i++) {
				String s = next();
				for(int j = 1; j<=M; j++) {
					if(s.charAt(j-1) != '*') cnt++;
				}
			}
		}
		else {
			for(int i = 1; i<=N; i++) {
				String s = next();
				for(int j = 1; j<=M; j++) {
					if(s.charAt(j-1) == '*') continue;
					Up[i][j] = Up[i-1][j]+1; Down[i][j] = Down[i][j-1]+1;
					if(Up[i][j] >= K) cnt++; if(Down[i][j] >= K) cnt++;
				}
			}
		}
		println(cnt);

		exit();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static float readFloat() throws IOException {
		return Float.parseFloat(next());
	}

	static boolean readBool() throws IOException {
		return Boolean.parseBoolean(next());
	}

	static short readShort() throws IOException {
		return Short.parseShort(next());
	}

	static byte readByte() throws IOException {
		return Byte.parseByte(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException {
		return next().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}

	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

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
		br.close();
		pr.close();
		System.exit(0);
	}
}