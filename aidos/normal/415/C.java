import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionC {
	public static void main(String[] args){
		try{
			new SolutionC().run();
			//new SolutionC().runIO();
		}
		catch(Exception ex){
			ex.printStackTrace();
		}
	}
	void solve(){
		int n = in.nextInt();
		int k = in.nextInt();
		int y = n/2;
		if( k < y){
			out.println(-1);
			return;
		}
		if( n == 1 && k != 0){
			out.println(-1);
			return;
		}
		int last = 1;
		for(int i = 0; i<y; i++){
			int z = k/(y - i);
			int t1 = (last + z - 1)/z;
			t1 *= z;
			int t2 = t1 + z;

			out.print(t1);
			out.print(' ');
			out.print(t2);
			out.print(' ');
			last = t2 + 1;
			k-=z;
		}
		if(n% 2 == 1) out.println(last);
	}
	PrintWriter out;
	FastScanner in;
	public void run(){
		try{
			in = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			out.close();
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}
	public void runIO(){
		try{
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));
			solve();
			out.close();
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}

	class FastScanner{
		BufferedReader bf;
		StringTokenizer st;
		public FastScanner(File is){
			try{
				bf = new BufferedReader(new FileReader(is));
			}catch(Exception ex){
				ex.printStackTrace();
			}
		}
		public FastScanner(InputStream is){
			try{
				bf = new BufferedReader(new InputStreamReader(is));
			}catch(Exception ex){
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