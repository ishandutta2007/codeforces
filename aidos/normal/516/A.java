import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionA {
	public static void main(String[] args) {
		new SolutionA().run();
	}
	
	void solve(){
		int cnt[] = new int[11];
		int n = in.nextInt();
		String x = in.next();
		for(int i = 0; i < n; i++){
			int cur = x.charAt(i) - '0';
			for(int j = 2; j <= cur; j++){
				cnt[j]++;
			}
		}
		StringBuilder sb = new StringBuilder();
		cnt[2]+=2 * cnt[4] + cnt[6];
		cnt[2]+=3 * cnt[8];
		cnt[3] += 2 * cnt[9] + cnt[6];
		cnt[4] = 0;
		cnt[6] = 0;
		cnt[9] = 0;
		while(cnt[7] > 0){
			sb.append('7');
			cnt[5]--;
			cnt[2]-=4;
			cnt[3] -= 2;
			cnt[7]--;
		}
		while(cnt[5] > 0){
			sb.append('5');
			cnt[5]--;
			cnt[2]-=3;
			cnt[3]--;
		}
		while(cnt[3] > 0){
			sb.append('3');
			cnt[3]--;
			cnt[2]--;
		}
		while(cnt[2] > 0){
			sb.append('2');
			cnt[2]--;
		}
		
		out.println(sb.toString());
		
		
	}
	FastScanner in;
	PrintWriter out;
	void run() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);
		solve();
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
		float nextFloat(){
			return Float.parseFloat(next());
		}
		short nextShort(){
			return Short.parseShort(next());
		}
		BigInteger nextBigInteger(){
			return new BigInteger(next());
		}
		BigDecimal nextBigDecimal(){
			return new BigDecimal(next());
		}
		int[] nextIntArray(int n){
			int a[] = new int[n];
			for(int i = 0; i < n; ++i)
				a[i] = Integer.parseInt(next());
			return a;
		}
		long[] nextLongArray(int n){
			long a[] = new long[n];
			for(int i = 0; i < n; ++i)
				a[i] = Long.parseLong(next());
			return a;
		}
	}

}