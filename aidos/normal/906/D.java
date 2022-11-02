import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;
 
 
public class Main {
	
	public static void main(String[] args) {
		new Main().run();
	}
	int phi(int n){
		int res = n;
		for(int i = 2; i * i <= n; i++){
			if(n % i == 0){
				while(n % i == 0){
					n/=i;
				}
				res = res - res/i;
			}
		}
		if(n > 1) res = res - res/n;
		return res;
	}
	int p[] = new int[155];
	long binpow(long a, long b, long mod){
		long res = 1;
		while(b>0){
			if(b%2==1){
				res = Math.min(res*a, res*a % mod+mod);
			}
			a = Math.min(a*a, a*a%mod+mod);
			b/=2;
		}
		return res;
	}
	void solve(){
		int n = in.nextInt();
		int m = in.nextInt();
		int sz = 1;
		p[0] = m;
		int a[] = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = in.nextInt();
		while(p[sz-1] != 1){
			p[sz] = phi(p[sz-1]);
			sz++;
		}
		p[sz] = 1;
		sz++;
		int q = in.nextInt();
		for(int i = 0; i < q; i++){
			int l = in.nextInt();
			int r = in.nextInt();
			l--;
			if(l+sz<r) r = l+sz;
			r--;
			long st = 1;
			while(r>=l){
				if(p[r-l] == 1){
					st = 1;
					r--;
				}else{
					st = binpow(a[r], st, p[r-l]);
					r--;
				}
			}
			out.println(st%m);
		}
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