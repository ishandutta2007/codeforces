import java.util.*;
import java.io.*;

public class _1041_C {
	
	static class Pair implements Comparable<Pair>{
		int x, v, id;
		public Pair(int x, int v, int id) {
			this.x = x; this.v =v ; this.id = id;
		}
		public int compareTo(Pair p) {
			return Integer.compare(this.v, p.v);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), D = readInt();
		PriorityQueue<Pair> pq= new PriorityQueue<>();
		int cnt = 0;
		int ans[] = new int[N+1];
		Pair arr[] = new Pair[N];
		for(int i = 0; i<N; i++) arr[i] = new Pair(0, readInt(), i+1);
		Arrays.sort(arr);
		for(int i = 1; i<=N; i++) {
			int n = arr[i-1].v;
//			println(n);
			if(pq.isEmpty() || n-pq.peek().v <= D) {
				cnt++;
				pq.add(new Pair(cnt, n, 2));
				ans[arr[i-1].id] = cnt;
			}
			else {
				ans[arr[i-1].id] = pq.peek().x;
				pq.poll();
				pq.add(new Pair(ans[arr[i-1].id], n, 2));
			}
//			println(pq.peek().v);
		}
		println(cnt);
		for(int i = 1; i<=N; i++) {
			print(ans[i] + " ");
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