import java.util.*;
import java.io.*;
import java.math.*;

public class SolutionC{
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        String s = in.next();
        StringBuilder st = new StringBuilder();
        int n = s.length();
        int cnt = 0;
        int pos = -1;
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == '#') pos = i;
        }
        int cntx = 0;
        for(int i = 0; i <= pos; i++){
            char x = s.charAt(i);
            if( x == '(') cnt++;
            else cnt--;
            if(x == '#'){
                st.append(')');
            }
            else st.append(x);
        }
        for(int i = pos+1; i<n; i++){
            if(s.charAt(i) == '(') cnt++;
            else cnt--;
        }
        for(int i = 0; i < cnt; i++){
            st.append(')');
        }
        for(int i = pos+1; i<n; i++){
            st.append(s.charAt(i));
        }
        Stack sta = new Stack();
        String stx = st.toString();
        for(int i = 0; i<stx.length(); i++){
            if( stx.charAt(i) == '('){
                sta.add(new Integer(1));
            }
            else {
                if( sta.empty() ){
                    out.println(-1);
                    return;
                }
                sta.pop();
            }
        }
        if( !sta.empty()) {
            out.println(-1);
            return;
        }
        for(int i = 0;i<s.length(); i++){
            if( s.charAt(i) == '#'){
                out.println((i == pos?cnt:0) + 1);
            }
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
        new SolutionC().run();
    }
}