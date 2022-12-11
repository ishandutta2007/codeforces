import java.util.*;
import java.io.*;

public class _729_C_RoadToCinema {
	
	static ArrayList<Integer> gs; static int T;

	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt(), M = readInt(); T = readInt();
		int cst[] = new int[N+1], cap[] = new int[N+1]; for(int i = 1; i<=N; i++) {cst[i] = readInt(); cap[i] = readInt();}
		gs = new ArrayList<>(); gs.add(0); gs.add(M); for(int i = 1; i<=K; i++) gs.add(readInt()); Collections.sort(gs);
		int best = Integer.MAX_VALUE, lo = 1, hi = 1000000000; while(lo <= hi) {
			int mid = (lo + hi)/2; if(solve(mid)) {best = Math.min(best, mid); hi = mid - 1;} else lo = mid + 1;
		}
		int min = Integer.MAX_VALUE; for(int i = 1; i<=N; i++) if(cap[i] >= best) min = Math.min(min, cst[i]); 
		println(min == Integer.MAX_VALUE ? -1 : min);
		exit();
	}
	
	public static boolean solve(int cap) {
		long tot = 0; for(int i = 0; i<gs.size()-1; i++) {
			int delta = gs.get(i+1) - gs.get(i);
			if(cap < delta) return false;
			else if(cap >= 2*delta) tot += delta;
			else {int t = cap - delta; tot += 2*delta-t;}
			if(tot > T) return false;
		}
		if(tot > T) return false; 
		return true;
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