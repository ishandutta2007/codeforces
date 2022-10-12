import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DWalkingBetweenHouses solver = new DWalkingBetweenHouses();
        solver.solve(1, in, out);
        out.close();
    }

    static class DWalkingBetweenHouses {
        final String NO = "NO";
        final String YES = "YES";
        PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            this.out = out;
            long s = in.nextLong();
            solve(n, k, s);
        }

        void solve(int n, int k, long s) {
            if (s > (n - 1) * (long) k) {
                out.println(NO);
                return;
            }

            long full = s / (n - 1);
            long remain = s % (n - 1);
            while (full + remain < k) {
                full--;
                if (full < 0 || full > k) {
                    out.println(NO);
                    return;
                }
                remain += n - 1;
            }
            if (full < 0 || full > k) {
                out.println(NO);
                return;
            }

            int cur = 1;

            int[] ans = new int[(int) k];
            int ansIndex = 0;
            for (int i = 0; i < full; i++) {
                cur = n + 1 - cur;
                ans[ansIndex++] = cur;
            }
            if (remain > 0) {
                int ones = (k - ansIndex) - 1;
                long step = remain - ones;

                if (step < 0) {
                    out.println(NO);
                    return;
                }
                if (step > 0) {
                    if (cur == 1) {
                        cur += step;
                        ans[ansIndex++] = cur;
                    } else {
                        cur -= step;
                        ans[ansIndex++] = cur;
                    }
                }
                while (ansIndex < k) {
                    if (cur < n)
                        cur++;
                    else
                        cur--;
                    ans[ansIndex++] = cur;
                }
            }

//        long start = 1;
//        long tot = 0;
//        for (long x : ans) {
//            tot += Math.abs(x - start);
//            Util.ASSERT(x != start);
//            Util.ASSERT(x >= 1 && x <= n);
//            start = x;
//        }
//        Util.ASSERT(ans.size() == k);
//        Util.ASSERT(tot == s);

            out.println(YES);
            out.println(Util.join(ans));
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }

    static class Util {
        public static String join(int... i) {
            StringBuilder sb = new StringBuilder();
            for (int o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

    }
}