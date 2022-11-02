import java.util.*;
import java.io.*;
import java.math.*;

public class SolutionB{
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int a = in.nextInt(), b = in.nextInt();
        if( a < b){
            out.println("0");
            return;
        }
        if( a == b){
            out.println("infinity");
            return;
        }
        int x = a - b;
        int cnt = 0;
        for(int i = 1; i * i <= x; i++){
            if( x % i == 0){
                int y = x/i;
                if( i > b ) cnt++;
                if( y > b && y != i ) cnt++;
            }
        }
        out.println(cnt);
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
        new SolutionB().run();
    }
}