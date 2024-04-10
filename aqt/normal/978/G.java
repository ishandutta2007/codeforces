import java.util.*;
import java.io.*;

public class _978_G_PetyasExam {
	
	public static class Quad{
		int s, e, pre, id;
		public Quad(int s, int e, int pre, int id) {
			this.s = s; this.e = e; this.pre = pre; this.id = id;
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(); Quad exam[] = new Quad[M+1]; int ans[] = new int[N+1];
		for(int i = 1; i<=M; i++) exam[i] = new Quad(readInt(), readInt(), readInt(), i);
		PriorityQueue<Quad> pq1 = new PriorityQueue<>(new comp1()), pq2 = new PriorityQueue<>(new comp2());
		for(int i = 1; i<=M; i++) {pq1.add(exam[i]); ans[exam[i].e] = -i;}
		for(int i = 1; i<=N; i++) {
			while(!pq1.isEmpty() && pq1.peek().s == i) pq2.add(pq1.poll());
			if(ans[i] < 0) {if(pq2.contains(exam[-ans[i]])) {println(-1); exit();} else ans[i] = M+1; continue;}
			else if(pq2.isEmpty()) continue; 
			ans[i] = pq2.peek().id; pq2.peek().pre--; if(pq2.peek().pre == 0) pq2.poll(); 
		}
		for(int i = 1; i<=N; i++) print(ans[i] + " ");
		exit();
	}
	
	public static class comp1 implements Comparator<Quad>{
		@Override
		public int compare(Quad o1, Quad o2) {
			return Integer.compare(o1.s, o2.s);
		} 
	}
	
	public static class comp2 implements Comparator<Quad>{
		@Override
		public int compare(Quad o1, Quad o2) {
			return Integer.compare(o1.e, o2.e);
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