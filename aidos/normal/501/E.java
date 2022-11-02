import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionE {
	public static void main(String[] args){
		new SolutionE().run();
	}
	int n;
	int cnt[];
	int a[];
	int b[];
	int m = 0;
	boolean check(int val){
		cnt = new int[n];
		for(int i = 0; i <= val; i++)
			cnt[b[i]]++;
		for(int i = 0; i<m; i++){
			if(i <= val || m - i - 1 > i) continue;
			if(m - i - 1 <= val){
				if(cnt[b[i]] <= 0) return false;
				cnt[b[i]]--;
			}
			else if(b[m-i-1] != b[i]){
				return false;
			}
		}
		return true;
	}
	int solve2(){
		int ans=m-1;
		int l = 0;
		int r = m-1;
		while( l<=r){
			int mid = (l+r)/2;
			if(check(mid)){
				ans = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		return ans;
	}
	void solve(){
		n = in.nextInt();
		a = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = in.nextInt()-1;
		cnt = new int[n];
		for(int i = 0; i < n; i++)
			cnt[a[i]]++;
		int x = 0;
		for(int i = 0; i < n; i++) x += cnt[i] % 2;
		if(x > 1) {
			out.println(0);
			return;
		}
		int cur = 0;
		while(cur < n && a[cur] == a[n - cur-1]) cur++;
		if( cur == n){
			out.println(n * 1L * (n + 1)/2);
			return;
		}
		m = n - 2 * cur;
		b = new int[m];
		for(int i = cur; i<m+cur; i++)
			b[i-cur] = a[i];
		int y = solve2();
		for(int i = 0; i < m/2; i++){
			b[i] ^= b[m-i-1];
			b[m-i-1] ^= b[i];
			b[i] ^= b[m-i-1];
		}
		int z = solve2();
		out.println((cur + 1) * 1L * ( m - y + cur) + (cur + 1) * 1L * (m - 1 - z));
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