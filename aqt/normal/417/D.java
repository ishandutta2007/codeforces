import java.util.*;
import java.io.*;

public class _417_D_CunningGena {
	
	public static class Trio implements Comparable<Trio>{
		int mask, amt, cst;
		public Trio(int mask, int amt, int cst) {
			this.mask = mask; this.amt = amt; this.cst = cst;
		}
		@Override
		public int compareTo(Trio o) {
			return Integer.compare(this.amt, o.amt);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), B = readInt(); Trio arr[] = new Trio[N];
		for(int i = 0; i<N; i++) {
			int cst = readInt(), amt = readInt(), q = readInt(), mask = 0;
			for(int j = 1; j<=q; j++) mask |= (1<<(readInt()-1));
			arr[i] = new Trio(mask, amt, cst);
		}
		Arrays.sort(arr); long moncst = 0; long dp[] = new long[1<<M]; Arrays.fill(dp, Long.MAX_VALUE); dp[0] = 0; long ans = Long.MAX_VALUE;
		for(Trio t : arr) {
			moncst = t.amt; int mask = t.mask;
			for(int i = (1<<M)-1; i>=0; i--) if(dp[i] != Long.MAX_VALUE){
				dp[mask|i] = Math.min(dp[mask|i], dp[i] + t.cst);
			}
			if(dp[(1<<M)-1] != Long.MAX_VALUE) ans = Math.min(ans, dp[(1<<M)-1] + moncst * B);
		}
		println(ans == Long.MAX_VALUE ? -1 : ans);
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