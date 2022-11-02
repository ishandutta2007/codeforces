import java.util.*;
import java.io.*;
import java.math.*;

public class SolveC {
    FastScanner in;
    PrintWriter out;
    int go(char a, char b){
        if( a < b){
            char c = a;
            a = b;
            b = c;
        }
        return Math.min(a-b, b - a + 26);
    }
    public void solve() throws IOException {
        int n = in.nextInt(), p = in.nextInt();
        String x=in.next();
        ArrayList < Integer > arr = new ArrayList<Integer>();
        for(int i = 0; i  < n; i++){
            arr.add(go(x.charAt(i), x.charAt(n-i-1)));
        }
        p--;
        int sum = 0;
        for(int a:arr){
            sum += a;
        }
        sum/=2;
        int ans = Integer.MAX_VALUE;
        if( sum == 0){
            out.println(0);
            return;
        }
        int pos1 = -1;
        int pos2 = -1;
        for(int i = 0; i < n/2; i++){
            if(pos1 == -1 && arr.get(i)!=0){
                pos1 = i;
            }
            if(arr.get(i) != 0) pos2 = i;
        }
        ans = Math.min(ans, pos2 - pos1 + Math.abs(p-pos1));
        ans = Math.min(ans, pos2 - pos1 + Math.abs(p-pos2));
        //out.println(ans);
        pos1 = -1;
        pos2 = -1;
        int cur = n/2;
        
        for(int i = n/2 ; i < n; i++){
            if(pos1 == -1 && arr.get(i)!=0){
                pos1 = i;
            }
            if(arr.get(i) != 0) pos2 = i;
        }
        //out.println((pos2 - pos1 + Math.abs(p-pos1)) + " " + (pos2 - pos1 + Math.abs(p-pos2)) + " " + pos1 + " " + pos2);
        ans = Math.min(ans, pos2 - pos1 + Math.abs(p-pos1));
        ans = Math.min(ans, pos2 - pos1 + Math.abs(p-pos2));
        
        
        out.println(ans + sum);
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
        new SolveC().run();
    }
}