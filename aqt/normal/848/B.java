import java.util.*;
import java.awt.PageAttributes;
import java.io.*;

public class _0848_B_RootersSong {
	
	static class Trio implements Comparable<Trio>{
		int x, y, id;
		public Trio(int x, int y) {
			this.x = x; this.y = y;
		}
		public Trio(int x, int y, int id) {
			this.x = x; this.y = y;
			this.id = id;
		}
		public int compareTo(Trio p) {
			return Integer.compare(this.x, p.x);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), W = readInt(), H = readInt();
		Trio ans[] = new Trio[N+1];
		PriorityQueue<Trio> pq = new PriorityQueue<>();
		LinkedList<Trio> llidx[] = new LinkedList[200001];
		LinkedList<Integer> llans[] = new LinkedList[200001];
		for(int i = 0; i<=200000; i++) {
			llidx[i] = new LinkedList<>();
			llans[i] = new LinkedList<>();
		}
		for(int i = 1; i<=N; i++) {
			if(readInt() == 1) {
				int p = readInt(), t = readInt();
//				if(p - t < 0) {
//					ans[i] = new Trio(p, H);
//				}
//				else {
					pq.add(new Trio(p, t, i));
//				}
			}
			else {
				int p = readInt(), t = readInt();
//				if(p - t < 0) {
//					ans[i] = new Trio(W, p);
//				}
//				else {
					llidx[p - t + 100000].add(new Trio(-p, 0, i));
					llans[p - t + 100000].add(-p);
//				}
			}
		}
		for(int i = 0; i<=200000; i++) {
			Collections.sort(llidx[i]);
			Collections.sort(llans[i]);
		}
		while(!pq.isEmpty()) {
			int p = pq.peek().x;
			int idx = pq.peek().x - pq.peek().y + 100000;
			int id = pq.poll().id;
			llidx[idx].add(new Trio(0, 0, id));
			ans[llidx[idx].poll().id] = new Trio(p, H);
		}
		for(int i = 0; i<=200000; i++) {
			while(!llidx[i].isEmpty()) {
				ans[llidx[i].poll().id] = new Trio(W, -llans[i].poll());
			}
		}
		for(int i = 1; i<=N; i++) println(ans[i].x + " " + ans[i].y);
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