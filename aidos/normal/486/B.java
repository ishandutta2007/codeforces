import java.util.*;
import java.io.*;
import java.math.*;

public class SolveB {
    FastScanner in;
    PrintWriter out;
    int a[][];
    int c[];
    int d[];
    int b[][];
    int x[][];

    public void solve() throws IOException {
        int n = in.nextInt(), m = in.nextInt();
        a = new int[n+1][m+1];
        c = new int[n+1];
        d = new int[m+1];
        b = new int[n+1][m+1];
        x = new int[n+1][m+1];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = in.nextInt();
                if( a[i][j] == 0){
                    c[i] = 1;
                    d[j] = 1;
                }
                b[i][j]=1;
            }
        }

        for(int i = 0; i < n; i++){
            if(c[i] == 1){
                for(int j = 0; j < m; j++) b[i][j] = 0;
            }
            c[i] = 0;
        }
        for(int i = 0; i < m; i++){
            if( d[i] == 1){
                for(int j = 0; j < n; j++){
                    b[j][i] = 0;
                }
            }
            d[i] = 0;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                d[i] |= b[j][i];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) c[i] |= b[i][j];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((c[i] | d[j])!=a[i][j] ){
                    out.println("NO\n");
                    return;
                }
            }
        }
        out.println("YES");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                out.print(b[i][j] + " ");
            }
            out.println();
        }
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
        new SolveB().run();
    }
}