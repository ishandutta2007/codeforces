import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.function.Function;
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
        BLettersShop solver = new BLettersShop();
        solver.solve(1, in, out);
        out.close();
    }

    static class BLettersShop {
        static final char A = 'a';
        static final int K = 26;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] s = in.next().toCharArray();
            int m = in.nextInt();

            int[][] count = new int[n + 1][K];
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < K; j++) {
                    count[i][j] = count[i - 1][j];
                }
                count[i][s[i - 1] - A]++;
            }

            for (int i = 0; i < m; i++) {
                char[] name = in.next().toCharArray();
                int[] des = new int[K];
                for (char x : name) {
                    des[x - A]++;
                }

                int answer = 0;
                for (int j = 0; j < K; j++) {
                    final int finalJ = j;
                    answer = Math.max(answer, BinarySearch.binarySearch(index -> {
                        if (index > n)
                            return true;
                        return count[index][finalJ] >= des[finalJ];
                    }));
                }

                out.println(answer);
            }
        }

    }

    static class BinarySearch {
        public static int binarySearch(Function<Integer, Boolean> bigEnough) {
            int tooSmall = 0, tooBig;
            if (bigEnough.apply(tooSmall)) {
                return tooSmall;
            }

            for (tooBig = 1; !bigEnough.apply(tooBig); tooBig *= 2)
                ;

            if (!bigEnough.apply(tooBig - 1)) {
                return tooBig;
            }

            while (tooBig - tooSmall > 1) {
                int center = (tooBig + tooSmall) / 2;
                if (!bigEnough.apply(center)) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return tooBig;
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