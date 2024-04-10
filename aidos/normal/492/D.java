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
    int n;
    long x, y, g;
    long gcd(long a, long b){
        while( a > 0 && b > 0){
            long x = a % b;
            a = b;
            b = x;
        }
        return a + b;
    }
    void solve(){
        n = in.nextInt();
        x = in.nextLong();
        y = in.nextLong();
        g = x/gcd(x, y) * y;
        
        for(int i=0; i < n; i++){
            long a = in.nextLong();
            long l = 0;
            long r = Long.MAX_VALUE;
            long ans = -1;
            while(l<=r){
                long mid = (l+r)/2;
                long t = mid/x+mid/y;
                if( t < a){
                    l = mid+1;
                    continue;
                }
                r = mid-1;
                ans = mid;
            }
            if(ans % g == 0){
                out.println("Both");
            }
            else if( ans % x == 0){
                out.println("Vova");
            }
            else out.println("Vanya");
        }
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