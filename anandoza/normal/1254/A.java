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
        AFeedingChicken solver = new AFeedingChicken();
        solver.solve(1, in, out);
        out.close();
    }

    static class AFeedingChicken {
        int r;
        int c;
        int k;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            r = in.nextInt();
            c = in.nextInt();
            k = in.nextInt();
            int size = r * c;

            boolean[] rice = new boolean[size];
            for (int i = 0, index = 0; i < r; i++) {
                char[] row = in.next().toCharArray();
                for (char c : row) {
                    rice[map(index++)] = (c == 'R');
                }
            }

            int riceCount = 0;
            for (boolean b : rice) {
                if (b)
                    riceCount++;
            }
            int min = riceCount / k;
            riceCount -= min * k;
            int max = min + (riceCount > 0 ? 1 : 0);
            int maxCount = riceCount;
            int minCount = k - maxCount;

            StringBuilder chickenNames = new StringBuilder();
            for (char x = 'A'; x <= 'Z'; x++) {
                chickenNames.append(x);
            }
            for (char x = 'a'; x <= 'z'; x++) {
                chickenNames.append(x);
            }
            for (char x = '0'; x <= '9'; x++) {
                chickenNames.append(x);
            }
            char[] chickens = chickenNames.toString().substring(0, k).toCharArray();

            int[] answer = new int[size];
            int currentChicken = 0;
            int count = 0;
            for (int i = 0; i < size; i++) {
                answer[i] = currentChicken;
                if (rice[i])
                    count++;
                if (currentChicken < minCount && count == min || currentChicken >= minCount && count == max) {
                    if (currentChicken < k - 1)
                        currentChicken++;
                    count = 0;
                }
            }

            StringBuilder output = new StringBuilder();
            for (int i = 0; i < size; i++) {
                if (i % c == 0 && i > 0)
                    output.append("\n");
                output.append(chickens[answer[map(i)]]);
            }
            out.println(output);
        }

        private int map(int i) {
            int row = i / c;
            int col = i % c;
            if (row % 2 == 1) {
                col = c - 1 - col;
            }
            int val = row * c + col;

            return val;
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