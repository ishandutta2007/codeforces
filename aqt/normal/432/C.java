import java.util.*;
import java.io.*;

public class _0432_C_PrimeSwaps {

	public static void main(String[] args) throws IOException {
		int N = readInt();
		int arr[] = new int[N+1];
		int idx[] = new int[N+1];
		for(int i = 1; i<=N; i++) {
			arr[i] = readInt();
			idx[arr[i]] = i;
		}
		ArrayList<Integer> primes = new ArrayList<>();
		boolean seive[] = new boolean[N+1];
		seive[1] = seive[0] = true;
		for(int i = 2; i<=N; i++) if(!seive[i]) {
			primes.add(i);
			for(int j = 2*i; j<=N; j+=i) seive[j] = true;
		}
		int sum[][] = new int[2][N+1];
		for(int i : primes) {
			if(i == 2) continue;
			sum[0][i-1] = i;
			sum[1][i-1] = 0;
			for(int j : primes) {
				if(i == 2 || j == 2) continue;
				if(i+j-2>N) break;
				sum[0][i+j-2] = i;
				sum[1][i+j-2] = j;
			}
		}
		LinkedList<Integer> ll1 = new LinkedList<>(), ll2 = new LinkedList<>();
		for(int i = 1; i<=N; i++) {
			if(idx[i] == i) continue;
			if((idx[i]-i)%2 == 1) {
				int temp = arr[idx[i]];
				arr[idx[i]] = arr[idx[i]-1];
				arr[idx[i]-1] = temp;
				idx[arr[idx[i]]] = idx[i];
				idx[i] = idx[i]-1;
				ll1.add(idx[i]+1);
				ll2.add(idx[i]);
			}
			int diff = idx[i]-i;
			if(sum[0][diff] == 0) continue;
			ll1.add(idx[i]);
			ll2.add(idx[i]-sum[0][diff] + 1);
			int temp = arr[idx[i]];
			arr[idx[i]] = arr[idx[i]-sum[0][diff]+1];
			arr[idx[i]-sum[0][diff]+1] = temp;
			idx[arr[idx[i]]] = idx[i];
			idx[arr[idx[i] - sum[0][diff] + 1]] = idx[i] - sum[0][diff] + 1;
			
			if(sum[1][diff] == 0) continue;
			ll1.add(idx[i]);
			ll2.add(idx[i]-sum[1][diff] + 1);
			temp = arr[idx[i]];
			arr[idx[i]] = arr[idx[i]-sum[1][diff]+1];
			arr[idx[i] - sum[1][diff]+1] = temp;
			idx[arr[idx[i]]] = idx[i];
			idx[arr[idx[i] - sum[1][diff] + 1]] = idx[i] - sum[1][diff] + 1;
		}
		println(ll1.size());
		while(!ll1.isEmpty()) {
			println(ll2.removeFirst() + " " + ll1.removeFirst());
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