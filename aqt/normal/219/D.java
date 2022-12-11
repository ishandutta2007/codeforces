import java.util.*;
import java.io.*;

public class _219_D_ChoosingCapitalForTreeland {

	public static class Pair{
		int id, val;
		public Pair(int id, int val) {
			this.id = id; this.val  = val;
		}
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt(); ArrayList<Pair> graph[] = new ArrayList[N+1]; 
		for(int i = 1; i<=N; i++) graph[i] = new ArrayList<Pair>();
		for(int i = 1; i<N; i++) { 
			int a = readInt(), b = readInt(); graph[a].add(new Pair(b, 1)); graph[b].add(new Pair(a, -1));
		}
		LinkedList<Pair> ll = new LinkedList<Pair>(); ll.add(new Pair(1, 0)); int cnt = 0;
		while(!ll.isEmpty()) {
			int n = ll.peek().id, p = ll.pop().val; for(Pair e : graph[n]) if(e.id != p){
				cnt += (-e.val+1)/2; ll.add(new Pair(e.id, n));
			}
		}
		ll.add(new Pair(1, 0)); int val[] = new int[N+1]; val[1] = cnt;
		ArrayList<Integer> list = new ArrayList<Integer>(); int min = Integer.MAX_VALUE;
		while(!ll.isEmpty()) {
			int n = ll.peek().id, p = ll.pop().val; 
			if(min > val[n]) { min = val[n]; list.clear(); list.add(n);}
			else if(min == val[n]) list.add(n);
			for(Pair e : graph[n]) if(e.id != p) {
				ll.add(new Pair(e.id, n)); val[e.id] = val[n] + e.val;
			}
		}
		println(min); Collections.sort(list); for(int n : list) print(n + " "); println();
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