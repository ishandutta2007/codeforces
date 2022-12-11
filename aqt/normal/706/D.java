import java.util.*;
import java.io.*;

public class _0706_D_VasiliysMultiset {

	static class Node{
		int val, dep; Node one, zero;
		public Node(int dep) {
			this.dep = dep;
		}
	}
	
	public static void main(String[] args) throws IOException {
		int Q = readInt();
		Node rt = new Node(30);
		Node crnt = rt;
		crnt.val++;
		for(int d = 29; d>=0; d--) {
			crnt = crnt.zero = new Node(d);
			crnt.val++;
		}
		while(Q-- > 0) {
			char cmd = read().charAt(0);
			int x = readInt();
			if(cmd == '+') {
				crnt = rt;
				rt.val++;
				for(int d = 29; d>=0; d--) {
					if(((1<<d)&x) == 0) {
						if(crnt.zero == null) crnt.zero = new Node(d);
						crnt = crnt.zero; 
						crnt.val++;
					}
					else {
						if(crnt.one == null) crnt.one = new Node(d);
						crnt = crnt.one; 
						crnt.val++;
					}
				}
			}
			else if(cmd == '-') {
				crnt = rt;
				rt.val--;
				for(int d = 29; d>=0; d--) {
					if(((1<<d)&x) == 0) {
						if(crnt.zero == null) crnt.zero = new Node(d);
						crnt = crnt.zero; 
						crnt.val--;
					}
					else {
						if(crnt.one == null) crnt.one = new Node(d);
						crnt = crnt.one; 
						crnt.val--;
					}
				}
			}
			else {
				crnt = rt;
				int ans = 0;
				for(int d = 29; d>=0; d--) {
					if(((1<<d)&x) == 0) {
						if(crnt.one == null || crnt.one.val == 0) {
							crnt = crnt.zero;
						}
						else {
							crnt = crnt.one;
							ans += (1<<d);
						}
					}
					else {
						if(crnt.zero == null || crnt.zero.val == 0) {
							crnt = crnt.one;
						}
						else {
							crnt = crnt.zero;
							ans += (1<<d);
						}
					}
				}
				println(ans);
			}
		}
		exit();
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	
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