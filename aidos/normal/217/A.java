	import java.io.*;
	import java.math.*;
	import java.util.*;
	
	public class SolutionB{
	
		public static void main(String[] args){
			new SolutionB().run();
		}
		int a[], b[];
		int p[];
		ArrayList<Integer> arr[];
		int find_set(int v){
			if(p[v] == v) return v;
			return p[v] = find_set(p[v]);
		}
		void solve(){
			int n = in.nextInt();
			a = new int[n];
			b = new int[n];
			p = new int[n];
			for(int i = 0; i < n; i++){
				p[i] = i;
				a[i] = in.nextInt();
				b[i] = in.nextInt();
			}
			for(int i = 0; i < n; i++){
				for(int j = 0; j < i; j++){
					if(a[i] == a[j] || b[i] == b[j]){
						int x = find_set(i);
						int y = find_set(j);
						if(x != y) p[x] = y;
					}
				}
			}
			int cnt = 0;
			for(int i = 1; i < n; i++){
				int x = find_set(i-1);
				int y = find_set(i);
				if(x != y){
					cnt++;
					p[x] = y;
				}
			}
			out.println(cnt);
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
		}
	}