import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionB {
	public static void main(String[] args) {
		new SolutionB().run();
	}
	int get(char c){
		if(c>='A' && c <='Z') return c - 'A' + 26;
		return c-'a';
	}
	
	void solve(){
		char a[]  =in.next().toCharArray();
		char b[] = in.next().toCharArray();
		int cnta[] = new int[52];
		int cntb[] = new int[52];
		int ans1 = 0;
		int ans2 = 0;
		for(int i = 0;  i<a.length; i++)
			cnta[get(a[i])]++;
		for(int i = 0;  i<b.length; i++)
			cntb[get(b[i])]++;
		for(int i = 0; i < 52; i++){
			int mi = Math.min(cnta[i], cntb[i]);
			cnta[i] -= mi;
			cntb[i] -= mi;
			ans1 += mi;
		}
		for(int i = 26; i < 52; i++){
			int tmp = cnta[i-26];
			cnta[i-26] = cnta[i];
			cnta[i] = tmp;
		}
		for(int i = 0; i < 52; i++){
			int mi = Math.min(cnta[i], cntb[i]);
			cnta[i] -= mi;
			cntb[i] -= mi;
			ans2 += mi;
		}
		out.println(ans1 +" " + ans2);
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