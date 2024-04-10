import java.util.*;
import java.io.*;
import java.math.*;

public class SolutionD{
    FastScanner in;
    PrintWriter out;
    int z[];
    int fr[];

    public void solve() throws IOException {
        String a = in.next();
        String b = in.next();
        String x = b + '#' + a;
        z = new int[x.length()+5];
        fr = new int[x.length()+5];
        int l = 0, r = 0;
        for(int i = 1; i<x.length(); i++){
            if( i<= r ) z[i] = Math.min(r - i +1, z[i-l]);
            while (i+z[i] < x.length() && x.charAt(z[i]) == x.charAt(i+z[i]))
                ++z[i];
            if (i+z[i]-1 > r){
                l = i;  r = i+z[i]-1;
            }
        }
        int sum = 0;
        int cur = 0;
        int mod = 1000000007;
        for(int i = x.length()-b.length(); i>b.length(); i--){
            sum += fr[b.length()+i]+1;
            sum %= mod;
            if(z[i] == b.length()){
                cur = sum;
            }
            fr[i] = (fr[i+1] + cur) % mod;
        }
        
        out.println(fr[b.length()+1]);
    }

    public void run() {
        try {
            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream f) {
            try {
                br = new BufferedReader(new InputStreamReader(f));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
    }

    public static void main(String[] arg) {
        new SolutionD().run();
    }
}