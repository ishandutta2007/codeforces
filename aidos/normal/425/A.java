import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA{

	public static void main(String[] args){
		new SolutionA().run();
	}
	int n;
	int a[];
	int k;
	int get(int l, int r){
		ArrayList<Integer> arr = new ArrayList<Integer>(), arr2 = new ArrayList<Integer>();
		int sum = 0;
		for(int i = 0; i < n; i++){
			if(i >= l && i <= r) {
				arr.add(a[i]);
				sum += a[i];
			}
			else arr2.add(a[i]);
		}
		Collections.sort(arr);
		Collections.sort(arr2);
		int cur = 0;
		int cur2 = arr2.size()-1;
		int x = k;
		while(cur < arr.size() && cur2 >= 0 && x > 0){
			if(arr.get(cur) >= arr2.get(cur2)){
				break;
			}
			sum -= arr.get(cur);
			sum += arr2.get(cur2);
			x--;
			cur++;
			cur2--;
		}
		return sum;
	}
	void solve(){
		n = in.nextInt();
		k = in.nextInt();
		a = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = in.nextInt();
		int ans = -2000;
		for(int i=0; i < n; i++)
			for(int j = i; j < n; j++){
				ans = Math.max(ans, get(i, j));
			}
		out.println(ans);
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