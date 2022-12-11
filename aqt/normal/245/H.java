import java.util.*;
import java.io.*;

public class _0245_H_QueriesForNumberOfPalindromes {

	static char[] s;
	static int num, end;
	static Node tree[];
	
	static class Node{
		int suff, len ,cnt;
		int edge[];
		public Node(int len) {
			this.len = len;
			this.edge = new int[26];
		}
		public Node() {
			this.edge = new int[26];
		}
	}
	
	static void addletter(int p, int i) {
		int idx = end;
		int let = s[p]-'a';
		while(true) {
			int curlen = tree[idx].len;
			if(p-curlen-1 > i-1 && s[p] == s[p-curlen-1]) break;
			else idx = tree[idx].suff;
		}
//		println(" " + tree[num].cnt + " " + p + ' ' + idx);
		if(tree[idx].edge[let] > 0) {
			end = tree[idx].edge[let];
			return;
		}
		end = ++num;
		tree[num].len = tree[idx].len + 2;
		tree[idx].edge[let] = num;
		if(tree[num].len == 1) {
			tree[num].suff = i+1;
			tree[num].cnt = 1;
			return;
		}
//		println(tree[num].len);
		while(true) {
			idx = tree[idx].suff;
			int curlen = tree[idx].len;
//			println("  " + idx + " " + s[p] + " " + s[p-curlen-1]);
			if(s[p] == s[p-curlen-1]) {
				tree[num].suff = tree[idx].edge[let];
//				println(" " + tree[num].suff + " " + tree[num].cnt);
//				flush();
				tree[num].cnt = tree[tree[num].suff].cnt + 1;
				break;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		s = (" " + read()).toCharArray();
		int N = s.length-1;
		int tbl[][] = new int[N+1][N+1];
		tree = new Node[N+5];
		for(int i = 1; i<=N; i++) {
//			println(i);
			for(int j = 1; j<=N+4; j++) tree[j] = new Node();
			tree[i].suff = tree[i+1].suff = i;
			tree[i].len = -1;
			tree[i+1].len = 0;
			tree[i+1].cnt = 1;
			num = end = i+1;
			for(int j = i; j<=N; j++) {
				addletter(j, i);
				tbl[i][j] = tbl[i][j-1] + tree[end].cnt;
			}
		}
		int Q = readInt();
		while(Q -- > 0) println(tbl[readInt()][readInt()]);
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
		byte[] ret = new byte[5001];
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