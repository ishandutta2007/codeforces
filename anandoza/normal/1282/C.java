import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        CPetyaAndExam solver = new CPetyaAndExam();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPetyaAndExam {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int T = in.nextInt();
            int a = in.nextInt(), b = in.nextInt();

            int[] type = new int[n];
            for (int i = 0; i < n; i++) {
                int j = in.nextInt();
                type[i] = j == 0 ? a : b;
            }

            int[] t = in.readIntArray(n);

            Pair<Integer, Integer>[] p = new Pair[n];
            for (int i = 0; i < n; i++) {
                p[i] = Pair.of(t[i], type[i]);
            }

            Arrays.sort(p, Comparator.comparingInt(pair -> -pair.first));

            int time = T;
            long cost = 0;
            for (int i = 0; i < n; i++) {
                cost += type[i];
            }

            int problemsSkipped = 0;
            int easyCount = 0;
            int hardCount = 0;
            int answer = 0;
            if (time >= cost)
                answer = n;
            while (true) {
                int j = problemsSkipped;
                while (j < n && p[j].first.equals(p[problemsSkipped].first))
                    j++;

                for (int i = problemsSkipped; i < j; i++) {
                    cost -= p[i].second;
                    if (p[i].second == a)
                        easyCount++;
                    else
                        hardCount++;
                }
                problemsSkipped = j;
                time = p[problemsSkipped - 1].first - 1;

                if (time >= cost) {
                    long extra = time - cost;
                    int bonus = 0;
                    //System.out.println("EXTRA: " + extra + " " + Util.join(a, b, easyCount, hardCount));
                    long easyBonus = Math.min(easyCount, extra / a);
                    bonus += easyBonus;
                    extra -= a * easyBonus;
                    long hardBonus = Math.min(hardCount, extra / b);
                    bonus += hardBonus;
                    extra -= b * hardBonus;
                    answer = Math.max(answer, n - problemsSkipped + bonus);
                }
                //System.out.println("EXTRA2: " + extra + " " + Util.join(a, b, easyCount, hardCount));

                if (problemsSkipped == n)
                    break;
            }

            out.println(answer);
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

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        public static <F, S> Pair<F, S> of(F first, S second) {
            return new Pair<>(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        public int hashCode() {
            return Objects.hash(first, second);
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

    }
}