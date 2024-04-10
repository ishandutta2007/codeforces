import java.util.*;
import java.io.*;

public class _1015_E_StarsDrawing {
	
	public static class Trio{
		int x, y, len;
		public Trio(int x, int y, int len) {
			this.x = x; this.y = y; this.len = len;
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(); boolean tkn[][] = new boolean[N+1][M+1];
		int u[][] = new int[N+2][M+2], d[][] = new int[N+2][M+2], l[][] = new int[N+2][M+2], r[][] = new int[N+2][M+2];
		for(int i = 1; i<=N; i++) {String s = read(); for(int j = 1; j<=M; j++) tkn[i][j] = s.charAt(j-1) == '*';}
		int diffv[][] = new int[N+2][M+2], diffh[][] = new int[N+2][M+2];
		for(int i = 1; i<=N; i++) for(int j = 1; j<=M; j++) if(tkn[i][j]) {
			u[i][j] = u[i-1][j]+1; l[i][j] = l[i][j-1]+1;
		}
		LinkedList<Trio> ll = new LinkedList<>();
		for(int i = N; i>=1; i--) for(int j = M; j>=1; j--) if(tkn[i][j]) {
			d[i][j] = d[i+1][j]+1; r[i][j] = r[i][j+1]+1;
			int min = Math.min(Math.min(d[i][j], u[i][j]), Math.min(l[i][j], r[i][j]))-1;
			if(min == 0) continue;
			else {
				diffv[i-min][j]++; diffv[i+min+1][j]--;
				diffh[i][j-min]++; diffh[i][j+min+1]--;
				ll.add(new Trio(i, j, min));
			}
		}
		for(int i = 1; i<=N; i++) for(int j =1; j<=M; j++) diffv[i][j] += diffv[i-1][j];
		for(int i = 1; i<=N; i++) for(int j =1; j<=M; j++) {
			diffh[i][j] += diffh[i][j-1]; 
			if(tkn[i][j] && (diffv[i][j]+diffh[i][j] == 0)) {println(-1); exit();}
		}
		println(ll.size()); for(Trio t : ll) println(t.x + " " + t.y + " " + t.len);
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