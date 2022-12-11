import java.util.*;
import java.io.*;

public class _0279_C_Ladder {

	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt(); int arr[] = new int[N+1]; for(int i= 1; i<=N; i++) arr[i] = readInt();
		int cnt = 1; Stack<Integer> stk = new Stack<Integer>(); int map[] = new int[N+1]; stk.add(arr[1]); map[1] = 1;
		for(int i = 2; i<=N; i++) {if(stk.peek() == arr[i]) map[i] = cnt; else {stk.add(arr[i]); map[i] = ++cnt;}}
		N = cnt; int a[] = new int[N+1]; for(int i = N; i>=1; i--) a[i] = stk.pop();
//		int logN = Integer.numberOfTrailingZeros(Integer.highestOneBit(N)); boolean tbl[][] = new boolean[N+1][logN+2];
//		for(int i = 1; i<N-1; i++) tbl[i][0] = a[i+1] - a[i] < 0 && a[i+2] - a[i+1] > 0;
//		for(int i = 1; i<=logN; i++) for(int j = 1; j<=N-(1<<i); j++) tbl[j][i] = tbl[j][i-1] | tbl[j+(1<<(i-1))][i-1];
//		for(int q = 0; q<Q; q++) {
//			int l = map[readInt()], r = map[readInt()];
//			if(r - l <= 1) println("Yes"); 
//			else {
//				r -= 2; int gap2 = Integer.numberOfTrailingZeros(Integer.highestOneBit(r-l+1)); 
//				println(tbl[l][gap2]|tbl[r-(1<<gap2)+1][gap2] ? "No" : "Yes");
//			}
//		}
		int lim[] = new int[N+1]; int last = 1; 
		for(int i = 1; i<N-1; i++) lim[i] = last = a[i+1] - a[i] < 0 && a[i+2] - a[i+1] > 0 ? i+1 : last;
		for(int q = 0; q < Q; q++) {
			int l = map[readInt()], r = map[readInt()];
			if(r - l >= 2) println(l >= lim[r-2] ? "Yes" : "No");
			else println("Yes");
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