import java.util.*;
import java.io.*;

public class _1041_F {

	public static void main(String[] args) throws IOException {
		int N = readInt(), y1 = readInt();
		int arr1[] = new int[N+1];
		for(int i = 1; i<=N; i++) arr1[i] = readInt();
		int M = readInt(), y2 = readInt();
		int arr2[] = new int[M+1];
		for(int i = 1; i<=M; i++) arr2[i] = readInt();
		int max = 1;
		for(int i = 1; i<=N; i++) {
			if(Arrays.binarySearch(arr2, arr1[i]) >= 0) {
				max = 2;
				break;
			}
		}
		for(int p = 1; p<=30; p++) {
			int pow = (1<<p);
			HashMap<Integer, Integer> map1 = new HashMap<>(), map2 = new HashMap<>();
			for(int i = 1; i<=N; i++) map1.put(arr1[i]%pow, map1.getOrDefault(arr1[i]%pow, 0)+1);
			for(int i = 1; i<=M; i++) map2.put(arr2[i]%pow, map2.getOrDefault(arr2[i]%pow, 0)+1);
			pow/=2;
			for(int n : map1.keySet()) {
				max = Math.max(max, map1.get(n) +
						map2.getOrDefault((n+pow)%(pow<<1), 0));
			}
			for(int n : map2.keySet()) {
				max = Math.max(max, map2.get(n) 
						+ map1.getOrDefault((n+pow)%(pow<<1), 0));
			}
		}
		println(max);
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