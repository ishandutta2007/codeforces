import java.util.*;
import java.io.*;

public class ModularExponential {

	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt();
		if(n <= 28) {
			println(m%(1<<n));
		}
		else println(m);
		exit();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static float readFloat() throws IOException {
		return Float.parseFloat(next());
	}

	static boolean readBoolean() throws IOException {
		return Boolean.parseBoolean(next());
	}

	static short readShort() throws IOException {
		return Short.parseShort(next());
	}

	static byte readByte() throws IOException {
		return Byte.parseByte(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readCharacter() throws IOException {
		return next().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}

	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	static void print(String s) {
		pr.print(s);
	}

	static void print(int s) {
		pr.print(s);
	}

	static void print(long s) {
		pr.print(s);
	}

	static void print(boolean s) {
		pr.print(s);
	}

	static void print(short s) {
		pr.print(s);
	}

	static void print(byte s) {
		pr.print(s);
	}

	static void print(double s) {
		pr.print(s);
	}

	static void print(char s) {
		pr.print(s);
	}

	static void print(float s) {
		pr.print(s);
	}

	static void println(String s) {
		pr.println(s);
	}

	static void println(int s) {
		pr.println(s);
	}

	static void println(long s) {
		pr.println(s);
	}

	static void println(boolean s) {
		pr.println(s);
	}

	static void println(short s) {
		pr.println(s);
	}

	static void println(byte s) {
		pr.println(s);
	}

	static void println(double s) {
		pr.println(s);
	}

	static void println(char s) {
		pr.println(s);
	}

	static void println(float s) {
		pr.println(s);
	}

	static void flush() {
		pr.flush();
	}

	static void exit() throws IOException {
		br.close();
		pr.close();
		System.exit(0);
	}
}