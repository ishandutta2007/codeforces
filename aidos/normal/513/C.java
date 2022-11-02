import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionC{

	public static void main(String[] args){
		new SolutionC().run();
	}
	long ff[];
	void solve(){

		int n = in.nextInt();
		int l[] = new int[n];
		int r[] = new int[n];
		ff = new long[n];
		for(int i = 0; i<n; i++){
			l[i] = in.nextInt();
			r[i] =in.nextInt();
		}
		double ansall = 0;
		for(int i = 10000; i >0; i--){
			for(int j = 0; j < n; j++){
				if(i>=r[j]) continue;
				double ans = 0;
				for(int k = 1; k < (1<<n); k++){
					if(((1 << j) &k )> 0) continue;
					double cur = 1;
					boolean ok = true;
					for(int t = 0; t < n; t++){
						if(((1 << t) & k) >0){
							if(l[t] > i || r[t] < i) ok = false;
						}
						else if(t!=j){
							if(l[t] > i) ok = false;
							else if(r[t] >= i) cur *= (i - l[t]);
							else cur *= (r[t] - l[t] + 1);
						}
					}
					if(ok) ans += cur;
				}
				if(l[j] > i){
					double xx = (r[j] - l[j] + 1) * ans * i;
					for(int x = 0; x < n; x++){
						double tt = (r[x] - l[x] + 1);
								xx/=tt;
					}
					ansall += xx;
				}
				else {
					double xx = (r[j] - i) * ans *i;;
					for(int x = 0; x < n; x++){
						double tt = (r[x] - l[x] + 1);
							xx/=tt;
					}
					ansall+=xx;
				}
			}
			double ans = 0;
			for(int k = 1; k < (1<<n); k++){
				double cur = 1;
				boolean ok = true;
				int cnt = 0;
				for(int t = 0; t < n; t++){
					if(((1 << t) & k) >0){
						if(l[t] > i || r[t] < i) ok = false;
						cnt++;
					}
					else{
						if(l[t] >= i) ok = false;
						else if(r[t] >= i) cur *= (i - l[t]);
						else cur *= (r[t] - l[t] + 1);
					}
				}
				if(ok && cnt > 1) ans += cur * i;
			}
			double xx = ans;
			for(int x = 0; x < n; x++){
				double tt = (r[x] - l[x] + 1);
				xx/=tt;
			}
			ansall+=xx;
		}
		
		out.printf("%.12f", ansall);
	}
	class Pair implements Comparable<Pair> {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pair o) {
			if (o.x == x)
				return ((Integer) y).compareTo(o.y);
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
			bf = new BufferedReader(new InputStreamReader(is), 32768);
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