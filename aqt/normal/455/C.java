import java.util.*;
import java.io.*;

public class _455_C_Civilization {
	
	public static int find(int n) {return par[n] = par[n] ==n ? n : find(par[n]);}
	
	static ArrayList<Integer> graph[]; static int par[]; static int dist[];

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), Q = readInt(); dist = new int[N+1]; int dist[] = new int[N+1];
		par = new int[N+1]; for(int i = 1; i<=N; i++) par[i] = i; 
		graph = new ArrayList[N+1]; for(int i = 1;i <=N; i++) graph[i] = new ArrayList<Integer>();
		for(int i = 1; i<=M; i++) {int a = readInt(), b = readInt(); graph[a].add(b); graph[b].add(a);}
		for(int i = 1; i<=N; i++) if(par[i] == i) dist[i] = dist(i, N);
		for(int q = 0; q<Q; q++) {
			if(readInt() == 1) println(dist[find(readInt())]);
			else {
				int a = find(readInt()), b = find(readInt()); if(a == b) continue;
				par[a] = b; dist[b] = Math.max((dist[a]+1)/2 + (dist[b]+1)/2 + 1, Math.max(dist[a], dist[b]));
			}
		}
		exit();
	}
	
	public static int dist(int src, int N) {
		dist[src] = 1; int max = src;
		LinkedList<Integer> ll = new LinkedList<Integer>(); ll.add(src);
		while(!ll.isEmpty()) {
			int n = ll.pop(); max = dist[n] > dist[max] ? n : max; par[n] = src;
			for(int e : graph[n]) if(dist[e] == 0){
				dist[e] = dist[n] + 1; ll.add(e);
			}
		}
		src = max; dist[src] = -1; ll.add(src);
		while(!ll.isEmpty()) {
			int n = ll.pop(); max = dist[n] < dist[max] ? n : max;
			for(int e : graph[n]) if(dist[e] >= 0){
				dist[e] = dist[n] - 1; ll.add(e);
			}
		}
		return -dist[max]-1;
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