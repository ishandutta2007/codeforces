import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionA {
    public static void main(String[] args){
        new SolutionA().run();
    }
    int n, k;
    int a[];
    boolean used[];
    void dfs(int x){
        if(used[x]) return;
        used[x] = true;
        if( x == n) return;
        dfs(x + a[x]);
    }
    void solve(){
        n = in.nextInt();
        k = in.nextInt();
        used = new boolean[n+10];
        a = new int[n+5];
        for(int i = 1; i<n; i++)
            a[i] = in.nextInt();
        dfs(1);
        if( used[k]) out.println("YES");
        else out.println("NO");
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