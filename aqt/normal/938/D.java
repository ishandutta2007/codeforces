import java.util.*;
import java.io.*;

public class _938_D_BuyATicket {
	
	public static class Pair implements Comparable<Pair>{
		int id; long val;
		public Pair(int id, long val) {
			this.id = id; this.val = val;
		}
		@Override
		public int compareTo(Pair o) {
			return Long.compare(this.val, o.val);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(); long d[] = new long[N+1]; ArrayList<Pair> graph[] = new ArrayList[N+1];
		for(int i = 1; i<=N; i++) graph[i] = new ArrayList<Pair>();
		for(int i = 1; i<=M; i++) {
			int a = readInt(), b = readInt(); long dis = 2*readLong();
			graph[a].add(new Pair(b, dis)); graph[b].add(new Pair(a, dis));
		}
		for(int i = 1; i<=N; i++) d[i] = readLong();
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>(); for(int i = 1; i<=N; i++) pq.add(new Pair(i, d[i]));
		while(!pq.isEmpty()) {
			Pair p = pq.poll(); if(p.val != d[p.id]) continue; int n = p.id;
			for(Pair e : graph[n]) if(d[e.id] > d[n] + e.val) {
				d[e.id] = d[n] + e.val; pq.add(new Pair(e.id, d[e.id]));
			}
		}
		for(int i = 1; i<=N; i++) print(d[i] + " ");
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