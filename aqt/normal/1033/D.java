import java.util.*;
import java.io.*;

public class _1033_D {

	public static void main(String[] args) throws IOException {
		int N = readInt();
		long arr[] = new long[N+1];
		boolean tkn[] = new boolean[N+1];
		HashMap<Long, Integer> map = new HashMap<>();
		for(int i = 1; i<=N; i++) {
			arr[i] = readLong();
			long sqrt = sqr(arr[i]);
			long cbrt = cub(arr[i]);
			if(sqrt*sqrt == arr[i]) {
				long sqrtsqrt = sqr(sqrt);
				if(sqrtsqrt*sqrtsqrt == sqrt) {
					map.put(sqrtsqrt, map.getOrDefault(sqrtsqrt, 0)+4);
				}
				else {
					map.put(sqrt, map.getOrDefault(sqrt, 0)+2);
				}
				tkn[i] = true;
			}
			else if(cbrt*cbrt*cbrt == arr[i]) {
				map.put(cbrt, map.getOrDefault(cbrt, 0)+3);
				tkn[i] = true;
			}
		}
		for(int i = 1; i<=N; i++) {
			for(int j = i+1; j<=N; j++) {
				if((arr[i] == arr[j]) || (tkn[i] || tkn[j])) continue;
				long factor = gcd(arr[i], arr[j]);
				if(factor > 1) {
					for(int k = 1; k<=N; k++) {
						if(arr[k]%factor == 0 && !tkn[k]) {
							map.put(factor,map.getOrDefault(factor, 0)+1); 
							map.put(arr[k]/factor,map.getOrDefault(arr[k]/factor, 0)+1);
							tkn[k] = true;
						}
					}
				}
			}
		}
		HashMap<Long, Integer> fre = new HashMap<>();
		long ans = 1, MOD = 998244353;
		for(int i = 1; i<=N; i++) if(!tkn[i]) {
			boolean done = true;
			for(long n : map.keySet()) {
				if(arr[i]%n == 0) {
					map.put(n, map.get(n)+1);
					map.put(arr[i]/n, map.getOrDefault(arr[i]/n, 0)+1);
					done = false;
					break;
				}
			}
			if(done) {
				fre.put(arr[i], fre.getOrDefault(arr[i], 0)+1);
			}
		}
		for(long n : fre.values()) {
			ans = (((ans*(n+1))%MOD)*(n+1))%MOD;
		}
		for(int n : map.values()) {
			ans = (ans*(n+1))%MOD;
		}
		println(ans);
		exit();
	}
	
	static long sqr(long n) {
		long l = 1, r = 2000000000;
		while(l <= r) {
			long mid = (l+r)/2;
			if(mid*mid == n) {
				return mid;
			}
			if(mid*mid < n) l = mid + 1;
			else r = mid - 1;
		}
		return 0;
	}
	
	static long cub(long n) {
		long l = 1, r = 2000000;
		while(l <= r) {
			long mid = (l+r)/2;
			if(mid*mid*mid == n) {
				return mid;
			}
			if(mid*mid*mid < n) l = mid + 1;
			else r = mid - 1;
		}
		return 0;
	}
	
	static long gcd(long a, long b) {
		if(a == 0 || b == 0) {
			return a+b;
		}
		return gcd(b, a%b);
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