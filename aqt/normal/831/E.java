import java.util.*;
import java.io.*;

public class _0831_E_CardsSorting {

	public static class Pair implements Comparable<Pair> {
		int p, v;

		public Pair(int p, int v) {
			this.p = p;
			this.v = v;
		}

		public int compareTo(Pair p) {
			return Integer.compare(this.v, p.v);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt();
		int arr[] = new int[N+1];
		for(int i = 1; i<=N; i++) arr[i] = readInt();
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		for(int i = 1; i<=N; i++) pq.add(new Pair(i, arr[i]));
		BIT = new int[N+1]; for(int i = 1; i<=N; i++) upd(i);
		for(int i = 1; i<=N; i++) BIT[i] = Math.abs(BIT[i]);
		int crntp = 0; long ans = 0;
		while(!pq.isEmpty()) {
			int p = 0, v = pq.peek().v;
			ArrayList<Integer> list = new ArrayList<>();
			while(!pq.isEmpty() && pq.peek().v == v) {
				if(pq.peek().p < crntp) p = Math.max(pq.peek().p+N, p);
				else p = Math.max(pq.peek().p, p);
				list.add(pq.poll().p);
			}
			if(p > N) p-=N;
			if(crntp <= p) ans += sum(p) - sum(crntp);
			else ans += sum(N) - sum(crntp) + sum(p);
			crntp = p;
			for(int n : list) upd(n);
		}
		println(ans);
		exit();
	}

	static int BIT[];

	static int sum(int p) {
		int sum = 0;
		for (int i = p; i > 0; i -= i & -i)
			sum += BIT[i];
		return sum;
	}

	static void upd(int p) {
		for (int i = p; i < BIT.length; i += i & -i)
			BIT[i]--;
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