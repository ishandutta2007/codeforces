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
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EKuroniAndTheScoreDistribution solver = new EKuroniAndTheScoreDistribution();
        solver.solve(1, in, out);
        out.close();
    }

    static class EKuroniAndTheScoreDistribution {
        private static final int MAX = 1_000_000_000;
        private static final int MIN = 1;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            int[] answer = solve(n, m);
            if (answer == null) {
                out.println(-1);
                return;
            }

            //Util.ASSERT(m == countSlow(answer));
            out.println(Util.join(answer));
        }

        static int[] solve(int n, int m) {
            if (m > maxM(n)) {
                return null;
            }

            if (m == 0) {
                int[] answer = new int[n];
                for (int i = 0; i < n; i++) {
                    answer[i] = MAX - 2 * n + i;
                }
                return answer;
            }

            int start = findStart(n, m);
            int countPrefix = count(start, start + n - 1);
            int diff = m - countPrefix;
            //System.out.println("diff: " + diff);
            int[] answer = new int[n];
            for (int i = 0; i < n - 1; i++) {
                answer[i] = i + start;
            }
            int lo = start, hi = start + n - 2;
            for (int i = hi + 1; i <= hi * 2; i++) {
                int d = countTargetInRange(i, lo, hi);
                //System.out.println("TRY: " + i + " " + diff + " " + d);
                if (d == diff) {
                    answer[n - 1] = i;
                    break;
                }
            }
            return answer;
        }

        private static int countTargetInRange(int target, int lo, int hi) {
            if (hi + hi - 1 < target)
                return 0;
            if (lo + lo + 1 > target)
                return 0;
            if (hi + lo == target) {
                return (hi - lo + 1) / 2;
            }
            if (hi + lo < target) {
                lo = target - hi;
                return (hi - lo + 1) / 2;
            }
            hi = target - lo;
            return (hi - lo + 1) / 2;
        }

        static int findStart(int n, int m) {
            for (int start = MIN; ; start++) {
                if (count(start, start + n) < m) {
                    return start - 1;
                }
            }
        }

        static int count(int lo, int hi) {
            int r = 0;
            for (int i = lo; i < hi; i++) {
                r += Math.max(0, (i - 2 * lo + 1) / 2);
            }
            return r;
        }

        static int maxM(int n) {
            int r = 0;
            for (int i = MIN; i - MIN < n; i++) {
                r += (i - 1) / 2;
            }
            return r;
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

        private Util() {
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

    }
}