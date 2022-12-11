import java.util.*;
import java.io.*;

public class _0208_E_BloodCousins {

	static ArrayList<Integer> graph[];
	static int st[], et[], arr[], time = 0, dep[], par[], sqrtN;

	public static class Query implements Comparable<Query>{
		int l, r, val, id;
		public Query(int l, int r, int val, int id) {
			this.l = l; this.r = r; this.val = val; this.id = id;
		}
		public int compareTo(Query q) {
			if(this.l/sqrtN == q.l/sqrtN) return Integer.compare(this.r, q.r);
			return Integer.compare(this.l/sqrtN, q.l/sqrtN);

		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(); sqrtN = (int) Math.sqrt(N);
		graph = new ArrayList[N+1]; for(int i = 0; i<=N; i++) graph[i] = new ArrayList<>();
		for(int i= 1; i<=N; i++) {int p = readInt(); graph[i].add(p); graph[p].add(i);} 
		st = new int[N+1]; et = new int[N+1]; arr = new int[2*N+1]; dep = new int[N+1]; par = new int[N+1]; dfs(0);
		int logN = Integer.numberOfTrailingZeros(Integer.highestOneBit(N)); int LCA[][] = new int[logN+2][N+1];
		for(int i = 1; i<=N; i++) LCA[0][i] = par[i];
		for(int i = 1; i<=logN+1; i++) for(int j = 1; j<=N; j++) LCA[i][j] = LCA[i-1][LCA[i-1][j]];
		int Q = readInt(); int ans[] = new int[Q]; Query qu[] = new Query[Q]; for(int q = 0; q<Q; q++) {
			int n = readInt(), d = readInt(); if(d >= dep[n]) {ans[q] = 1; qu[q] = new Query(-1, -1, -1, -1);}
			else {
				for(int i = logN+1; i>=0; i--) if(((1<<i)&d) != 0) n = LCA[i][n];
				qu[q] = new Query(st[n], et[n], dep[n]+d, q); 
			}
		}
		Arrays.sort(qu); int l = 1, r = 0, tot[] = new int[N+1]; for(int q = 0; q<Q; q++) {
			int lidx = qu[q].l, ridx = qu[q].r; if(lidx == -1) continue;
			while(l < lidx) tot[arr[l++]]--;
			while(l > lidx) tot[arr[--l]]++;
			while(r < ridx) tot[arr[++r]]++;
			while(r > ridx) tot[arr[r--]]--;
			ans[qu[q].id] += tot[Math.abs(qu[q].val)]/2;
		}
		for(int n : ans) print((n-1) + " "); exit();
	}

	public static void dfs(int n) {
		for(int e : graph[n]) if(par[n] != e){
			par[e] = n; dep[e] = dep[n] + 1; st[e] = ++time; arr[time] = dep[e]; 
			dfs(e); et[e] = ++time; arr[time] = dep[e];
		}
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
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