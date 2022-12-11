import java.util.*;
import java.io.*;

public class _817_E_ChoosingTheCommander {

	public static class Node{
		Node left, right; int cnt;
		public Node() {this.cnt= 0; }
	}
	
	static Node rt = new Node();
	
	public static int query(Node n, int dep, int val, int num, int lim) {
//		println(val + " " + (val + (1<<(dep+1))-1) + " " + num);
		if(n == null || val >= lim) return 0; 
		if(val + (1<<(dep+1))-1 < lim) return n.cnt; 
		if((num&(1<<dep)) != 0) return query(n.left, dep-1, val, num, lim) + query(n.right, dep-1, val + (1<<dep), num, lim);
		else return query(n.left, dep-1, val + (1<<dep), num, lim) + query(n.right, dep-1, val, num, lim);
	}
	
	public static Node add(Node n, int num, int dep) {
//		if(n != null) println(n.cnt); flush();
		if(dep == -2) return null; if(n == null) n = new Node(); n.cnt++;
		if((num&(1<<dep)) != 0) n.left = add(n.left, num, dep-1); else n.right = add(n.right, num ,dep-1); return n;
	}
	
	public static Node remove(Node n, int num, int dep) {
//		if(dep != -1) println(n.cnt); flush();
		if(dep == -2) return null; n.cnt--;
		if((num&(1<<dep)) != 0) n.left = remove(n.left, num, dep-1); else n.right = remove(n.right, num ,dep-1); return n;
	}
	
	public static void main(String[] args) throws IOException {
		int Q = readInt(); rt.cnt = 0; for(int q = 0; q<Q; q++) {
			int cmd = readInt(); 
			if(cmd == 1) rt = add(rt, readInt(), 29);
			else if(cmd == 2) rt = remove(rt, readInt(), 29);
			else println(query(rt, 29, 0, readInt(), readInt()));
			flush();
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