import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Set;
import java.util.HashMap;
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
        BUniqueness solver = new BUniqueness();
        solver.solve(1, in, out);
        out.close();
    }

    static class BUniqueness {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            HashMap<Integer, Integer> count = new HashMap<>();
            for (int x : a) {
                count.put(x, 1 + count.getOrDefault(x, 0));
            }
            int surplus = n - count.keySet().size();
            //System.out.println(surplus);

            int r;
            for (r = 0; surplus > 0; r++) {
                count.put(a[r], count.get(a[r]) - 1);
                if (count.get(a[r]) >= 1) {
                    surplus--;
                }
            }

            int answer = r;
            //System.out.println(surplus + " " + count);
            //System.out.println(0 + " " + answer);

            outer:
            for (int l = 1; l < n; l++) {
                count.put(a[l - 1], count.get(a[l - 1]) + 1);
                if (count.get(a[l - 1]) >= 2)
                    surplus++;
                //System.out.println(surplus + " " + count);

                for (; surplus > 0; r++) {
                    if (r == n) {
                        break outer;
                    }
                    count.put(a[r], count.get(a[r]) - 1);
                    if (count.get(a[r]) >= 1) {
                        surplus--;
                    }
                    //System.out.println(surplus + " " + count);
                }
                //System.out.println(l + " " + r);
                answer = Math.min(answer, r - l);
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
}