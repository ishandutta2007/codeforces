import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionD {
    public static void main(String[] args){
        new SolutionD().run();
    }
    int k;
    int x[];
    Bor[]b;
    int sz = 1;
    int ans = 0;
    void add(String t){
        int par = 0;
        int n = t.length();
        int cnt = 0;
        boolean ok  = false;
        for(int i = 0; i < n; i++){
            if(b[par].x[t.charAt(i) - 'a'] == -1){
                b[par].x[t.charAt(i) - 'a'] = sz;
                b[sz] = new Bor();
                sz++;
                ok = true;
            }
            cnt += x[t.charAt(i)-'a'];
            if( cnt > k) return;
            if(ok) ans++;
            par = b[par].x[t.charAt(i) - 'a'];
        }
    }
    void solve(){
        String s = in.next(), t = in.next();
        k = in.nextInt();
        x = new int[27];
        for(int i = 0; i < 26; i++) x[i] = '1' - t.charAt(i);
        b = new Bor[1200100];
        int n=s.length();
        b[0]=new Bor();
        for(int i = 0; i < n; i++){
            add(s.substring(i));
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
class Bor{
    int x[];
    public Bor(){
        x = new int[27];
        Arrays.fill(x, -1);
    }
}