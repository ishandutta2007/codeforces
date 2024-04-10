import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	String s[];
	char c[][];
	ArrayList<Integer> arr[], cur;
	int used[];
	boolean dfs(int x){
		used[x] = 1;
		boolean ok = false;
		for(int to: arr[x]){
			
			if(used[to] == 0) {
				if(dfs(to)) return true;
			}
			else if(used[to] == 1){
				return true;
			}
		}
		cur.add(x);
		used[x] = 2;
		return false;
	}
	char tt[];
	void solve(){
		int n = in.nextInt();
		s = new String[n];
		cur =new ArrayList<Integer>();
		for(int i = 0; i < n; i++)
			s[i] = in.next();
		c = new char[n][];
		for(int i = 0; i < n; i++){
			c[i] = s[i].toCharArray();
		} 
		arr = new ArrayList[27];
		for(int i = 0; i<26; i++)
			arr[i] = new ArrayList<Integer>();
		used = new int[27];
		for(int i = 0; i < n; ++i){
			for(int j = i+1; j < n; j++){
				int t = Math.min(s[i].length(), s[j].length());
				int cnt = 0;
				for(int k = 0; k < t; k++){
					if(c[i][k] == c[j][k]){
						cnt++;
						continue;
					}
					arr[c[i][k] - 'a'].add(c[j][k] - 'a');
					break;
				}
				if(cnt == t && c[i].length > c[j].length){
					out.println("Impossible");
					return;
				}
			}
		}
		for(int i = 0; i<26; i++){
			if(used[i] == 0){
				if(dfs(i)){
					out.println("Impossible");
					return;
				}
			}
		}
		tt = new char[27];
		char d = 'z';
		int cnt = 25;
		for(int i = 25; i>=0; i--){
			out.print((char)('a' +cur.get(i)));
		}
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
		char nextChar(){
			return next().charAt(0);
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