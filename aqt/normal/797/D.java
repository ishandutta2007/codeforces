import java.util.*;
import java.io.*;

public class _0797_D_BrokenBST {

	public static void main(String[] args) throws IOException {
		int N = readInt();
		boolean rt[] = new boolean[N+1];
		Arrays.fill(rt, true);
		int left[] = new int[N+1], right[] = new int[N+1], val[] = new int[N+1];
		HashMap<Integer, Boolean> chk = new HashMap<>();
		HashMap<Integer, Integer> sz = new HashMap<>();
		for(int i= 1; i<=N; i++) {
			val[i] = readInt();
			left[i] = readInt();
			right[i] = readInt();
			chk.put(val[i], false);
			sz.put(val[i], sz.getOrDefault(val[i], 0)+1);
			rt[Math.max(left[i], 0)] = rt[Math.max(right[i], 0)] = false;
		}
		int s = 0;
		for(int i= 1; i<=N; i++) if(rt[i]) s = i;
		LinkedList<Integer> ll = new LinkedList<>();
		int rb[] = new int[N+1], lb[] = new int[N+1];
		ll.add(s);
		rb[s] = Integer.MAX_VALUE;
		lb[s] = Integer.MIN_VALUE;
		while(!ll.isEmpty()) {
			int n = ll.pop();
			if(val[n] < rb[n] && val[n] > lb[n]) {
				chk.put(val[n], true);
			}
			if(left[n] != -1) {
				ll.add(left[n]);
				rb[left[n]] = Math.min(val[n], rb[n]);
				lb[left[n]] = lb[n];
			}
			if(right[n] != -1) {
				ll.add(right[n]);
				lb[right[n]] = Math.max(val[n], lb[n]);
				rb[right[n]] = rb[n];
			}
		}
		int cnt = 0;
		for(int n : chk.keySet()) {
			if(!chk.get(n)) cnt+=sz.get(n);
		}
		println(cnt);
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