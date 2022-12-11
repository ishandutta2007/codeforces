import java.util.*;
import java.io.*;

public class _0723_D_LakesInBerland {

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), K = readInt();
		char map[][] = new char[N+2][M+2];
		for(int i = 1; i<=N; i++) {
			String s = read();
			for(int j = 1; j<=M; j++) {
				map[i][j] = s.charAt(j-1);
			}
		}
		int type[][] = new int[N+2][M+2];
		int moves[][] = {{0,0,1,-1},{1,-1,0,0}};
		LinkedList<Integer> X = new LinkedList<>(), Y = new LinkedList<>();
		for(int i = 1; i<=N; i++) {
			if(type[i][1] == 0 && map[i][1] == '.') {
				X.add(i); Y.add(1);
				while(!X.isEmpty()) {
					int x = X.pop(), y = Y.pop();
					type[x][y] = -1;
					for(int j = 0; j<4; j++) {
						if(map[moves[0][j]+x][moves[1][j]+y] == '.' && 
								type[moves[0][j]+x][moves[1][j]+y] == 0) {
							type[moves[0][j]+x][moves[1][j]+y] = -1;
							X.add(moves[0][j]+x);
							Y.add(moves[1][j]+y);
						}
					}
				}
			}
			if(type[i][M] == 0 && map[i][M] == '.') {
				X.add(i); Y.add(M);
				while(!X.isEmpty()) {
					int x = X.pop(), y = Y.pop();
					type[x][y] = -1;
					for(int j = 0; j<4; j++) {
						if(map[moves[0][j]+x][moves[1][j]+y] == '.' && 
								type[moves[0][j]+x][moves[1][j]+y] == 0) {
							type[moves[0][j]+x][moves[1][j]+y] = -1;
							X.add(moves[0][j]+x);
							Y.add(moves[1][j]+y);
						}
					}
				}
			}
		}
		for(int i = 1; i<=M; i++) {
			if(type[1][i] == 0 && map[1][i] == '.') {
				X.add(1); Y.add(i);
				while(!X.isEmpty()) {
					int x = X.pop(), y = Y.pop();
					type[x][y] = -1;
					for(int j = 0; j<4; j++) {
						if(map[moves[0][j]+x][moves[1][j]+y] == '.' && 
								type[moves[0][j]+x][moves[1][j]+y] == 0) {
							type[moves[0][j]+x][moves[1][j]+y] = -1;
							X.add(moves[0][j]+x);
							Y.add(moves[1][j]+y);
						}
					}
				}
			}
			if(type[N][i] == 0 && map[N][i] == '.') {
				X.add(N); Y.add(i);
				while(!X.isEmpty()) {
					int x = X.pop(), y = Y.pop();
					type[x][y] = -1;
					for(int j = 0; j<4; j++) {
						if(map[moves[0][j]+x][moves[1][j]+y] == '.' && 
								type[moves[0][j]+x][moves[1][j]+y] == 0) {
							type[moves[0][j]+x][moves[1][j]+y] = -1;
							X.add(moves[0][j]+x);
							Y.add(moves[1][j]+y);
						}
					}
				}
			}
		}
		int sz[] = new int[3000];
		int idx = 0;
		for(int i = 2; i<N; i++) for(int j = 2; j<M; j++) {
			if(type[i][j] == 0 && map[i][j] == '.') {
				X.add(i); Y.add(j);
				idx++;
				while(!X.isEmpty()) {
					int x = X.pop(), y = Y.pop();
					type[x][y] = idx;
					sz[idx]++;
					for(int k = 0; k<4; k++) {
						if(map[moves[0][k]+x][moves[1][k]+y] == '.' && 
								type[moves[0][k]+x][moves[1][k]+y] == 0) {
							type[moves[0][k]+x][moves[1][k]+y] = idx;
							X.add(moves[0][k]+x);
							Y.add(moves[1][k]+y);
						}
					}
				}
			}
		}
		HashSet<Integer> lakes = new HashSet<>();
		int tot = 0;
		sz[0] = Integer.MAX_VALUE;
		for(int i = 1; i<=idx-K; i++) {
			int max = 0;
			for(int j= 1; j<=idx; j++) {
				max = sz[max] > sz[j] ? j : max;
			}
			tot += sz[max];
			sz[max] = Integer.MAX_VALUE;
			lakes.add(max);
		}
		println(tot);
		for(int i = 1; i<=N; i++) {
			for(int j = 1; j<=M; j++) {
				if(lakes.contains(type[i][j]) || map[i][j] == '*') {
					print('*');
				}
				else {
					print('.');
				}
			}
			println();
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