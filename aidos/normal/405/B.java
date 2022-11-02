import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA {

	public static void main(String[] args){
		new SolutionA().run();
	}
	int n;
	char c[];
	void solve(){
		n = in.nextInt();
		c = in.next().toCharArray();
		int cur=n-1;
		int ans = 0;
		while(cur >= 0){
			int nextL = -1;
			int nextR = -1;
			for(int i = cur; i>= 0; i--){
				if(c[i] == 'L' && nextL == -1) nextL = i;
				if(c[i] == 'R' && nextR == -1) nextR = i;
			}
			if(nextL == -1 && nextR == -1){
				ans += cur+1;
				break;
			}
			else if(nextL == -1){
				ans += nextR;
				break;
			}
			else if(nextR == -1){
				ans += cur - nextL;
				break;
			}
			else {
				if(nextR>nextL){
					ans += nextR - nextL - 1;
					cur = nextL;
				}
				else {
					ans += cur - nextL;
					if((nextL - nextR) %2 ==0) ans++;
					cur = nextR-1;
				}
				
			}
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
	}
}