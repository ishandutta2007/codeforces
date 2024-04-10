import java.util.*;
import java.io.*;

public class _1000_C {
	
	public static class Pair{
		long l, r;
		public Pair(long l, long r) {
			this.l = l; this.r = r;
		}
	}	

	public static void main(String[] args) throws IOException {
		int N = readInt(); long ans[] = new long[N+1]; 
		PriorityQueue<Pair> pq1 = new PriorityQueue<>(new comp1()), pq2 = new PriorityQueue<>(new comp2());
		for(int i = 1; i<=N; i++) pq1.add(new Pair(readLong()-1, readLong())); long last = -1; int tot = 0;
		while(!pq1.isEmpty() || !pq2.isEmpty()) {
			long crnt = Math.min(pq1.isEmpty() ? Long.MAX_VALUE : pq1.peek().l, pq2.isEmpty() ? Long.MAX_VALUE : pq2.peek().r);
			ans[tot] += crnt - last; last = crnt; 
			while(!pq1.isEmpty() && pq1.peek().l == crnt) {pq2.add(pq1.poll()); tot++;}
			while(!pq2.isEmpty() && pq2.peek().r == crnt) {pq2.poll(); tot--;}
		}
		for(int i = 1; i<=N; i++) print(ans[i] + " ");
		exit();
	}
	
	public static class comp1 implements Comparator<Pair>{

		@Override
		public int compare(Pair o1, Pair o2) {
			return Long.compare(o1.l, o2.l);
		}
		
	}
	
	public static class comp2 implements Comparator<Pair>{

		@Override
		public int compare(Pair o1, Pair o2) {
			return Long.compare(o1.r, o2.r);
		}
		
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