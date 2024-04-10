    import java.io.*;
    import java.math.BigInteger;
    import java.util.*;

    public class Main {

        BufferedReader br;
        StringTokenizer st;
        PrintWriter out;

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        private void solve() throws IOException {
            String s = next();
            long ans = 0;
            for (int i = 0; i < s.length() - 1; i++) {
                if (s.charAt(i) % 4 == 0)
                    ans++;
                if (((s.charAt(i) - '0') * 10 + (s.charAt(i + 1) - '0')) % 4 == 0) {
                    ans += i + 1;
                }
            }
            if ((s.charAt((s.length() - 1)) - '0') % 4 == 0)
                ans++;
            out.println(ans);
        }

        private void run() throws IOException {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            solve();
            br.close();
            out.close();
        }

        public static void main(String[] args) throws IOException {
            new Main().run();
        }
    }