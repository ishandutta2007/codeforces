import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;
 
 
public class Main {
	
	public static void main(String[] args) {
		new Main().run();
	}
	int a[] = new int[35];
	void solve(){
		int n = in.nextInt();
		int m = in.nextInt();
		for(int i = 0; i < m; i++){
			int u = in.nextInt()-1;
			int v = in.nextInt()-1;
			a[u] |= (1<<v);
			a[v] |= (1<<u);
		}
		int c = 0;
		for(int i = 0 ; i<n;i++){
			if((a[i]|(1<<i)) == (1<<n)-1){
				c++;
			}
		}
		if(c == n){
			out.println(0);
			return;
		}
		int ans = (1<<n)*2-1;
		boolean used[] = new boolean[1<<n];
		used[0] = true;
		for(int i = 0; i < n; i++)
			used[(1<<i)] = true;
		for(int i = 1; i < (1<<n); i++){
			for(int j = 0; j < n; j++){
				if((i&(1<<j)) > 0 && used[i^(1<<j)] && (a[j] & i) > 0) used[i] = true;
			}
			
		}
		int cc = n + 1;
		for(int i = 0; i < (1<<n); i++){
			if(!used[i]) continue;
			int cnt = 0;
			int M = 0;
			for(int j = 0; j < n; j++){
				if((i&(1<<j)) > 0){
					M |= a[j];
					cnt++;
				}
			}
			if(cnt < cc && (i|M) == (1<<n)-1){
				cc = cnt;
				ans = i;
			}
		}
		out.println(cc);
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++){
			if((ans&(1<<i)) > 0){
				sb.append(' ');
				sb.append(new Integer(i+1).toString());
			}
		}
		out.println(sb.substring(1));
		
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