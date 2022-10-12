import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
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
        BHyperset solver = new BHyperset();
        solver.solve(1, in, out);
        out.close();
    }

    static class BHyperset {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int[][] s = new int[n][k];

            for (int i = 0; i < n; i++) {
                char[] line = in.next().toCharArray();
                for (int j = 0; j < k; j++) {
                    s[i][j] = "SET".indexOf(line[j]);
                }
            }

            HashSet<Long> set = new HashSet<>();

            int answer = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    long des = 0;
                    for (int t = 0; t < k; t++) {
                        int d;
                        if (s[i][t] == s[j][t])
                            d = s[i][t];
                        else
                            d = 3 - s[i][t] - s[j][t];
                        des *= 3;
                        des += d;
                    }
                    if (set.contains(des))
                        answer++;
                }
                long key = 0;
                for (int x : s[i]) {
                    key *= 3;
                    key += x;
                }
                set.add(key);
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