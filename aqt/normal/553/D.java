import java.util.*;
import java.io.*;

public class _0553_D_NudistBeach {
	
	static class Pair implements Comparable<Pair>{
		int n; double v;
		public Pair(int n, double v) {
			this.n = n; this.v = v;
		}
		public int compareTo(Pair p) {
			return Double.compare(this.v, p.v);
		}
	}
	
	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), K = readInt();
		boolean isfort[] = new boolean[N+1];
		for(int i = 1; i<=K; i++) {
			isfort[readInt()] = true;
		}
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		ArrayList<Integer> graph[] = new ArrayList[N+1];
		for(int i =1; i<=N; i++) graph[i] = new ArrayList<>();
		int dgr[] = new int[N+1], act[] = new int[N+1];
		for(int i = 1; i<=M; i++) {
			int a = readInt(), b = readInt();
			graph[a].add(b);
			graph[b].add(a);
			dgr[a]++; dgr[b]++;
			if(!isfort[b]) {
				act[a]++;
			}
			if(!isfort[a]) {
				act[b]++;
			}
		}
		for(int i = 1; i<=N; i++) {
			if(!isfort[i])
				pq.add(new Pair(i, act[i]*1.0/dgr[i]));
		}
		double bestv = -1;
		int bestp = 0;
		int ans[] = new int[N+1];
		int cnt = N;
		while(!pq.isEmpty()) {
			Pair p = pq.poll();
			if(isfort[p.n]) continue;
			int n = p.n;
			ans[cnt] = n;
			if(bestv < p.v) {
				bestv = p.v;
				bestp = cnt;
			}
			cnt--;
			for(int e : graph[n]) {
				act[e]--;
				if(!isfort[e]) {
					pq.add(new Pair(e, act[e]*1.0/dgr[e]));
				}
			}
			isfort[n] = true;
			act[n] = 10000000;
		}
		println(bestp-cnt);
		for(int i = cnt+1; i<=bestp; i++) {
			print(ans[i] + " ");
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