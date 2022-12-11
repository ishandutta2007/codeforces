import java.util.*;
import java.io.*;

public class _0853_B_JuryMeeting {
	
	public static class Query implements Comparable<Query>{
		int time, id, val;
		public Query(int id, int time, int val) {
			this.id = id; this.time = time; this.val = val;
		}
		public int compareTo(Query q) {
			return Integer.compare(this.time, q.time);
		}
	}
	
	public static class Pair{
		int pos, val;
		public Pair(int pos, int val) {this.pos = pos; this.val = val;}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), K = readInt();
		LinkedList<Pair> monoq[] = new LinkedList[N+1]; for(int i = 1; i<=N; i++) monoq[i] = new LinkedList<>();
		PriorityQueue<Query> pq2 = new PriorityQueue<>(), pq1 = new PriorityQueue<>(), pq3 = new PriorityQueue<>();
		for(int i = 1; i<=M; i++) {
			int t = readInt(), fr = readInt(), to = readInt(), c = readInt();
			if(fr == 0) {pq2.add(new Query(to, t, c)); pq3.add(new Query(to, t, c));} else pq1.add(new Query(fr, t, c));
		}
		while(!pq2.isEmpty()) {
			Query q = pq2.poll(); int id = q.id, v = q.val;
			while(!monoq[id].isEmpty() && monoq[id].peekLast().val >= v) monoq[id].removeLast();
			monoq[id].addLast(new Pair(q.time, v));
		}
		long tot = 0, ans = Long.MAX_VALUE, cnt = N; 
		for(int i = 1; i<=N; i++) if(monoq[i].isEmpty()) {println(-1); exit();} else tot += monoq[i].peekFirst().val;
		int val[] = new int[N+1]; Arrays.fill(val, Integer.MAX_VALUE);while(!pq1.isEmpty()) {
			int time = pq1.peek().time; while(!pq1.isEmpty() && pq1.peek().time == time) {
				Query p = pq1.poll(); if(val[p.id] == Integer.MAX_VALUE) {val[p.id] = p.val; tot += val[p.id]; cnt--;} 
				else {tot -= val[p.id]; val[p.id] = Math.min(val[p.id], p.val); tot += val[p.id];}
			}
			while(!pq3.isEmpty() && pq3.peek().time <= time+K) {
				int id = pq3.peek().id, t = pq3.poll().time; 
				if(monoq[id].isEmpty() || monoq[id].peekFirst().pos != t) continue;
				tot -= monoq[id].pollFirst().val; if(monoq[id].isEmpty()) cnt++; else tot += monoq[id].peekFirst().val;
			}
			if(cnt == 0) ans = Math.min(tot, ans);
		}
		println(ans == Long.MAX_VALUE ? -1 : ans); exit();
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