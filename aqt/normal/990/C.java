import java.util.*;
import java.io.*;

public class _990_C {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		int N = Integer.parseInt(br.readLine()), max = 300001; long pos[] = new long[max], neg[] = new long[max], zero = 0; 
		for(int i = 1; i<=N; i++) { 
			String str = br.readLine(); int len = str.length(); char s[] = new char[len];  int cnt = 0; boolean valid = true; 
			for(int j = 0; j<len; j++) s[j] = str.charAt(j);
			for(int j = 0; j<len && valid; j++) if(cnt == 0 && s[j] == ')') valid = false; else if(s[j] == ')') cnt--; else cnt++;
			if(cnt > 0) valid = false; if(valid) {zero++; continue;}
			int op = 0, cl = 0; cnt = 0;
			for(int j = 0; j<len; j++) if(cnt == 0 && s[j] == ')') cl++; else if(s[j] == ')') cnt--; else cnt++; cnt = 0;
			for(int j = len-1; j>=0; j--) if(cnt == 0 && s[j] == '(') op++; else if(s[j] == '(') cnt--; else cnt++;
			if(op >0 && cl > 0) continue;
			if(op >0) pos[op]++; else neg[cl]++;
		}
		long tot = 0; for(int i = 1; i<max; i++) tot += pos[i] * neg[i];
		println(tot + zero*zero); exit();
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static String read() throws IOException {
		byte[] ret = new byte[300005];
		int idx = 0;
		byte c = Read();
		if (c <= ' ') c = Read();
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