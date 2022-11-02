import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionE {
	public static void main(String[] args) {
		new SolutionE().run();
	}
	boolean flag = false;
	ArrayList<Integer> get1(int x, int col){
		ArrayList<Integer> cur = new ArrayList<Integer>();
		if(x <= 0){
			int y = x - col;
			while(y < x){
				cur.add(y);
				y++;
			}
			return cur;
		}
		col--;
		int l = col/2;
		if(l >= x) l = x-1;
		int r = col-l;
		r = -r;
		while(r <=l){
			cur.add(r);
			r++;
		}
		return cur;
	}
	ArrayList<Integer>  get2(int x, int col){

		ArrayList<Integer> cur = new ArrayList<Integer>();
		if(x >= 0){
			int y = x+1;
			x += col+1;
			while(y < x){
				cur.add(y);
				y++;
			}
			return cur;
		}
		x = -x;
		col--;
		int l = col/2;
		if(l >= x) l = x-1;
		int r = col-l;
		l = -l;
		while(l<=r){
			cur.add(l);
			l++;
		}
		return cur;
	}
	ArrayList<Integer> get3(int l, int r, int col){
		ArrayList<Integer> cur = new ArrayList<Integer>();
		if(r - l <= col) {
			flag = true;
			return cur;
		}
		if(col == 0) return cur;
		if(l >= 0){
			r = l+col;
			l++;
			while( l <= r){
				cur.add(l);
				l++;
			}
			return cur;
		}
		if(r <= 0) {
			l = r - col;	
			while( l < r){
				cur.add(l);
				l++;
			}
			return cur;
		}
		l = -l;
		col--;
		int x = col/2;
		if( x >= l) x = l-1;
		int y = col - x;
		if(y >= r) {
			y = r - 1;
			x = col - y;
		}
		x = -x;
		while(x <= y){
			cur.add(x);
			x++;
		}
		return cur;
	}
	ArrayList<Integer> go(ArrayList<String> arr){
		int n = arr.size();
		int l = 0;
		int r = n-1;
		while(l < n && arr.get(l).equals("?")) l++;
		if(l == n){
			int x = r/2;
			int y = r - x;
			ArrayList<Integer> cur = new ArrayList<Integer>();
			y = -y;
			while(y <= x){
				cur.add(y);
				y++;
			}
			return cur; 
		}
		ArrayList<Integer> cur = new ArrayList<Integer>();
		ArrayList<Integer> x1 = get1(Integer.parseInt(arr.get(l)), l);
		while(r>=0 && arr.get(r).equals("?")) r--;
		for(int c: x1) cur.add(c);
		while(l < r){
			int pr = l+1;
			while(arr.get(pr).equals("?")) pr++;
			x1= get3(Integer.parseInt(arr.get(l)),Integer.parseInt(arr.get(pr)), pr - l - 1);
			cur.add(Integer.parseInt(arr.get(l)));
			for(int c: x1) cur.add(c);
			l = pr;
		}

		cur.add(Integer.parseInt(arr.get(r)));
		x1 = get2(Integer.parseInt(arr.get(r)), n - r - 1);
		for(int c: x1) cur.add(c);
		return cur;
	}
	
	void solve(){
		int n = in.nextInt();
		int k = in.nextInt();
		ArrayList<String> arr[] = new ArrayList[k];
		ArrayList<Integer> a[] = new ArrayList[k];
		for(int i = 0; i < k; i++){
			arr[i] = new ArrayList<String>();
			a[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < n; i++){
			arr[i % k].add(in.next());
		}
		long ans = 0;
		//out.println(arr[0].size());
		for(int i = 0; i < k; i++){
			a[i] = go(arr[i]);
		}
		
		if(flag) out.println("Incorrect sequence");
		else {
			//out.println(a[0].size());
			for(int i = 0;  i<n; i++){
				out.print(a[i % k].get(i/k) + " ");
			}
		}
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