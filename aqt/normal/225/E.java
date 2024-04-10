import java.util.*;
import java.io.*;

public class _0255_E_Unsolvable {

	public static void main(String[] args) throws IOException {
		int N = readInt(); 
		if(N == 1) println(1);
		if(N == 2) println(3);
		if(N == 3) println(15);
		if(N == 4) println(63);
		if(N == 5) println(4095);
		if(N == 6) println(65535);
		if(N == 7) println(262143);
		if(N == 8) println(73741816);
		if(N == 9) println(536396503);
		if(N == 10) println(140130950);
		if(N == 11) println(487761805);
		if(N == 12) println(319908070);
		if(N == 13) println(106681874);
		if(N == 14) println(373391776);
		if(N == 15) println(317758023);
		if(N == 16) println(191994803);
		if(N == 17) println(416292236);
		if(N == 18) println(110940209);
		if(N == 19) println(599412198);
		if(N == 20) println(383601260);
		if(N == 21) println(910358878);
		if(N == 22) println(532737550);
		if(N == 23) println(348927936);
		if(N == 24) println(923450985);
		if(N == 25) println(470083777);
		if(N == 26) println(642578561);
		if(N == 27) println(428308066);
		if(N == 28) println(485739298);
		if(N == 29) println(419990027);
		if(N == 30) println(287292016);
		if(N == 31) println(202484167);
		if(N == 32) println(389339971);
		if(N == 33) println(848994100);
		if(N == 34) println(273206869);
		if(N == 35) println(853092282);
		if(N == 36) println(411696552);
		if(N == 37) println(876153853);
		if(N == 38) println(90046024);
		if(N == 39) println(828945523);
		if(N == 40) println(697988359);
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