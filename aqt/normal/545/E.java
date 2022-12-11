import java.util.*;
import java.io.*;

public class _0545_E_PathsAndTrees {
	
	static class Pair implements Comparable<Pair>{
		int n; long v;
		public Pair(int n ,long v) {
			this.n= n; this.v =v ;
		}
		public int compareTo(Pair p) {
			return Long.compare(this.v, p.v);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt();
		ArrayList<Pair> graph[] = new ArrayList[N+1];
		for(int i = 1; i<=N; i++) {
			graph[i] = new ArrayList<>();
		}
		int val[] = new int[M+1];
		for(int i = 1; i<=M; i++) {
			int a = readInt(), b = readInt(), v = readInt();
			graph[a].add(new Pair(b, i)); graph[b].add(new Pair(a, i));
			val[i] = v;
		}
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		long dist[] = new long[N+1];
		Arrays.fill(dist, Long.MAX_VALUE);
		int s = readInt();
		dist[s] = 0;
		pq.add(new Pair(s, 0));
		long min[] = new long[N+1];
		while(!pq.isEmpty()) {
			Pair p = pq.poll();
			if(dist[p.n] != p.v) continue;
			for(Pair e : graph[p.n]) {
				if(dist[e.n] > dist[p.n] + val[(int)e.v]) {
					dist[e.n] = dist[p.n] + val[(int)e.v];
					min[e.n] = e.v;
					pq.add(new Pair(e.n, dist[e.n]));
				}
				else if(dist[e.n] == dist[p.n] + val[(int)e.v]) {
					min[e.n] = val[(int)min[e.n]] > val[(int)e.v] ? e.v : min[e.n];
				}
			}
		}
		long tot = 0;
		for(int i = 1; i<=N; i++) {
			tot += val[(int)min[i]];
		}
		println(tot);
		for(int i = 1; i<=N; i++) {
			if(min[i] != 0) print(min[i] + " ");
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