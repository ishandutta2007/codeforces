import java.util.*;
import java.io.*;

public class _1010_D_MarsRover {

	static class Node{
		int typ;
		int cld[];
		int val;
		public Node(int typ, int val) {
			this.typ = typ;
			this.val  = val;
			int t[] = {};
			cld = t;
		}
		public Node(int typ, int val, int child) {
			this.typ = typ;
			this.val = val;
			int t[] = {child};
			cld = t;
		}
		public Node(int type, int val, int cld1, int cld2) {
			this.typ = type;
			this.val = val;
			int t[] = {cld1, cld2};
			cld = t;
		}
	}
	
	static class Pair{
		int idx, val;
		public Pair(int idx, int val) {
			this.idx =idx; this.val = val;
		}
	}
	
	static Node graph[];
	static int val[];
	
	public static void main(String[] args) throws IOException {
		int N = readInt();
		graph = new Node[N+1];
		val = new int[N+1];
		ArrayList<Pair> al = new ArrayList<>();
		for(int i =1; i<=N; i++) {
			String s = read();
			if(s.equals("AND")) {
				graph[i] = new Node(1, 0, readInt(), readInt());
			}
			if(s.equals("OR")) {
				graph[i] = new Node(2, 0, readInt(), readInt());
			}
			if(s.equals("XOR")) {
				graph[i] = new Node(3, 0, readInt(), readInt());
			}
			if(s.equals("NOT")) {
				graph[i] = new Node(4, 0, readInt());
			}
			if(s.equals("IN")) {
				graph[i] = new Node(0, 0);
				val[i] = readInt();
				al.add(new Pair(i, val[i]));
			}
		}
		graph[1].val = 2;
		int arr[] = new int[N+1], par[] = new int[N+1];
		arr[1] = 1;
		for(int l = 1, r = 1; l<=N; l++) {
			for(int e : graph[arr[l]].cld) {
				arr[++r] = e;
				par[r] = arr[l];
			}
		}
		for(int i = N; i>=1; i--) {
			int n = arr[i];
			if(graph[n].typ == 1) {
				val[n] = val[(graph[n].cld[0])] & val[(graph[n].cld[1])];
			}
			if(graph[n].typ == 2) {
				val[n] = val[(graph[n].cld[0])] | val[(graph[n].cld[1])];
			}
			if(graph[n].typ == 3) {
				val[n] = val[(graph[n].cld[0])] ^ val[(graph[n].cld[1])];
			}
			if(graph[n].typ == 4) {
				val[n] = (val[(graph[n].cld[0])]+1)%2;
			}
		}
		for(int j=1; j<=N; j++) {
			int n = arr[j];
			if(graph[n].typ == 1) {
				for(int i =0; i<2; i++) {
					if(val[graph[n].cld[(i+1)%2]] == 0) {
						graph[graph[n].cld[i]].val = ((graph[n].val%2)<<1) + graph[n].val%2;
					}
					else {
						graph[graph[n].cld[i]].val = graph[n].val;
					}
				}
			}
			if(graph[n].typ == 2) {
				for(int i =0; i<2; i++) {
					if(val[graph[n].cld[(i+1)%2]] == 0) {
						graph[graph[n].cld[i]].val = graph[n].val;
					}
					else {
						graph[graph[n].cld[i]].val = ((graph[n].val/2)<<1) + graph[n].val/2;
					}
				}
			}
			if(graph[n].typ == 3) {
				for(int i =0; i<2; i++) {
					if(val[graph[n].cld[(i+1)%2]] == 0) {
						graph[graph[n].cld[i]].val = graph[n].val;
					}
					else {
						graph[graph[n].cld[i]].val = ((graph[n].val%2)<<1) + graph[n].val/2;
					}
				}
			}
			if(graph[n].typ == 4) {
				graph[graph[n].cld[0]].val = ((graph[n].val%2)<<1) + graph[n].val/2;
			}
		}
		for(Pair p : al) {
			if(p.val == 0) {
				print(graph[p.idx].val/2);
			}
			else {
				print(graph[p.idx].val%2);
			}
		}
		exit();
	}
	
	static int dfs1(int n) {
		if(graph[n].typ == 0) {
			return val[n];
		}
		if(graph[n].typ == 1) {
			return val[n] = dfs1(graph[n].cld[0]) & dfs1(graph[n].cld[1]);
		}
		if(graph[n].typ == 2) {
			return val[n] = dfs1(graph[n].cld[0]) | dfs1(graph[n].cld[1]);
		}
		if(graph[n].typ == 3) {
			return val[n] = dfs1(graph[n].cld[0]) ^ dfs1(graph[n].cld[1]);
		}
		if(graph[n].typ == 4) {
			return val[n] = dfs1(graph[n].cld[0]) == 1 ? 0 : 1;
		}
		return 0;
	}
	
	static void dfs2(int n) {
		if(graph[n].typ == 0) {
			return;
		}
		if(graph[n].typ == 1) {
			for(int i =0; i<2; i++) {
				if(val[graph[n].cld[(i+1)%2]] == 0) {
					graph[graph[n].cld[i]].val = ((graph[n].val%2)<<1) + graph[n].val%2;
				}
				else {
					graph[graph[n].cld[i]].val = graph[n].val;
				}
			}
		}
		if(graph[n].typ == 2) {
			for(int i =0; i<2; i++) {
				if(val[graph[n].cld[(i+1)%2]] == 0) {
					graph[graph[n].cld[i]].val = graph[n].val;
				}
				else {
					graph[graph[n].cld[i]].val = ((graph[n].val/2)<<1) + graph[n].val/2;
				}
			}
		}
		if(graph[n].typ == 3) {
			for(int i =0; i<2; i++) {
				if(val[graph[n].cld[(i+1)%2]] == 0) {
					graph[graph[n].cld[i]].val = graph[n].val;
				}
				else {
					graph[graph[n].cld[i]].val = ((graph[n].val%2)<<1) + graph[n].val/2;
				}
			}
		}
		if(graph[n].typ == 4) {
			graph[graph[n].cld[0]].val = ((graph[n].val%2)<<1) + graph[n].val/2;
		}
		for(int e : graph[n].cld) {
			dfs2(e);
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
		byte[] ret = new byte[5];
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