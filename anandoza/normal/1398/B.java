import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BSubstringRemovalGame solver = new BSubstringRemovalGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class BSubstringRemovalGame {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int[] s = in.readBitString();
            final int n = s.length;

            List<Integer> ones = new ArrayList<>();
            for (int i = 0, j = 0; i < n; i = j) {
                while (j < n && s[i] == s[j])
                    j++;

                if (s[i] == 1)
                    ones.add(j - i);
            }
            Collections.sort(ones, Comparator.reverseOrder());

            int answer = 0;
            for (int i = 0; i < ones.size(); i += 2) {
                answer += ones.get(i);
            }
            out.println(answer);
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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

        public int[] readBitString() {
            char[] chars = next().toCharArray();
            int[] x = new int[chars.length];
            for (int i = 0; i < x.length; i++) {
                x[i] = chars[i] - '0';
            }
            return x;
        }

    }
}