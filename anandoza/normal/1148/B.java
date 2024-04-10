import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        BBornThisWay solver = new BBornThisWay();
        solver.solve(1, in, out);
        out.close();
    }

    static class BBornThisWay {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            long ta = in.nextInt(), tb = in.nextInt();
            int k = in.nextInt();

            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            long[] b = new long[m];
            for (int i = 0; i < m; i++) {
                b[i] = in.nextInt();
            }

            long answer = 0;
            for (int aCancel = 0; aCancel <= k; aCancel++) {
                int bCancel = k - aCancel;

                if (aCancel >= n) {
                    out.println(-1);
                    return;
                }

                long timeAtB = a[aCancel] + ta;

                int bIndex = Arrays.binarySearch(b, timeAtB);
                if (bIndex < 0) {
                    bIndex = -bIndex - 1;
                }

                bIndex += bCancel;

                if (bIndex >= m) {
                    out.println(-1);
                    return;
                }

                long timeAtC = b[bIndex] + tb;
                answer = Math.max(answer, timeAtC);
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

    }
}