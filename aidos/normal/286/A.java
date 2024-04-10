import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionA {
    public static void main(String[] args){
        new SolutionA().run();
    }
    int n;
    int a[];
    void solve(){
        n = in.nextInt();
        if( n % 4 == 3 || n % 4 == 2){
            out.println(-1);
            return;
        }
        a = new int[n+1];
        int l = 1;
        int r = n;
        while( l<r){
            a[l] = l+1;
            a[l+1] = r;
            a[r] = r - 1;
            a[r-1] = l;
            l+=2;
            r-=2;
        }
        if( l == r) a[l] = l;
        for(int i = 1; i<=n; i++)
            out.print(a[i] + " ");
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