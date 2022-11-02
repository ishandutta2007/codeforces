import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionD {
	public static void main(String[] args){
		new SolutionD().run();
	}
	int n;
	int a[];
	int b[];
	void solve(){
		n = in.nextInt();
		b = new int[n];
		a = in.nextArray(n);
		SegmentTree st = new SegmentTree(0, n-1);
		for(int i = 0; i < n; i++){
			b[i] += st.sum(a[i]) - 1;
			st.upd(a[i]);
		}
		a = in.nextArray(n);
		st = new SegmentTree(0, n-1);
		for(int i = 0; i < n; i++){
			b[i] += st.sum(a[i]) - 1;
			st.upd(a[i]);
		}
		
		for(int i = n-1; i>0; i--){
			int x = b[i]/(n - i);
			b[i-1] += x;
			b[i] %= (n - i);
		}
		b[0] %= n;
		st = new SegmentTree(0, n-1);
		//for(int i = 0; i < n; i++)
			//out.println("b[" + i + "] = " + b[i]);
		
		for(int i = 0; i < n; i++){
			int x = st.get(b[i]);
			out.print(x);
			out.print(' ');
			st.upd(x);
		}
	}
	class SegmentTree{
		SegmentTree left, right;
		int lx, rx;
		int sum;
		public SegmentTree(int l, int r){
			lx = l;
			rx = r;
			if(l != r){
				int mid = (l+r)>>1;
				left = new SegmentTree(l, mid);
				right = new SegmentTree(mid+1, r);
				sum = left.sum + right.sum;
			}else sum = 1;
		}
		int get(int k){
			if(lx == rx) return lx;
			if(left.sum > k) return left.get(k);
			return right.get(k - left.sum);
		}
		int sum(int k){
			if(lx==rx) return sum;
			int mid = (lx + rx)>>1;
			if(mid >= k) return left.sum(k);
			return left.sum + right.sum(k);
		}
		void upd(int k){
			if(lx == rx){
				sum = 0;
				return;
			}
			int mid = (lx + rx) >> 1;
			if(mid >= k) left.upd(k);
			else right.upd(k);
			sum = left.sum + right.sum;
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