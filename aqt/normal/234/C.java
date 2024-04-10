import java.util.*;
import java.io.*;

public class _234_C_Weather {

	public static void main(String[] args) throws IOException, FileNotFoundException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
				BufferedReader br = new BufferedReader(new FileReader("input.txt"));
				PrintWriter pr = new PrintWriter(new FileWriter("output.txt"));
		MyConsole mc = new MyConsole(br, pr);
		int N = mc.readInt(); int arr[] = new int[N+1]; for(int i = 1; i<=N; i++) arr[i] = mc.readInt();
		int pos[] = new int[N+2]; for(int i = N;i>0; i--) pos[i] = pos[i+1] + (arr[i] <= 0 ? 1 : 0);
		int neg[] = new int[N+1]; for(int i = 1; i<=N; i++) neg[i] = neg[i-1] + (arr[i] >= 0 ? 1 : 0);
		int min = Integer.MAX_VALUE; for(int i = 1; i<N; i++) min = Math.min(min, pos[i+1] + neg[i]); mc.println(min);
		mc.exit();
	}

	public static class MyConsole {
		BufferedReader br;
		PrintWriter pr;

		StringTokenizer st;

		public MyConsole(BufferedReader br, PrintWriter pr) {
			this.br = br;
			this.pr = pr;
		}

		String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine().trim());
			return st.nextToken();
		}

		long readLong() throws IOException {
			return Long.parseLong(next());
		}

		float readFloat() throws IOException {
			return Float.parseFloat(next());
		}

		boolean readBool() throws IOException {
			return Boolean.parseBoolean(next());
		}

		short readShort() throws IOException {
			return Short.parseShort(next());
		}

		byte readByte() throws IOException {
			return Byte.parseByte(next());
		}

		int readInt() throws IOException {
			return Integer.parseInt(next());
		}

		double readDouble() throws IOException {
			return Double.parseDouble(next());
		}

		char readChar() throws IOException {
			return next().charAt(0);
		}

		String readLine() throws IOException {
			return br.readLine().trim();
		}

		void print(Object o) {
			pr.print(o);
		}

		void println(Object o) {
			pr.println(o);
		}

		void flush() {
			pr.flush();
		}

		void println() {
			pr.println();
		}

		void exit() throws IOException {
			br.close();
			pr.close();
			System.exit(0);
		}
	}
}