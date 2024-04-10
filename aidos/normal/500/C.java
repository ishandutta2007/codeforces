import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionC {
    public static void main(String[] args){
        new SolutionC().run();
    }
    int n, m;
    int w[];
    int b[];
    int d[];
    int pos[];
    int used[];
    void solve(){
        n = in.nextInt();
        m = in.nextInt();
        w = in.nextArray(n);
        b = in.nextArray(m);
        d = new int[n];
        used = new int[n];
        pos = new int[n];
        
        for(int i = 0; i < m ;i++) b[i]--;
        int cur = n-1;
        long ans = 0;
        for(int i = 0; i < m; i++){
            if(used[b[i]] == 0){
                pos[b[i]] = cur;
                d[cur] = b[i];
                used[b[i]]=1;
                cur--;
            }
            int x = pos[b[i]];
            for(int j = x + 1; j < n; j++){
                int t = d[j];
                ans += w[d[j]];
                d[j] = d[j-1];
                d[j-1] = t;
                pos[d[j]] = j;
                pos[d[j-1]] = j-1;
            }
        }
        
        out.println(ans);
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