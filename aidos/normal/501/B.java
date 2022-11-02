import java.io.*;
import java.math.*;
import java.util.*;



public class SolutionB {
	public static void main(String[] args){
		new SolutionB().run();
	}
	String[]a;
	String[]b;
	int p[];
	boolean used[];
	HashMap<String, Integer> hm;
	void solve(){
		int q = in.nextInt();
		a = new String[q];
		b = new String[q];
		p = new int[q];
		used = new boolean[q];
		Arrays.fill(p, -1);
		hm = new HashMap<String, Integer>();
		for(int i = 0; i < q; i++){
			a[i] = in.next();
			hm.put(a[i], i);
			b[i] = in.next();
		}
		int cnt = 0;
		for(int i = 0; i < q; i++){
			if(used[i]) continue;
			String last = a[i];
			int id=-1;
			while(hm.containsKey(last)){
				id = hm.get(last);
				used[id] = true;
				last = b[id];
			}
			p[i] = id;
			cnt++;			
		}
		out.println(cnt);
		for(int i=0; i < q; i++){
			if(p[i] == -1) continue;
			out.println(a[i] + " " + b[p[i]]);
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