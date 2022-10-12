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
        CLoseIt solver = new CLoseIt();
        solver.solve(1, in, out);
        out.close();
    }

    static class CLoseIt {
        static final int[] good = {4, 8, 15, 16, 23, 42};
        static final int six = 6;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            int[] subseq = new int[six + 1];
            subseq[0] = Integer.MAX_VALUE;
            int answer = 0;
            for (int i = 0; i < n; i++) {
                int index = index(a[i]);
                if (index >= 0 && subseq[index] > 0) {
                    subseq[index + 1]++;
                    subseq[index]--;
                } else {
                    answer++;
                }
            }
            for (int i = 1; i < six; i++) {
                answer += subseq[i] * i;
            }

            out.println(answer);
        }

        static int index(int x) {
            for (int i = 0; i < six; i++) {
                if (good[i] == x) {
                    return i;
                }
            }
            return -1;
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