import java.util.*;
import java.io.*;

public class _372_C_WatchingFireworksIsFun {

	public static class Trio implements Comparable<Trio>{
		int time, pos, val;
		public Trio(int p, int v, int t) {
			this.time = t; this.pos = p; this.val = v;
		}
		public int compareTo(Trio o) {
			return Integer.compare(this.time, o.time);
		}
	}
	
	public static class Pair{
		int idx; long val;
		public Pair(int idx, long val) {
			this.idx = idx; this.val = val;
		}
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), d = readInt(); long DP[][] = new long[2][N+1]; Trio arr[] = new Trio[M+1];
		for(int i = 1; i<=M; i++) arr[i] = new Trio(readInt(), readInt(), readInt()); arr[0] = new Trio(0,0,0);Arrays.sort(arr); 
		for(int i= 1; i<=M; i++) {
			Pair ll[] = new Pair[N+1]; int idx = 0, L = 1, R = 0, b4 = (i+1)%2; long gap = arr[i].time - arr[i-1].time;
			for(int j= 1; j<=N; j++) {
				long ub = j + d * gap, lb = j - d * gap;
				while(idx < N && idx < ub) {
					while(R>=L && ll[R].val < DP[b4][idx + 1]) R--;
					ll[++R] = (new Pair(++idx, DP[b4][idx]));
				}
				DP[i%2][j] = ll[L].val;
				while(R>=L && ll[L].idx <= lb) L++;
				DP[i%2][j] += arr[i].val - Math.abs(arr[i].pos - j);
			}
		}
		long ans = Long.MIN_VALUE; int b4 = M%2; for(int i = 1; i<=N; i++) ans = Math.max(DP[b4][i], ans); println(ans); exit();
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
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