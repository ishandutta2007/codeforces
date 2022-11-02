import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	int a[];
	boolean used[];
	int b[] = {1, 6, 8, 9};
	String cnt;
	boolean go(int x, int t){
		if(x == 4) {
			cnt = "";
			return t == 0;
		}
		for(int i = 0; i < 4; i++){
			if(!used[i]){
				used[i] = true;
				if(go(x+1, (t * 3 + b[i]) % 7)) {
					cnt = (char)('0' + b[i]) + cnt;
					return true;
				}
				used[i] = false;
			}
		}
		return false;
	}
	void solve(){
		char c[] = in.next().toCharArray();
		int n = c.length;
		a = new int[11];
		for(int i = 0; i < n; i++){
			a[c[i] - '0']++;
		}
		for(int i = 0; i < b.length; i++) a[b[i]]--;
		StringBuilder sb = new StringBuilder();
		int cur = 0;
		for(int j = 9; j>0; j--){
			for(int i = 0; i < a[j]; i++) {
				sb.append(j);
				cur = cur * 3 + j;
				cur %= 7;
			}
		}
		used = new boolean[4];
		go(0, cur);
		sb.append(cnt);
		while(a[0]>0){
			sb.append(0);
			a[0]--;
		} 
		out.println(sb.toString());
	}


	class Pair implements Comparable<Pair>{
		int x, y;
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
		@Override
		public int compareTo(Pair o) {
			if(o.x == x) return ((Integer) y).compareTo(o.y); 
			return ((Integer) x).compareTo(o.x);
		}

	}
	FastScanner in;
	PrintWriter out;
	void run(){
		in = new FastScanner(System.in);
		out = new PrintWriter(new OutputStreamWriter(System.out));
		solve();
		out.close();
	}

	void runIO(){
		try{
			in = new FastScanner(new File("expr.in"));
			out = new PrintWriter(new FileWriter(new File("expr.out")));
			solve();
			out.close();
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}
	class FastScanner{
		BufferedReader bf;
		StringTokenizer st;
		public FastScanner(File f){
			try{
				bf = new BufferedReader(new FileReader(f));
			}
			catch(IOException ex){
				ex.printStackTrace();
			}
		}
		public FastScanner(InputStream is){
			bf = new BufferedReader(new InputStreamReader(is));
		}
		String next(){
			while(st == null || !st.hasMoreTokens()){
				try{
					st = new StringTokenizer(bf.readLine());
				}
				catch(IOException ex){
					ex.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt(){
			return Integer.parseInt(next());
		}
		double nextDouble(){
			return Double.parseDouble(next());
		}
		float nextFloat(){
			return Float.parseFloat(next());
		}
		String nextLine(){
			try{
				return bf.readLine();
			}
			catch(Exception ex){
				ex.printStackTrace();
			}
			return "";
		}
		long nextLong(){
			return Long.parseLong(next());
		}
		BigInteger nextBigInteger(){
			return new BigInteger(next());
		}
		BigDecimal nextBigDecimal(){
			return new BigDecimal(next());
		}
		int[] nextIntArray(int n){
			int a[] = new int[n];
			for(int i = 0; i < n; i++)
				a[i] = Integer.parseInt(next());
			return a;
		}
		long[] nextLongArray(int n){
			long a[] = new long[n];
			for(int i = 0; i < n; i++)
				a[i] = Long.parseLong(next());
			return a;
		}
	}
}