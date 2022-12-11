import java.util.*;
import java.io.*;

public class _1020_C_Elections {

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt();
		int party[][] = new int[M+1][N+1];
		int size[] = new int[M+1];
		for(int i = 1; i<=N; i++) {
			int p = readInt(); party[p][++size[p]] = readInt();
		}
		for(int i = 1; i<=M; i++) Arrays.sort(party[i] , 1, size[i]+1);
		int cost[] = new int[N+1], which[] = new int[N+1];
		PriorityQueue<Integer> pq[] = new PriorityQueue[M+1];
		for(int i = 1; i<=M; i++) {pq[i] = new PriorityQueue<>(); for(int j = 1; j<=size[i]; j++) pq[i].add(party[i][j]);}
		for(int k = 1; k<=N; k++) {
			int best = 1, val = Integer.MAX_VALUE;
			for(int i = 1; i<=M; i++) {
				if(!pq[i].isEmpty() && pq[i].peek() < val) {
					val = pq[i].peek(); best = i;
				}
			}
			cost[k] = pq[best].poll(); which[k] = best; 
		}
		long ans = Long.MAX_VALUE;
		int sz = Math.max(size[1], 1);
		for(int i = sz; i<=N; i++) {
			int szrn = size[1]; long tot = 0; 
			int idx[] = new int[M+1]; 
			for(int j = 2; j<=M; j++) {
				while(size[j]-idx[j] >= i) {
					tot += party[j][++idx[j]];
					szrn++;
				}
			}
			for(int j = 1; j<=N && szrn < i; j++) {
				if(which[j] == 1) continue;
				if(idx[which[j]] != size[which[j]] && party[which[j]][idx[which[j]]+1] == cost[j]) {
					tot += cost[j]; szrn++; idx[which[j]]++;
				}
			}
			ans = Math.min(tot, ans);
		}
		println(ans);
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