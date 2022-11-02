import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionD {
    public static void main(String[] args){
        new SolutionD().run();
    }
    ArrayList<Integer> arr[];
    int n;
    int mod = 1000000007;
    int col[];
    long dp[][];
    void dfs(int x){
        dp[x][0] = col[x];
        dp[x][1] = 1-col[x];
        for(int c: arr[x]) {
            dfs(c);
            dp[x][0] = (dp[x][1] *  dp[c][0] + dp[x][0] * dp[c][0] + dp[x][0] * dp[c][1]) % mod;
            dp[x][1] = ((dp[c][0] + dp[c][1]) * 1L * dp[x][1]) % mod; 
        }
    }
    void solve(){
        n = in.nextInt();
        arr = new ArrayList[n];
        dp = new long[n][2];
        for(int i = 0; i < n; i++) arr[i]=new ArrayList<Integer>();
        for(int i = 0, x; i < n-1; i++){
            x = in.nextInt();
            arr[x].add(i+1);
        }
        col = in.nextArray(n);
        dfs(0);
        out.println(dp[0][0]);
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