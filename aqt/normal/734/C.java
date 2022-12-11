import java.util.*;
import java.io.*;

public class _0734_C_AntonAndMakingPotions {
	
	public static class Pair implements Comparable<Pair>{
		int amt, val;
		public Pair(int amt, int val) {this.amt = amt; this.val = val;}
		public int compareTo(Pair p) {
			return Integer.compare(this.val, p.val);
		}
	}

	public static void main(String[] args) throws IOException {
		int K = readInt(), N = readInt(), M = readInt(), init = readInt(), mana = readInt(); long ans = 1L*init*K;
		Pair time[] = new Pair[N+1]; for(int i = 1; i<=N; i++) time[i] = new Pair(readInt(), 0);
		for(int i = 1; i<=N; i++) time[i].val = readInt(); time[0] = new Pair(init, 0); Arrays.sort(time);
		Pair instant[] = new Pair[M+1]; for(int i = 1; i<=M; i++) instant[i] = new Pair(readInt(), 0);
		for(int i = 1; i<=M; i++) instant[i].val = readInt(); instant[0] = new Pair(0, 0); Arrays.sort(instant);
		LinkedList<Pair> ll = new LinkedList<>(); 
		for(int i = 0; i<=M; i++) {
			while(!ll.isEmpty() && ll.peek().amt < instant[i].amt && instant[i].val == ll.peek().val) ll.removeLast();
			if(ll.isEmpty() || ll.peek().amt < instant[i].amt) ll.addLast(instant[i]);
		}
		for(int i = 0; i<=N; i++) {
			if(time[i].val > mana) break;
			while(!ll.isEmpty() && 1L*ll.peekLast().val+time[i].val > mana) ll.removeLast();
			ans = Math.min(ans, 1L*(K-ll.peekLast().amt)*time[i].amt);
		}
		println(ans);
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