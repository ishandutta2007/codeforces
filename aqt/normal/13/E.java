import java.util.*;
import java.io.*;

public class _013_E_Holes {

	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt(), BLKSZ = (int) Math.sqrt(N);
		int pow[] = new int[N+1], cnt[] = new int[N+1], end[] = new int[N+1]; 
		for(int i = 1; i<=N; i++) pow[i] = readInt();	
		for(int i = N; i>0; i--) {
			if(i + pow[i] >= Math.min((i/BLKSZ+1)*BLKSZ, N)) end[i] = i;
			else {end[i] = end[pow[i] + i]; cnt[i] = cnt[pow[i] + i] + 1;}
		}
		for(int q = 0; q<Q; q++) {
			if(readInt() == 1) {
				int n = readInt(), tot = 0; while(n <= N) {
					tot += cnt[n] + 1; if(end[n] + pow[end[n]] > N) {n = end[n];break;} n = end[n] + pow[end[n]];
				}
				println(n + " " + tot);
			}
			else {
				int v = readInt(), lim = v/BLKSZ*BLKSZ; pow[v] = readInt();
				for(int i = v; i>=lim; i--) {
					if(i + pow[i] >= Math.min((i/BLKSZ+1)*BLKSZ, N)) {end[i] = i; cnt[i] = 0;}
					else {end[i] = end[pow[i] + i]; cnt[i] = cnt[pow[i] + i] + 1;}
				}
			}
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
		while (c <= ' ')
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
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