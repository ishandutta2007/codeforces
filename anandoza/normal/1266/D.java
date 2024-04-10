import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.ArrayDeque;
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
        DDecreasingDebts solver = new DDecreasingDebts();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDecreasingDebts {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            long[] bal = new long[n];
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                long c = in.nextLong();
                bal[a] -= c;
                bal[b] += c;
            }

            Queue<Integer> pos = new ArrayDeque<>();
            Queue<Integer> neg = new ArrayDeque<>();
            for (int i = 0; i < n; i++) {
                if (bal[i] > 0)
                    pos.add(i);
                if (bal[i] < 0)
                    neg.add(i);
                bal[i] = Math.abs(bal[i]);
            }

            List<String> output = new ArrayList<>();
            while (!pos.isEmpty() && !neg.isEmpty()) {
                int a = neg.poll();
                int b = pos.poll();

                long c = Math.min(bal[a], bal[b]);
                bal[a] -= c;
                bal[b] -= c;
                output.add(Util.join(a + 1, b + 1, c));
                if (bal[a] > 0)
                    neg.add(a);
                if (bal[b] > 0)
                    pos.add(b);
            }

            out.println(output.size());
            for (String s : output)
                out.println(s);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }

    static class Util {
        public static String join(long... i) {
            StringBuilder sb = new StringBuilder();
            for (long o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

    }
}