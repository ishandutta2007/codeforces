import java.util.*;
import java.io.*;

public class _0803_F_CoprimeSubsequences {

	public static void main(String[] args) throws IOException {
		int N = readInt(), maxN = 100000, MOD = 1000000007;
		boolean seive[] = new boolean[maxN+1];
		seive[1] = seive[0] = true;
		ArrayList<Integer> prime = new ArrayList<>();
		for(int i = 2; i<=maxN; i++) if(!seive[i]) {
			prime.add(i);
			for(int j = 2*i; j<=maxN; j+=i) seive[j] = true;
		}
		int cnt[] = new int[maxN+1];
		cnt[1] = 2;
		for(int q : prime) {
			for(int i= maxN/q; i>=1; i--) {
				if(cnt[i] == 0) continue;
				cnt[i*q] = cnt[i]+1;
			}
		}
		for(int i = 2; i<=maxN; i++) if(cnt[i] == 0) cnt[i] = -1;
		long pow[] = new long[N+1];
		pow[0] = 1;
		for(int i =1; i<=N; i++) pow[i] = (pow[i-1]*2)%MOD;
		for(int i= 0; i<=N; i++) pow[i] = (pow[i]-1+MOD)%MOD;
		int count[] = new int[maxN+1];
		for(int i = 1; i<=N; i++) {
			int n = readInt();
			for(int j = 1; j<=Math.sqrt(n); j++) {
				if(n%j == 0) {
					count[n/j]++;
					if(n/j != j) count[j]++;
				}
			}
		}
		long tot = 0;
		for(int i = 1; i<=maxN; i++) {
			if(cnt[i] == -1) continue;
			if(cnt[i]%2 == 0) {
				tot = (tot + pow[count[i]])%MOD;
			}
			else {
				tot = ((tot - pow[count[i]])%MOD + MOD)%MOD;
			}
		}
		println(tot);
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