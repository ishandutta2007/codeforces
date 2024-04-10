import java.util.*;
import java.io.*;
import java.math.*;

public class SolutionA {
    FastScanner in;
    PrintWriter out;
    public void solve() throws IOException {
        long ans = 0;
        long a = in.nextLong();
        if(a % 2 == 0){
            ans=a/2;
        }
        else{
            long b=a-1;
            ans = b/2;
            ans -= a;
        }
        out.println(ans);
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
        new SolutionA().run();
    }
}