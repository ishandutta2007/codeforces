import java.util.*;
import java.io.*;

public class _0359_D_PairOfNumbers {
	
	static int org[], tbl[][], N, logN, pow2[];
	
	public static void build() {
		for(int i = 1; i<=N; i++) tbl[i][0] = org[i];
		for(int i = 1; i<=logN; i++) for(int j = 1; j<=N-(1<<i)+1; j++) tbl[j][i] = gcd(tbl[j][i-1], tbl[j+(1<<(i-1))][i-1]);
	}
	
	public static int query(int l, int r) {
		int k = Integer.numberOfTrailingZeros(Integer.highestOneBit(r-l+1)); 
		return gcd(tbl[l][k], tbl[r-(1<<k)+1][k]);
	}
	
	public static int gcd(int a, int b) {
		return a*b == 0 ? a+b: gcd(b, a%b);
	}
	
	public static void main(String[] args) throws IOException {
		N = readInt(); logN = 20; org = new int[N+1]; tbl = new int[N+1][logN+1];
		for(int i = 1; i<=N; i++) org[i] = readInt(); build();
		int max = -1; int ans[] = new int[N+1], idx = 0;
		for(int i = 1; i<=N; i++) {
			int l = 1, r = i; int lb = i, ub = i;
			while(l <= r) {
				int mid = (l+r)>>1; 
				if(query(mid, i) == org[i]) {lb = mid; r = mid - 1;}
				else l = mid + 1;
			}
			l = i; r = N;
			while(l <= r) {
				int mid = (l+r)>>1; 
				if(query(i, mid) == org[i]) {ub = mid; l = mid + 1;}
				else r = mid - 1;
			}
			if(ub-lb > max) {
				idx = 0; max = ub-lb;
				ans[++idx] = lb;
			}
			else if(ub-lb == max) {
				if(ans[idx] != lb) ans[++idx] = lb;
			}
		}
		println(idx + " " + max); for(int i = 1; i<=idx; i++) print(ans[i] + " ");
		exit();
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