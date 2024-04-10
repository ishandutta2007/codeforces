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
        BUglyPairs solver = new BUglyPairs();
        solver.solve(1, in, out);
        out.close();
    }

    static class BUglyPairs {
        static final String NO = "No answer";
        private static final char A = 'a';

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.nextInt();
            for (int testcase = 0; testcase < T; testcase++) {
                String s = in.next();

                out.println(solve(s));
            }
        }

        private static String solve(String s) {
            char[] chars = s.toCharArray();
            int[] count = new int[26];
            char[] odd = new char[13];
            char[] even = new char[13];
            for (int i = 0; i < 26; i++) {
                if (i % 2 == 0) {
                    even[i / 2] = (char) (A + i);
                } else {
                    odd[i / 2] = (char) (A + i);
                }
            }

            for (char c : chars) {
                count[c - A]++;
            }

            StringBuilder oddSb = new StringBuilder();
            for (char x : odd) {
                for (int j = 0; j < count[x - A]; j++) {
                    oddSb.append(x);
                }
            }
            StringBuilder evenSb = new StringBuilder();
            for (char x : even) {
                for (int j = 0; j < count[x - A]; j++) {
                    evenSb.append(x);
                }
            }

            if (oddSb.length() == 0 || evenSb.length() == 0) {
                return oddSb.toString() + evenSb.toString();
            }

            for (int i = 0; i < oddSb.length(); i++) {
                for (int j = 0; j < evenSb.length(); j++) {
                    if (Math.abs(oddSb.charAt(i) - evenSb.charAt(j)) != 1) {
                        oddSb.append(oddSb.charAt(i));
                        oddSb.deleteCharAt(i);
                        evenSb.insert(0, evenSb.charAt(j));
                        evenSb.deleteCharAt(j + 1);
                        return oddSb.toString() + evenSb.toString();
                    }
                }
            }

            return NO;
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