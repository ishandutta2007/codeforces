import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;
 
 
public class TaskC {
	
	public static void main(String[] args) {
		new TaskC().run();
	}
	
	void solve(){
		int n = in.nextInt();
		String s[] = new String[n];
		for(int i = 0; i < n; i++) s[i] = in.next();
		if(s[n-1].compareTo("f") == 0){
			out.println(0);
			return;
		}
		int dp[] = new int[n+2];
		int mod = 1000*1000*1000+7;
		dp[0] = 1;
		for(int i = n-1; i >= 0; i--){	
			if(s[i].compareTo("s") == 0){
				int ss = 0;
				for(int j = 0; j <= n; j++){
					ss += dp[j];
					if(ss>=mod) ss -= mod;
					dp[j] = ss;
				}
			}else{
				for(int j = 0; j < n;j++){
					dp[j] = dp[j+1];
				}
				dp[n] = 0;
			}
		}
		out.println(dp[0]);
	}

	
	FastScanner in;
	PrintWriter out;
	void run() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);
		int tests = 1;//in.nextInt();
		while(tests > 0){
			solve();
			tests--;
		}
		out.close();
	}
	
	class Pair implements Comparable<Pair>{
		Integer x, y;
		public Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
		@Override
		public int compareTo(Pair o) {
			if(x.compareTo(o.x) == 0) return y.compareTo(o.y);
			return x.compareTo(o.x);
		}
		
	}
 
	class FastScanner {
		StringTokenizer st;
		BufferedReader bf;
 
		public FastScanner(InputStream is) {
			bf = new BufferedReader(new InputStreamReader(is));
		}
 
		public FastScanner(File f){
			try{
				bf = new BufferedReader(new FileReader(f));
			}
			catch(IOException ex){
				ex.printStackTrace();
			}
		}
		String next(){
			while(st == null || !st.hasMoreTokens()){
				try{
					st = new StringTokenizer(bf.readLine());
				}
				catch(Exception ex){
					ex.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt(){
			return Integer.parseInt(next());
		}
		long nextLong(){
			return Long.parseLong(next());
		}
		double nextDouble(){
			return Double.parseDouble(next());
		}
		int[] readArray(int n){
			int[] a = new int[n];
			for(int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
	}
 
}