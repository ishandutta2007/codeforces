import java.util.*;
import java.io.*;

public class _987_D_Fair {

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), K = readInt(), S = readInt();
		int head[] = new int[N+1], point[] = new int[2*M+1], to[] = new int[2*M+1];
		int type[][] = new int[N+1][K+1]; int ptr[] = new int[N+1];
		int dist[][] = new int[N+1][K+1]; for(int i = 1; i<=N; i++) for(int j = 1; j<=K; j++) dist[i][j] = Integer.MAX_VALUE;
		for(int i =1; i<=N; i++) {int s = readInt(); type[++ptr[s]][s] = i;}
		for(int i = 1; i<=2*M; i+=2) {
			int a = readInt(), b = readInt(); 
			point[i] = head[a]; head[a] = i; point[i+1] = head[b]; head[b] = i+1; to[i] = b; to[i+1] = a;
		}
		int ll[] = new int[N+5];  for(int i = 1; i<=K; i++) {
			int l = 1, r = 1;
			for(int j = 1; j<=ptr[i]; j++) {ll[r++] = type[j][i]; dist[type[j][i]][i] = 0;} while(l < r) {
				int n = ll[l++]; int pt = head[n]; while(pt != 0) {if(dist[to[pt]][i] > dist[n][i] + 1) {
					dist[to[pt]][i] = dist[n][i] + 1; ll[r++] = to[pt];
				}
				pt = point[pt];
				}
			}
		}
		for(int i = 1; i<=N; i++) {
			Arrays.sort(dist[i]); int tot = 0; for(int j = 1; j<=S; j++) tot += dist[i][j]; print(tot + " ");
		}
		exit();
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ') c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
		return ret;
	}

	private static void fillBuffer() throws IOException {
		bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesRead == -1)
			buffer[0] = -1;
	}

	private static byte Read() throws IOException {
		if (bufferPointer == bytesRead) fillBuffer();
		return buffer[bufferPointer++];
	}

	public void close() throws IOException {
		if (din == null) return;
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