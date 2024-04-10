import java.util.*;
import java.io.*;

public class _0456_D_ALotOfGames {

	public static class Node{
		boolean lose, win, leaf;
		Node edge[];
		public Node() {
			this.edge = new Node[26];
			this.leaf = true;
		}
	}

	public static void solve(Node crnt) throws IOException{
		if(crnt.leaf) crnt.lose = true;
		else {
			for(int i = 0; i<26; i++) if(crnt.edge[i] != null) {
				solve(crnt.edge[i]); 
				if(!crnt.edge[i].win) crnt.win = true;
				if(!crnt.edge[i].lose) crnt.lose = true;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt(); Node rt = new Node();
		for(int i = 1; i<=N; i++) {
			Node crnt = rt; String s = read();
			for(int j = 0; j<s.length(); j++) {
				if(crnt.edge[s.charAt(j)-'a'] == null) {
					crnt.edge[s.charAt(j)-'a'] = new Node();
					crnt.leaf = false;
				}
				crnt = crnt.edge[s.charAt(j)-'a'];
			}
		}
		solve(rt); 
		if(rt.win && rt.lose) println("First");
		else if(rt.win && K%2 == 0) println("Second");
		else if(rt.lose) println("Second");
		else if(!rt.lose && !rt.win) println("Second");
		else println("First");
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