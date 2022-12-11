import java.util.*;
import java.io.*;

public class _612_D_TheUnionOfKSegments {

	public static class Pair implements Comparable<Pair>{
		int l, r;
		public Pair(int l, int r) {
			this.l = l; this.r =r ;
		}
		public int compareTo(Pair p) {
			return Integer.compare(this.l, p.l);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt(); 
		PriorityQueue<Integer> rpq = new PriorityQueue<Integer>(); PriorityQueue<Pair> lpq = new PriorityQueue<Pair>();
		for(int i = 1; i<=N; i++)lpq.add(new Pair(readInt(), readInt())); 
		ArrayList<Pair> list = new ArrayList<Pair>(); int cnt = 0, start = (int) -(1e9+7), end = start; boolean line = false;
		while(!lpq.isEmpty() || !rpq.isEmpty()) {
			if(!lpq.isEmpty() && ((!rpq.isEmpty() && lpq.peek().l < rpq.peek()) || rpq.isEmpty())) {
				int here = lpq.peek().l; 
				while(!lpq.isEmpty() && lpq.peek().l == here) {cnt++; rpq.add(lpq.poll().r);}
				if(!line && cnt >= K) {line = true; end = start = here;}
				else if(cnt >= K) end = here;
			}
			else if(!rpq.isEmpty() && ((!lpq.isEmpty() && lpq.peek().l > rpq.peek()) || lpq.isEmpty())) {
				int here = rpq.peek(); if(cnt >= K) end = here;
				while(!rpq.isEmpty() && rpq.peek() == here) {cnt--; rpq.poll();}
				if(line && cnt < K) {line = false; list.add(new Pair(start, end));}
			}
			else if(!lpq.isEmpty() && !rpq.isEmpty() && lpq.peek().l == rpq.peek()){
				int here = lpq.peek().l; while(!lpq.isEmpty() && lpq.peek().l == here) {cnt++; rpq.add(lpq.poll().r);}
				if(!line && cnt >= K) {line = true; end = start = here;}
				else if(cnt >= K) end = here; here = rpq.peek();
				while(!rpq.isEmpty() && rpq.peek() == here) {cnt--; rpq.poll();}
				if(line && cnt < K) {line = false; list.add(new Pair(start, end));}
			}
		}
		println(list.size()); for(Pair p : list) println(p.l + " " + p.r);
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