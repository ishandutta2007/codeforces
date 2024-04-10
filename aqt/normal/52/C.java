import java.util.*;
import java.io.*;

public class _0052_C_CircularRMQ {
	
	public static class node{
		int min, lazy;
		public node() {}
	}
	
	static node seg[] = new node[800005];
	static int org[] = new int[200005];
	
	static void build(int l, int r, int idx) {
		seg[idx] = new node();
		if(l == r) {seg[idx].min = org[l]; return;}
		int mid = (l+r)/2;
		build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
		seg[idx].min = Math.min(seg[2*idx].min, seg[2*idx+1].min);
	}
	
	public static int query(int crntl, int crntr, int l, int r, int idx) {
		if(l == crntl && r == crntr) return seg[idx].min;
		if(seg[idx].lazy != 0) push(idx);
		int mid = (crntl + crntr)/2;
		if(l > mid) return query(mid+1, crntr, l, r, 2*idx+1);
		else if(r <= mid) return query(crntl, mid, l, r, 2*idx);
		else return Math.min(query(crntl, mid, l, mid, 2*idx), query(mid+1, crntr, mid+1, r, 2*idx+1));
	}
	
	static void update(int crntl, int crntr, int l, int r, int idx, int val) {
		if(l == crntl && r == crntr) {
			seg[idx].min += val;
			seg[idx].lazy += val;
			return;
		}
		if(seg[idx].lazy != 0) push(idx);
		int mid = (crntl + crntr)/2;
		if(l > mid) update(mid+1, crntr, l, r, 2*idx+1, val);
		else if(r <= mid) update(crntl, mid, l, r, 2*idx, val);
		else {update(crntl, mid, l, mid, 2*idx, val); update(mid+1, crntr, mid+1, r, 2*idx+1, val);}
		
		seg[idx].min = Math.min(seg[2*idx].min, seg[2*idx+1].min);
	}

	static void push(int idx) {
		seg[2*idx].min += seg[idx].lazy; seg[2*idx+1].min += seg[idx].lazy;
		seg[2*idx].lazy += seg[idx].lazy; seg[2*idx+1].lazy += seg[idx].lazy;
		seg[idx].lazy = 0;
	}

	public static void main(String[] args) throws IOException {
		int N = readInt();
		for(int i = 0; i<N; i++) org[i] = readInt();
		build(0, N-1, 1);
		int Q = readInt();
		for(int q = 0; q<Q; q++) {
			int l = readInt(), r = readInt();
			if(st.hasMoreTokens()) {
				int val = readInt();
				if(l > r) {
					update(0, N-1, l, N-1, 1, val);
					update(0, N-1, 0, r, 1, val);
				}
				else update(0, N-1, l, r, 1, val);
			}
			else {
				if(l > r) println(Math.min(query(0, N-1, l, N-1, 1), query(0, N-1, 0, r, 1)));
				else println(query(0, N-1, l, r, 1));
			}
		}
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