import java.util.*;
import java.io.*;

public class _0777_E_HanoiFactory {

	public static class Disk implements Comparable<Disk>{
		int o, i, h;
		public Disk(int i, int o, int h) {
			this.o = o; this.i = i; this.h = h;
		}
		public int compareTo(Disk d) {
			if(this.o == d.o) return Integer.compare(d.i, this.i);
			return Integer.compare(d.o, this.o);
		}
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt(); PriorityQueue<Integer> pq = new PriorityQueue<>();
		Disk arr[] = new Disk[N];
		for(int i =0 ; i<N; i++) {
			arr[i] = new Disk(readInt(), readInt(), readInt());
			pq.add(arr[i].i); pq.add(arr[i].o);
		}
		HashMap<Integer, Integer> map = new HashMap<>(); int cnt = 0;
		while(!pq.isEmpty()) {
			int n = pq.poll(); while(!pq.isEmpty() && pq.peek() == n) pq.poll();
			map.put(n, ++cnt);
		}
		long BIT[] = new long[cnt+1];
		Arrays.sort(arr);
		long ans = 0;
		for(int i = 0; i<N; i++) {
			long max = arr[i].h;
			for(int j = map.get(arr[i].o)-1; j>0; j-=j&-j) {
				max = Math.max(BIT[j]+arr[i].h, max);
			}
			ans = Math.max(max, ans);
			for(int j = map.get(arr[i].i); j<=cnt; j+=j&-j) {
				BIT[j] = Math.max(max, BIT[j]);
			}
		}
		println(ans);
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