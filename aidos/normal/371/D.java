import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionB {
	public static void main(String[] args){
		new SolutionB().run();
	}
	
	int next[];
	int a[];
	int cur[];
	int arr[];
	int sz = 0;
	void solve(){
		int n = in.nextInt();
		a = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = in.nextInt();
		next = new int[n];
		cur = new int[n];
		for(int i = 0; i < n; i++)
			next[i] = i+1;
		int m = in.nextInt();
		arr = new int[n];
		for(int i = 0; i < m; i++){
			int k = in.nextInt();
			if( k == 1){
				int st = in.nextInt()-1;
				int ad = in.nextInt();
				sz = 0;
				
				while(st < n && a[st] <= cur[st] + ad){
					ad -= (a[st] - cur[st]);
					arr[sz] = st;
					cur[st] = a[st];
					st = next[st];
					sz++;
				}
				if(st < n){
					cur[st] += ad;
				}
				for(int j = 0; j < sz; j++)
					next[arr[j]] = st;
				//out.flush();
			}
			else {
				out.println(cur[in.nextInt()-1]);
				//out.flush();
			}
		}
		
		
	}
	
	PrintWriter out;
	FastScanner in;
	public void run(){
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);
		solve();
		
		out.close();
	}
	class FastScanner{
		BufferedReader bf;
		StringTokenizer st;
		public FastScanner(InputStream is){
			bf = new BufferedReader(new InputStreamReader(is));
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
		float nextFloat(){
			return Float.parseFloat(next());
		}
		BigInteger nextBigInteger(){
			return new BigInteger(next());
		}
		BigDecimal nextBigDecimal(){
			return new BigDecimal(next());
		}	
		int[] nextArray(int n){
			int x[] = new int[n];
			for(int i = 0; i < n; i++){
				x[i] = Integer.parseInt(next());
			}
			return x;
		}
	}
}