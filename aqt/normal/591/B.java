import java.util.*;
import java.io.*;

public class _0591_B_Rebranding {

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt();
		char arr[][] = new char[26][2]; 
		for(int i = 0; i<26; i++) arr[i][0] = (char) (i+'a');
		String s = readLine();
		for(int i = 1; i<=M; i++) {
			char a = read().charAt(0), b = read().charAt(0);
			for(int j = 0; j<26; j++) {
				arr[j][i%2] = arr[j][(i+1)%2] == a ? b : arr[j][(i+1)%2];
			}
			for(int j = 0; j<26; j++) {
				arr[j][i%2] = arr[j][(i+1)%2] == b ? a : arr[j][i%2];
			}
		}
		for(int i = 0; i<N; i++) print(arr[s.charAt(i)-'a'][M%2]);
		exit();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	static String read() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(read());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(read());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(read());
	}

	static char readCharacter() throws IOException {
		return read().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}

	static void println() throws IOException {
		pr.println();
	}

	static void println(Object o) throws IOException {
		pr.println(o);
	}

	static void print(Object o) throws IOException {
		pr.print(o);
	}

	static void flush() throws IOException {
		pr.flush();
	}

	static void exit() throws IOException {
		br.close();
		pr.close();
		System.exit(0);
	}
}