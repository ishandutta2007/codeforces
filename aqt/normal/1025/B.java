import java.util.*;
import java.io.*;

public class _1025_B_WeakenedCommonDivisor{

	public static void main(String[] args) throws IOException {
		int N = readInt();
		ArrayList<Integer> primes = new ArrayList<>();
		boolean isPrime[] = new boolean[50000];
		Arrays.fill(isPrime, true); isPrime[1] = isPrime[0] = false;
		for(int i = 1; i<50000; i++) if(isPrime[i]) {
			primes.add(i);
			for(int j = 2*i; j<50000; j+=i) isPrime[i] = false;
		}
		HashSet<Integer> pos = new HashSet<>();
		int n = readInt();
		for(int p : primes) if(n%p == 0) {
			pos.add(p);
			while(n%p == 0) n/=p;
		}
		if(n > 1) pos.add(n);
		n = readInt();
		for(int p : primes) if(n%p == 0) {
			pos.add(p);
			while(n%p == 0) n/=p;
		}
		if(n > 1) pos.add(n);
		Iterator <Integer>iter = pos.iterator();
		int sz = pos.size();
		int gcd[] = new int[sz];
		for(int i = 0; i<sz; i++) gcd[i] = iter.next();
		for(int i = 2; i<=N; i++) {
			int a = readInt(), b = readInt();
			for(int j = 0; j<sz; j++) if(gcd[j] != 0){
				if(a%gcd[j] != 0 && b%gcd[j] != 0) 
					gcd[j] = 0;
			}
		}
		for(int ne : gcd) if(ne != 0) {println(ne); exit();}
		println(-1);
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