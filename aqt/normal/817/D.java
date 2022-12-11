import java.util.*;
import java.io.*;

public class _0817_D_ImbalancedArray {

	static int N;
	static int arr[];
	static int tbl[][];
	
	public static void main(String[] args) throws IOException {
		N = readInt();
		arr = new int[N+1];
		for(int i = 1; i<=N; i++) {
			arr[i] = readInt();
		}
		tbl = new int[20][N+1];
		for(int j = 1; j<=N; j++) {
			tbl[0][j] = j;
		}
		for(int i = 1; i<20; i++) {
			for(int j = 1; j<=N-(1<<i)+1; j++) {
				tbl[i][j] = arr[tbl[i-1][j]] >= arr[tbl[i-1][j+(1<<(i-1))]] ? 
						tbl[i-1][j] : tbl[i-1][j+(1<<(i-1))];
			}
		}
		long tot = f();
		for(int i =1; i<=N; i++) {
			arr[i] = -arr[i];
		}
		for(int i = 1; i<20; i++) {
			for(int j = 1; j<=N-(1<<i)+1; j++) {
				tbl[i][j] = arr[tbl[i-1][j]] >= arr[tbl[i-1][j+(1<<(i-1))]] ? 
						tbl[i-1][j] : tbl[i-1][j+(1<<(i-1))];
			}
		}
		println(tot + f());
		exit();
	}
	
//	static long f(int l, int r) {
//		if(l > r) {
//			return 0;
//		}
//		int k = Integer.numberOfTrailingZeros(Integer.highestOneBit(r-l+1));
//		int idx = arr[tbl[k][l]] >= arr[tbl[k][r-(1<<k)+1]] ? tbl[k][l] : tbl[k][r-(1<<k)+1];
//		return 1L*arr[idx]*(r-idx+1)*(idx-l+1) + f(l, idx-1) + f(idx+1, r);
//	}
	
	static long f() {
		LinkedList<Long> ll = new LinkedList<>();
		ll.add(1L*10000000+N);
		long tot = 0;
		while(!ll.isEmpty()) {
			long t = ll.pop();
			int l = (int) (t/10000000);
			int r = (int) (t%10000000);
			if(l > r) {
				continue;
			}
			int k = Integer.numberOfTrailingZeros(Integer.highestOneBit(r-l+1));
			int idx = arr[tbl[k][l]] >= arr[tbl[k][r-(1<<k)+1]] ? tbl[k][l] : tbl[k][r-(1<<k)+1];
			tot += 1L*arr[idx]*(r-idx+1)*(idx-l+1);
			ll.add(l*10000000L + idx - 1); 
			ll.add((idx + 1)*10000000L + r);
		}
		return tot;
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