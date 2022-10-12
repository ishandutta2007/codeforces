import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
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
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BLongestPalindrome solver = new BLongestPalindrome();
        solver.solve(1, in, out);
        out.close();
    }

    static class BLongestPalindrome {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            String[] s = new String[n];
            for (int i = 0; i < n; i++) {
                s[i] = in.next();
            }
            Arrays.sort(s);

            List<String> palindromes = new ArrayList<>();
            List<String> nonPalindromes = new ArrayList<>();
            for (String x : s) {
                (x.equals(reverse(x)) ? palindromes : nonPalindromes).add(x);
            }

            StringBuilder center = new StringBuilder();
            StringBuilder left = new StringBuilder();
            for (int i = 0, j = 0; i < palindromes.size(); i = j) {
                while (j < palindromes.size() && palindromes.get(i).equals(palindromes.get(j)))
                    j++;

                int c = j - i;
                if (center.length() == 0 && c % 2 == 1) {
                    center.append(palindromes.get(i));
                }
                for (int k = 0; k < c / 2; k++) {
                    left.append(palindromes.get(i));
                }
            }

            HashMap<String, Integer> count = new HashMap<>();
            for (String x : nonPalindromes)
                count.merge(x, 1, Integer::sum);
            for (int i = 0, j = 0; i < nonPalindromes.size(); i = j) {
                String cur = nonPalindromes.get(i);
                while (j < nonPalindromes.size() && cur.equals(nonPalindromes.get(j)))
                    j++;

                int c1 = count.get(cur);
                String rev = reverse(cur);
                int c2 = count.getOrDefault(rev, 0);
                int c = Math.max(0, Math.min(c1, c2));
                count.merge(cur, -c, Integer::sum);
                for (int k = 0; k < c; k++) {
                    left.append(cur);
                }
            }

            String right = reverse(left.toString());
            String answer = new StringBuilder().append(left).append(center).append(right).toString();
            out.println(answer.length());
            out.println(answer);
        }

        private static String reverse(String s) {
            StringBuilder r = new StringBuilder();
            r.append(s);
            r.reverse();
            return r.toString();
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