import java.util.*;
import java.io.*;

public class _321_C_CielTheCommander {
	
	static int N;
	static ArrayList<Integer> graph[] = new ArrayList[100001];
	static int parent[] = new int[100001], size[] = new int[100001];
	static boolean vis[] = new boolean[100001];
	static char val[] = new char[100001];

	public static void main(String[] args) throws IOException {
		
		N = readInt();
		for(int i = 1; i<=N; i++) graph[i] = new ArrayList<Integer>();
		
		for(int i = 1; i<N; i++) {int a = readInt(), b = readInt(); graph[a].add(b); graph[b].add(a);}
		
		solve(1, 0);
		
		for(int i = 1; i<=N; i++) print(val[i] + " ");
		
		exit();
	}
	
	public static void DFS(int n) {
		
		size[n] = 1;
		for(int e : graph[n]) {
			if(e != parent[n] && !vis[e]) {
				parent[e] = n;
				DFS(e);
				size[n] += size[e];
			}
		}
	}
	
	public static int getCentroid(int n) {
		parent[n] = 0; DFS(n); 
		int sz = size[n];
		while(true) {
			int maxIdx = 0;
			for(int e : graph[n]) { 
				if(!vis[e] && e != parent[n]) {
					if(size[maxIdx] < size[e]) maxIdx = e;
				}
			}
			if(size[maxIdx]*2 >= sz) n = maxIdx;
			else return n;
		}
	}
	
	public static void solve(int n, int depth) throws IOException {
		n = getCentroid(n); vis[n] = true;	
		val[n] = (char) (depth + 'A');
		for(int e : graph[n]) if(!vis[e]) solve(e, depth+1);
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static float readFloat() throws IOException {
		return Float.parseFloat(next());
	}

	static boolean readBoolean() throws IOException {
		return Boolean.parseBoolean(next());
	}

	static short readShort() throws IOException {
		return Short.parseShort(next());
	}

	static byte readByte() throws IOException {
		return Byte.parseByte(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readCharacter() throws IOException {
		return next().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}

	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	static void print(Object o) {
		pr.print(o);
	}

	static void println(Object o) {
		pr.println(o);
	}

	static void flush() {
		pr.flush();
	}

	static void exit() throws IOException {
		br.close();
		pr.close();
		System.exit(0);
	}
}