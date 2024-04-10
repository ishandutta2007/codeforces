import java.util.*;
import java.io.*;

public class _0665_D_SimpleSubset {

	public static void main(String[] args) throws IOException {
		boolean seive[] = new boolean[2000001]; seive[1] = seive[0] = true;
		for(int i = 2; i<=2000000; i++) if(!seive[i]) for(int j = 2*i; j<=2000000; j+=i) seive[j] = true;
		int N = readInt(), arr[] = new int[N+1], num1 = 0;  
		for(int i = 1; i<=N; i++) {arr[i] = readInt(); num1 += arr[i] == 1 ? 1 : 0; }
		if(num1 >= 1) {
			for(int i = 1; i<=N; i++) if(arr[i] != 1 && !seive[arr[i] + 1]) {
				println(num1 + 1); while(num1-- > 0) print(1 + " "); print(arr[i]); exit();
			} 
			if(num1 >= 2) {println(num1); while(num1-- > 0) print(1 + " ");}
			else {
				for(int i = 1; i<=N; i++) for(int j = 1; j<=N; j++) if(i != j && !seive[arr[i] + arr[j]]) {
					println(2 + "\n" + arr[i] + " " + arr[j]); exit();
				}
				println(1); println(arr[1]);
			}
		}
		else {
			for(int i = 1; i<=N; i++) for(int j = 1; j<=N; j++) if(i != j && !seive[arr[i] + arr[j]]) {
				println(2 + "\n" + arr[i] + " " + arr[j]); exit();
			}
			println(1); println(arr[1]);
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