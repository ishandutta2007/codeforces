import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        CFromSToT solver = new CFromSToT();
        solver.solve(1, in, out);
        out.close();
    }

    static class CFromSToT {
        private static final String NO = "NO";
        private static final String YES = "YES";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                boolean answer = solve(in, out);
                out.println(answer ? YES : NO);
            }
        }

        private boolean solve(InputReader in, PrintWriter out) {
            char[] s = in.next().toCharArray();
            char[] t = in.next().toCharArray();
            char[] p = in.next().toCharArray();

            List<Character> need = new ArrayList<>();
            int tIndex = 0;
            for (int i = 0; i < s.length; i++) {
                while (tIndex < t.length && t[tIndex] != s[i]) {
                    need.add(t[tIndex]);
                    tIndex++;
                }

                if (tIndex == t.length) {
                    return false;
                }

                tIndex++;
            }
            while (tIndex < t.length) {
                need.add(t[tIndex]);
                tIndex++;
            }

            int[] count = new int[26];
            for (char x : p) {
                count[x - 'a']++;
            }

            for (char x : need) {
                count[x - 'a']--;
            }

            for (int c : count) {
                if (c < 0)
                    return false;
            }

            return true;
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