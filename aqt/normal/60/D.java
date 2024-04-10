import java.util.*;
import java.io.*;

public class _0060_D_Savoir {

	public static void main(String[] args) throws IOException {
		int MAXVAL = 10000000;
		int N = readInt(), ans = N; boolean tkn[] = new boolean[MAXVAL+1];
		int par[] = new int[MAXVAL+1]; for(int i = 1; i<=MAXVAL; i++) par[i] = i;
		for(int i = 1; i<=N; i++) tkn[readInt()] = true; 
		for(int i = 1; i<=2*Math.sqrt(MAXVAL); i++) for(int j = i; j<=2*Math.sqrt(MAXVAL); j++) {
			long a = 1L*i*i+1L*j*j, b = 2L*i*j, c = 1L*j*j-1L*i*i;
			if(b > MAXVAL || c > MAXVAL) continue;
			if(a <= MAXVAL && tkn[(int) a] && tkn[(int) b] && gcd(a, b) == 1) {
				int ap = find(par, (int) a), bp = find(par, (int) b);
				if(ap != bp) {ans--; par[bp] = ap;}
			}
			if(a <= MAXVAL && tkn[(int) c] && tkn[(int) a] && gcd(a, c) == 1) {
				int cp = find(par, (int) c), ap = find(par, (int) a);
				if(cp != ap) {ans--; par[cp] = ap;}
			}
			if(b <= MAXVAL && tkn[(int) b] && tkn[(int) c] && gcd(c, b) == 1) {
				int bp = find(par, (int) b), cp = find(par, (int) c);
				if(bp != cp) {ans--; par[Math.min(cp, bp)] = Math.max(bp, cp);}
			}
		}
		println(ans);
		exit();
	}
	
	public static int find(int par[], int n) {
		return par[n] = par[n] == n ? n : find(par, par[n]);
	}
	
	public static long gcd(long a, long b) {
		return a*b == 0 ? a+b : gcd(b, a%b);
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