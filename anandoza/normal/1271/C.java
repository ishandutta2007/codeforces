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
        CShawarmaTent solver = new CShawarmaTent();
        solver.solve(1, in, out);
        out.close();
    }

    static class CShawarmaTent {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int sx = in.nextInt();
            int sy = in.nextInt();
            int l = 0, r = 0, u = 0, d = 0;
            for (int i = 0; i < n; i++) {
                int x = in.nextInt() - sx;
                int y = in.nextInt() - sy;
                if (x > 0)
                    r++;
                if (x < 0)
                    l++;
                if (y > 0)
                    u++;
                if (y < 0)
                    d++;
            }

            int ans = Util.max(l, r, u, d);
            out.println(ans);
            if (l == ans) {
                out.println(Util.join(sx - 1, sy));
            } else if (r == ans) {
                out.println(Util.join(sx + 1, sy));
            } else if (u == ans) {
                out.println(Util.join(sx, sy + 1));
            } else if (d == ans) {
                out.println(Util.join(sx, sy - 1));
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

        public static int max(int... x) {
            int max = Integer.MIN_VALUE;
            for (int i : x) {
                max = Math.max(i, max);
            }
            return max;
        }

    }
}