import java.util.*;
import java.io.*;

public class _1037_D {
	
	static class Pair implements Comparable<Pair>{
		int e, p;
		public Pair(int e) {this.e = e;}
		public int compareTo(Pair p) {
			return Integer.compare(this.p, p.p);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt();
		ArrayList<Pair> graph[] = new ArrayList[N+1];
		for(int i=  1; i<=N; i++) graph[i] = new ArrayList<>();
		LinkedList<Integer> ll = new LinkedList<>();
		for(int i = 1; i<N; i++) {
			int a = readInt(),b = readInt();
			graph[a].add(new Pair(b)); graph[b].add(new Pair(a));
		}
		ll.add(1);
		int dist[] = new int[N+1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[1] = 0;
		int seq[] = new int[N+1];
		int idx[] = new int[N+1];
		for(int i = 1; i<=N; i++) {
			seq[i] = readInt();
			idx[seq[i]] = i;
		}
		for(int i = 1; i<=N; i++) {
			for(Pair e : graph[i]) e.p = idx[e.e];
			Collections.sort(graph[i]);
		}
		int crnt = 1;
		while(!ll.isEmpty()) {
			int n = ll.pop();
			if(seq[crnt] == n) crnt++;
			else {
				println("No");
				exit();
			}
			for(Pair e : graph[n]) {
				if(dist[e.e] == Integer.MAX_VALUE) {
					dist[e.e] = dist[n] + 1;
					ll.add(e.e);
				}
			}
		}
		println("Yes");
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