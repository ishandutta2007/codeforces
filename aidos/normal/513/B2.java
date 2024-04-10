import java.io.*;
import java.math.*;
import java.util.*;
 
public class SolutionB {
 
    public static void main(String[] args) {
        new SolutionB().run();
    }
    int n;
    long m;
    boolean used[];
    ArrayList<Integer> arr;
    ArrayList<ArrayList<Integer>> arrx = new ArrayList<ArrayList<Integer>>();
    long fact[];
    int pos[];
    long maxi = 0;
    void go(int p){
    	if(p == n+1){
    		long ans = 0;
    		ArrayList<Integer> arru = new ArrayList<Integer>();
    		for(int i = 1; i<=n; i++){
    			int mi = Integer.MAX_VALUE;
    			for(int j = i; j <=n; j++){
    				mi=Math.min(mi, pos[j]);
    				ans += mi;
    			}
    			arru.add(pos[i]);
    		}
    		if(ans == maxi){
    			arrx.add(arru);
    		}
    	}
    	for(int i = 1; i<=n; i++){
    		if(!used[i]){
    			used[i] = true;
    			pos[p] = i;
    			go(p+1);
    			used[i] = false;
    			
    		}
    	}
    }
    void solve() {
    	n = in.nextInt();
    	m = in.nextLong();
    	arr = new ArrayList<Integer>();
    	used  = new boolean[n+1];
    	fact = new long[55];
    	pos = new int[55];
    	fact[0] = 0;
    	fact[1] = 1;
    	for(int i = 2; i < 53; i++)
    		fact[i] = fact[i-1] * 2;
    	for(int i = 1; i <= n; i++){
    		maxi += i * (n - i + 1);
    	}
    	int cur = 0;
    	for(int i = 1; i <= n; i++){
    		if(used[i]) continue;
    		if(m <= fact[n-i]){
    			used[i] = true;
    			out.print(i + " ");
    		}
    		else {
    			m -= fact[n -i];
    			arr.add(i);
    		}
    	}
    	for(int i = n; i>=1; i--)
    		if(!used[i]) out.print(i + " ");
    	
    	//out.println(-1);
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
 
    void run() {
        in = new FastScanner(System.in);
        out = new PrintWriter(new OutputStreamWriter(System.out));
        solve();
        out.close();
    }
 
    void runIO() {
        try {
            in = new FastScanner(new File("a.in"));
            out = new PrintWriter(new FileWriter(new File("a2.out")));
            solve();
            out.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
 
    class FastScanner {
        BufferedReader bf;
        StringTokenizer st;
 
        public FastScanner(File f) {
            try {
                bf = new BufferedReader(new FileReader(f));
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
 
        public FastScanner(InputStream is) {
            bf = new BufferedReader(new InputStreamReader(is), 32768);
        }
 
        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(bf.readLine());
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        float nextFloat() {
            return Float.parseFloat(next());
        }
 
        String nextLine() {
            try {
                return bf.readLine();
            } catch (Exception ex) {
                ex.printStackTrace();
            }
            return "";
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        BigInteger nextBigInteger() {
            return new BigInteger(next());
        }
 
        BigDecimal nextBigDecimal() {
            return new BigDecimal(next());
        }
 
        int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = Integer.parseInt(next());
            return a;
        }
 
        long[] nextLongArray(int n) {
            long a[] = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = Long.parseLong(next());
            return a;
        }
    }
}