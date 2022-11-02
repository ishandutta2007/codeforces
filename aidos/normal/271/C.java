import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionC {
    public static void main(String[] args){
        new SolutionC().run();
    }
    void solve(){
        int n = in.nextInt();
        int k = in.nextInt();
        if(n < 3 * k){
            out.println(-1);
            return;
        }
        for(int i = 1; i <= k; i++) out.print(i + " ");
        for(int i = 1; i<= k; i++){
            out.print(i+ " " + i + " ");
        }
        for(int j = 3 * k ; j<n; j++) out.print("1 ");
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