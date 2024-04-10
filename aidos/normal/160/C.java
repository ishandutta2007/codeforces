import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionC {
    public static void main(String[] args){
        new SolutionC().run();
    }
    int n;
    long k;
    int a[];
    void solve(){
        n = in.nextInt();
        k = in.nextLong();
        a = in.nextArray(n);
        Arrays.sort(a);
        for(int i = 0; i < n; ){
            int j = i;
            while(i < n && a[i] == a[j]) i++;
            if( k <= (i - j) * 1L * n){
                out.print(a[j] + " ");
                for(int z = 0; z < n; ){
                    int t = z;
                    while(z < n && a[t] == a[z]) z++;
                    if(k <= (i - j) * 1L * (z-t)){
                        out.println(a[t]);
                        return;
                    }
                    k -= (i - j) * 1L * (z - t);
                }
            }
            k-= ( i - j ) * 1L * n;
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