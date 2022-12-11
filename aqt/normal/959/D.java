import java.util.*;
import java.io.*;

public class _0959_D_MahoumadAndEhabAndAnotherArrayConstructionTask {

	public static void main(String[] args) throws IOException {
		boolean seive[] = new boolean[3000001]; seive[1] = seive[0] = true; ArrayList<Integer> prime = new ArrayList<>();
		for(int i = 1; i<=3e6; i++) if(!seive[i]) {
			for(int j = i*2; j<=3e6; j += i) seive[j] = true; prime.add(i);
		}
		int N = readInt(); seive = new boolean[3000001];
		int a[] = new int[N+1], b[] = new int[N+1]; for(int i =1; i<=N; i++) {
			int k = a[i] = readInt(), sqrt = (int) Math.sqrt(k); 
			if(!seive[k]) {
				b[i] = a[i];
				for(int p : prime) if(p > sqrt) break; else if(k%p == 0) {
					while(k%p == 0) k/=p; 
					for(int j = p; j<=3e6; j+=p) seive[j] = true;
				}
				if(k > 1) for(int j = k; j<=3e6; j+=k) seive[j] = true;
			}
			else {
				for(; k <= 3e6; k++) if(!seive[k]) {
					seive[k] = true; b[i] = k;
					for(int p : prime) if(p > sqrt) break; else if(k%p == 0) {
						while(k%p == 0) k/=p; 
						for(int j = p; j<=3e6; j+=p) seive[j] = true;
					}
					if(k > 1) for(int j = k; j<=3e6; j+=k) seive[j] = true;
					break;
				}
				i++;
				for(k = 2; k<=3e6 && i<=N; k++) if(!seive[k]) {
					seive[k] = true; b[i] = k;
					for(int p : prime) if(p > sqrt) break; else if(k%p == 0) {
						while(k%p == 0) k/=p; 
						for(int j = p; j<=3e6; j+=p) seive[j] = true;
					}
					if(k > 1) for(int j = k; j<=3e6; j+=k) seive[j] = true;
					i++;
				}
				break;
			}
		}
		for(int i = 1; i<=N; i++) print(b[i] + " ");
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