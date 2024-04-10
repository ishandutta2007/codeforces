import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        DGuessTheMaximums solver = new DGuessTheMaximums();
        solver.solve(1, in, out);
        out.close();
    }

    static class DGuessTheMaximums {
        InputReader in;
        PrintWriter out;
        int n;
        int k;
        int[][] subsets;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;

            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        void answer(int... answer) {
            out.println("! " + Util.join(answer));
            out.flush();
            in.next();
        }

        int query(int... indices) {
            TreeSet<Integer> other = new TreeSet<>();
            for (int i = 1; i <= n; i++) {
                other.add(i);
            }
            for (int i : indices) {
                for (int j : subsets[i]) {
                    other.remove(j);
                }
            }
            out.println("? " + other.size() + " " + Util.join(other));
            out.flush();
            return in.nextInt();
        }

        int query(List<Integer> indices) {
            int[] x = new int[indices.size()];
            int j = 0;
            for (int i : indices) {
                x[j++] = i;
            }
            return query(x);
        }

        private void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            subsets = new int[k][];
            for (int i = 0; i < k; i++) {
                int size = in.nextInt();
                subsets[i] = in.readIntArray(size);
            }

            if (k == 1) {
                int max = query(0);
                answer(max);
                return;
            }

            int max = query();
            int left = 0;
            int right = k;
            int candidate = -1;
            while (right - left > 1) {
                int center = left + (right - left) / 2;
                List<Integer> l = new ArrayList<>();
                for (int i = left; i < center; i++) {
                    l.add(i);
                }
                candidate = query(l);
                if (candidate == max) {
                    left = center;
                } else {
                    right = center;
                }
            }
            System.err.println("l + r = " + left + " " + right);
            int second = query(left);

            int[] answer = new int[k];
            for (int i = 0; i < k; i++) {
                answer[i] = max;
            }
            answer[left] = second;
            answer(answer);
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }

    static class Util {
        public static String join(Iterable i) {
            StringBuilder sb = new StringBuilder();
            for (Object o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

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
}