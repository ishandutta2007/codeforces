import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class SolutionD {
    public static void main(String [] args){
        new SolutionD().run();
    }
    PrintWriter out;
    FastScanner in;
    long a1, b1, a2, b2;
    long x, y;
    long gcd(long a, long b){
        while( a > 0 && b > 0){
            long x = a % b;
            a = b;
            b = x;
        }
        return a + b;
    }
    void solve(){
        a1 = in.nextLong();
        b1 = in.nextLong();
        a2 = in.nextLong();
        b2 = in.nextLong();
        x = a1 * b1;
        y = a2 * b2;
        long t = x/gcd(x, y);
        while(t%2 == 0 || t % 3 == 0){
            if( t % 2 == 0) t/=2;
            if( t % 3 == 0) t/=3;
        }
        if( t != 1){
            out.println(-1);
            return;
        }
        t = y/gcd(x, y);
        while(t%2 == 0 || t % 3 == 0){
            if( t % 2 == 0) t/=2;
            if( t % 3 == 0) t/=3;
        }
        if( t != 1){
            out.println(-1);
            return;
        }
        int cnt = 0;
        while(a1 * b1 != a2 * b2){
            x = a1 * b1;
            y = a2 * b2;
            t = gcd(x, y);
            cnt++;
            if((x/t) % 3 == 0){
                if( a1 % 3 == 0){
                    a1 *=2;
                    a1/=3;
                }
                else{
                    b1 *=2;
                    b1/=3;
                }
                continue;
            }
            if((y/t) % 3 == 0){
                if( a2 % 3 == 0){
                    a2 *=2;
                    a2/=3;
                }
                else{
                    b2 *=2;
                    b2/=3;
                }
                continue;
            }
            if((x/t) % 2 == 0){
                if( a1 % 2 == 0){
                    a1/=2;
                }
                else{
                    b1/=2;
                }
                continue;
            }
            if((y/t) % 2 == 0){
                if( a2 % 2 == 0){
                    a2/=2;
                }
                else{
                    b2/=2;
                }
                continue;
            }
        }
        out.println(cnt);
        out.println(a1 + " " + b1);
        out.println(a2 + " " + b2);
    }
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
    }
}