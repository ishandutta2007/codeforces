import java.util.*;
import java.io.*;

public class _1000_E_WeNeedMoreBosses {
	
	public static class Edge{
		int to, id;
		public Edge(int to, int id) {
			this.to = to; this.id = id;
		}
	}

	static int N, M; static ArrayList<Edge> graph[], cgraph[];
	static int low[], par[], dsc[], time = 0; static boolean bdg[], vis[];
	
	public static void main(String[] args) throws IOException {
		N = readInt(); M = readInt(); graph = new ArrayList[N+1]; for(int i =1; i<=N; i++) graph[i] = new ArrayList<>(); int cnt = 1;
		for(int i = 1; i<=M; i++) {int a = readInt(), b = readInt(); graph[a].add(new Edge(b, i)); graph[b].add(new Edge(a, i));}
		low = new int[N+1]; par = new int[N+1]; dsc = new int[N+1]; bdg = new boolean[M+1]; vis = new boolean[N+1]; dfs((cnt = 1)); 
		vis = new boolean[N+1]; int w[] = new int[N+1]; for(int i = 1; i<=N; i++) if(!vis[i]) {
			LinkedList<Integer> ll = new LinkedList<>(); ll.add(i); w[i] = cnt; vis[i] = true; while(!ll.isEmpty()) {
				int n = ll.pop(); for(Edge e : graph[n]) if(!bdg[e.id] && !vis[e.to]) {vis[e.to] = true; ll.add(e.to); w[e.to] = cnt;}
			}
			cnt++;
		}
		cgraph = new ArrayList[cnt]; for(int i = 1; i<cnt; i++) cgraph[i] = new ArrayList<>();
		for(int i = 1; i<=N; i++) for(Edge e : graph[i]) if(bdg[e.id]) cgraph[w[i]].add(new Edge(w[e.to], 0));
		int dist[] = bfs(1), max = 1; for(int i = 2; i<cnt; i++) max = dist[max] > dist[i] ? max : i; 
		dist = bfs(max); int dis = 0; for(int i = 1; i<cnt; i++) dis = Math.max(dis, dist[i]); println(dis); exit();
	}
	
	public static int [] bfs(int n) {
		LinkedList<Integer> ll = new LinkedList<>(); int dist[] = new int[N+1]; Arrays.fill(dist, Integer.MAX_VALUE);
		ll.add(n); dist[n] = 0; while(!ll.isEmpty()) {
			n = ll.pop(); for(Edge e : cgraph[n]) if(dist[e.to] == Integer.MAX_VALUE){
				dist[e.to] = dist[n] + 1; ll.add(e.to);
			}
		}
		return dist;
	}
	
	public static void dfs(int n) {
		vis[n] = true; low[n] = dsc[n] = ++time; for(Edge e : graph[n]) {
			if(!vis[e.to]) {
				par[e.to] = n; dfs(e.to);
				low[n] = Math.min(low[e.to], low[n]);
				if(low[e.to] > low[n]) bdg[e.id] = true;
			}
			else if(par[n] != e.to) low[n] = Math.min(dsc[e.to], low[n]);
		}
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