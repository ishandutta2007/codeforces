import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionC {
	public static void main(String[] args){
		new SolutionC().run();
	}
	long a[];
	void solve(){
		a = new long[3];
		for(int i = 0; i < 3; i++) a[i] = in.nextInt();
Arrays.sort(a);
		if( a[2] > 2 *(a[0] + a[1])){
			out.println(a[0] + a[1]);
			return;
		}
		out.println((a[0] + a[1] + a[2])/3);
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
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new FileWriter(new File("a.out")));
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
	}
}