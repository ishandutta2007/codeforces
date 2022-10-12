import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.util.function.ToIntFunction;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        E1StringColoringEasyVersion solver = new E1StringColoringEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class E1StringColoringEasyVersion {
        private static final String YES = "YES";
        private static final String NO = "NO";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] sInput = in.next().toCharArray();
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = sInput[i] - 'a';
            }

            List<Integer> first = new ArrayList<>();
            List<Integer> second = new ArrayList<>();
            ToIntFunction<List<Integer>> last = (l) -> l.isEmpty() ? -1 : s[l.get(l.size() - 1)];

            for (int i = 0; i < n; i++) {
                if (s[i] < last.applyAsInt(first)) {
                    if (s[i] < last.applyAsInt(second)) {
                        out.println(NO);
                        return;
                    }
                    second.add(i);
                } else {
                    if (s[i] < last.applyAsInt(second)) {
                        first.add(i);
                    } else {
                        if (last.applyAsInt(first) > last.applyAsInt(second)) {
                            first.add(i);
                        } else {
                            second.add(i);
                        }
                    }
                }
            }

            char[] answer = new char[n];
            for (int i : first) {
                answer[i] = '0';
            }
            for (int i : second) {
                answer[i] = '1';
            }
            out.println(YES);
            out.println(String.valueOf(answer));
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