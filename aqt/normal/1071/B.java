import java.util.*;
import java.io.*;

public class _1071_B {

	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt();
		int dp1[][] = new int[N+1][N+1], dp2[][] = new int[N+2][N+2];
		char map[][] = new char[N+1][N+1];
		for(int i = 1; i<=N; i++) {
			String s = read();
			for(int j= 1; j<=N; j++) {
				map[i][j] = s.charAt(j-1);
			}
		}
		for(int i = 0; i<=N; i++) {
			for(int j = 0; j<=N; j++) {
				dp1[i][j] = 1000000;
			}
		}
		for(int i = 0; i<=N+1; i++) {
			for(int j = 0; j<=N+1; j++) {
				dp2[i][j] = 1000000;
			}
		}
		if(K == 0) {
			dp2[N][N] = 1;
			for(int i = 2*N-1; i>=2; i--) {
				Long arr[] = new Long[Math.min(i, N+1)-Math.max(1, i-N)];
				int idx = 0;
				for(int j = Math.max(1, i-N); j<Math.min(i, N+1); j++) {
					arr[idx++] = (map[i-j][j]-'a')*1000000000000L
							+Math.min(dp2[i-j+1][j], dp2[i-j][j+1])*1000000L
							+j;
				}
				Arrays.sort(arr);
				for(int j = 0; j<Math.min(i, N+1)-Math.max(1, i-N); j++) {	
					int pos = (int)(arr[j]%1000000);
					dp2[i-pos][pos] = j+1;
				}
			}
			int pos = 1;
			print(map[1][1]);
			for(int i = 2; i<2*N; i++) {
				if(dp2[i-pos+1][pos] < dp2[i-pos][pos+1]) {
					print(map[i-pos+1][pos]);
				}
				else {
					print(map[i-pos][pos+1]);
					pos++;
				}
			}
			exit();
		}
		if(map[1][1] != 'a') dp1[1][1] = 1;
		else dp1[1][1] = 0;
		int max = 2;
		for(int i = 3; i<=2*N; i++) {
			for(int j = Math.max(1, i-N); j<Math.min(i, N+1); j++) {
				if(Math.min(dp1[i-j-1][j], dp1[i-j][j-1]) <= K-1 
						&& map[i-j][j] != 'a') {
					dp1[i-j][j] = Math.min(dp1[i-j-1][j], dp1[i-j][j-1]) + 1;
					max = i;
				}
				else if(Math.min(dp1[i-j-1][j], dp1[i-j][j-1]) <= K && 
						map[i-j][j] == 'a') {
					dp1[i-j][j] = Math.min(dp1[i-j-1][j], dp1[i-j][j-1]);
					max = i;
				}
			}
		}
		dp2[N][N] = 1;
		for(int i = 2*N-1; i>=2; i--) {
			Long arr[] = new Long[Math.min(i, N+1)-Math.max(1, i-N)];
			int idx = 0;
			for(int j = Math.max(1, i-N); j<Math.min(i, N+1); j++) {
				arr[idx++] = (map[i-j][j]-'a')*1000000000000L
						+Math.min(dp2[i-j+1][j], dp2[i-j][j+1])*1000000L
						+j;
			}
			Arrays.sort(arr);
			for(int j = 0; j<Math.min(i, N+1)-Math.max(1, i-N); j++) {	
				int pos = (int)(arr[j]%1000000);
				dp2[i-pos][pos] = j+1;
			}
		}
		int pos = 0, best = Integer.MAX_VALUE;
		for(int j = Math.max(1, max-N); j<Math.min(max, N+1); j++) {
			if(dp1[max-j][j] < 1000000) {
				if(Math.min(dp2[max-j][j+1], dp2[max-j+1][j]) < best) {
					pos = j;
					best = Math.min(dp2[max-j][j+1], dp2[max-j+1][j]);
				}
			}
		}
		for(int i = 2; i<=max; i++) print('a');
		for(int i = max; i<2*N; i++) {
			if(dp2[i-pos+1][pos] < dp2[i-pos][pos+1]) {
				print(map[i-pos+1][pos]);
			}
			else {
				print(map[i-pos][pos+1]);
				pos++;
			}
		}
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
		byte[] ret = new byte[2001];
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