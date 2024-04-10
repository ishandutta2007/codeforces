import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionB {
    public static void main(String[] args){
        new SolutionB().run();
    }
    int n;
    int p[];
    int d[][];
    void solve(){
        n = in.nextInt();
        p = in.nextArray(n);
        d = new int[n][n];
        for(int i = 0; i < n; i++){
            String x = in.next();
            for(int j = 0; j < n; j++){
                d[i][j] = x.charAt(j) - '0';
            }
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    d[i][j] |= (d[i][k] & d[k][j]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            int cur = i;
            for(int j = i+1; j < n; j++){
                if(d[i][j] == 1 && p[cur] > p[j]) cur = j;
            }
            int x = p[cur];
            p[cur] = p[i];
            p[i] = x;
        }
        for(int i = 0; i < n; i++)
            out.print(p[i] + " ");
        out.println();
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