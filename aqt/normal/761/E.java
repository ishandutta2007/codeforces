import java.util.*;
import java.io.*;

public class _761_E_DashaAndPuzzle {

	public static void main(String[] args) throws IOException {
		int N = readInt(); ArrayList<Integer> graph[] = new ArrayList[N+1]; for(int i = 1; i<=N; i++) graph[i] = new ArrayList<>();
		for(int i = 1; i<N; i++) {
			int a = readInt(), b = readInt(); graph[a].add(b); graph[b].add(a);
		}
		int max = 0; for(int i = 1; i<=N; i++) max = Math.max(max, graph[i].size()); if(max >= 5) {println("NO"); exit();}
		LinkedList<Integer> ll = new LinkedList<>(); ll.add(1); 
		long x[] = new long[N+1], y[] = new long[N+1], dep[] = new long[N+1]; dep[1] = 1L<<31;
		boolean tkn[][] = new boolean[N+1][4]; 
		while(!ll.isEmpty()) {
			int n = ll.pop(); for(int e : graph[n]) if(dep[e] == 0) {
				dep[e] = dep[n]/2; ll.add(e); 
				if(!tkn[n][0]) {x[e] = x[n] + dep[n]; y[e] = y[n]; tkn[e][1] = tkn[n][0] = true;}
				else if(!tkn[n][1]){x[e] = x[n] - dep[n]; y[e] = y[n]; tkn[e][0] = tkn[n][1] = true;}
				else if(!tkn[n][2]){x[e] = x[n]; y[e] = y[n] + dep[n]; tkn[e][3] = tkn[n][2] = true;}
				else {x[e] = x[n]; y[e] = y[n] - dep[n]; tkn[e][2] = tkn[n][3] = true;}
			}
		}
		println("YES"); for(int i = 1; i<=N; i++) println(x[i] + " " + y[i]);
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

	public void close() throws IOException {
		if (din == null)
			return;
		din.close();
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