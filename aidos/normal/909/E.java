import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;
 
 
public class TaskE {
	
	public static void main(String[] args) {
		new TaskE().run();
	}
	
	void solve(){
		int n = in.nextInt();
		int m = in.nextInt();
		int []a = in.readArray(n);
		int []in_deg = new int[n];
		int []out_deg = new int[n];
		ArrayList<Integer> []g = new ArrayList[n];
		ArrayList<Integer> []gr = new ArrayList[n];
		for(int i = 0; i < n; i++){
			g[i] = new ArrayList<>();
			gr[i] = new ArrayList<>();
		}
		for(int i = 0; i < m; i++){
			int x = in.nextInt();
			int y = in.nextInt();
			g[x].add(y);
			gr[y].add(x);
			in_deg[y]++;
			out_deg[x]++;
		}
		Stack<Integer> st = new Stack<>();
		Stack<Integer> st2 = new Stack<>();
		
		for(int i = 0; i < n; i++){
			if(out_deg[i] == 0){
				if(a[i] == 1) st.add(i);
				else st2.add(i);
			}
		}
		int cnt = 0;
		while(st.size()>0 || st2.size()>0){
			if(st2.size() > 0){
				int x = st2.pop();
				for(int y: gr[x]){
					out_deg[y]--;
					if(out_deg[y] == 0){
						if(a[y] == 1) st.add(y);
						else st2.add(y);
					}
				}
			}else{
				Stack<Integer> st3 = new Stack<>();
				while(st.size()>0){
					int x = st.pop();
					for(int y: gr[x]){
						out_deg[y]--;
						if(out_deg[y] == 0){
							if(a[y] == 1) st.add(y);
							else st2.add(y);
						}
					}
				}
				cnt++;
			}
		}
		out.println(cnt);
	}

	
	FastScanner in;
	PrintWriter out;
	void run() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);
		int tests = 1;//in.nextInt();
		while(tests > 0){
			solve();
			tests--;
		}
		out.close();
	}
	
	class Pair implements Comparable<Pair>{
		Integer x, y;
		public Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
		@Override
		public int compareTo(Pair o) {
			if(x.compareTo(o.x) == 0) return y.compareTo(o.y);
			return x.compareTo(o.x);
		}
		
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
		int[] readArray(int n){
			int[] a = new int[n];
			for(int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
	}
 
}