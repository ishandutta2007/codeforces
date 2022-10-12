import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        CVasyaAndArray solver = new CVasyaAndArray();
        solver.solve(1, in, out);
        out.close();
    }

    static class CVasyaAndArray {
        static final int MAX = 1_000_000_000;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            int[] answer = new int[n];
            for (int i = 0; i < n; i++) {
                answer[i] = 1;
            }

            boolean[] sorted = new boolean[n - 1];

            List<EndPoint> unsorted = new ArrayList<>();

            for (int i = 0; i < m; i++) {
                int t = in.nextInt();
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                if (t == 1) {
                    Arrays.fill(sorted, l, r, true);
                } else {
                    unsorted.add(new EndPoint(l, true));
                    unsorted.add(new EndPoint(r, false));
                }
            }

            boolean possible = true;
            for (int i = 0; i < unsorted.size(); i += 2) {
                int left = unsorted.get(i).i;
                int right = unsorted.get(i + 1).i;

                boolean done = false;
                for (int j = left; j < right; j++) {
                    if (!sorted[j]) {
                        answer[j] = MAX - j;
                        done = true;
                        break;
                    }
                }
                if (!done)
                    possible = false;
            }

            out.println(possible ? "YES" : "NO");
            if (possible) {
                StringBuilder sb = new StringBuilder();
                for (int x : answer)
                    sb.append(x + " ");
                sb.deleteCharAt(sb.length() - 1);

                out.println(sb);
            }
        }

        private class EndPoint implements Comparable<EndPoint> {
            final int i;
            final boolean start;

            private EndPoint(int i, boolean start) {
                this.i = i;
                this.start = start;
            }

            public int compareTo(EndPoint o) {
                int ret = Integer.compare(i, o.i);
                if (ret != 0)
                    return ret;
                ret = Boolean.compare(start, o.start);
                return ret;
            }

            public String toString() {
                return "EndPoint{" + "i=" + i + ", start=" + start + '}';
            }

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