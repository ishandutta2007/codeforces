import java.util.*;
import java.io.*;

public class _1043_E {

	static class Pair implements Comparable<Pair>{
		long diff; int id;
		public Pair(long diff, int id) {
			this.diff  = diff; this.id = id;
		}
		public int compareTo(Pair p) {
			return Long.compare(this.diff, p.diff);
		}
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt();
		long x[] = new long[N+1], y[] = new long[N+1];
		Pair sort[] = new Pair[N+1];
		for(int i =1; i<=N; i++) {
			x[i] = readInt();
			y[i] = readInt();
			sort[i] = new Pair(x[i] - y[i], i);
		}
		Arrays.sort(sort, 1, N+1);
		long pre[] = new long[N+1], suf[] = new long[N+2];
		int ord[] = new int[N+1];
		for(int i = 1; i<=N; i++) {
			ord[sort[i].id] = i;
		}
		for(int i =1 ; i<=N; i++) {
			pre[i] = pre[i-1] + x[sort[i].id];
		}
		for(int i = N; i>0; i--) {
			suf[i] = suf[i+1] + y[sort[i].id];
		}
		long val[] = new long[N+1];
		for(int i =1; i<=N; i++) {
			val[sort[i].id] = pre[i-1] + suf[i+1] 
					+ (N-i)*x[sort[i].id] + (i-1)*y[sort[i].id];
		}
		for(int i =1; i<=M; i++) {
			int a = readInt(), b = readInt();
			if(ord[a] < ord[b]) {
				val[a] -= (x[a] + y[b]);
				val[b] -= (x[a] + y[b]);
			}
			else {
				val[a] -= (y[a] + x[b]);
				val[b] -= (y[a] + x[b]);
			}
		}
		for(int i =1; i<=N; i++) {
			print(val[i] + " ");
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