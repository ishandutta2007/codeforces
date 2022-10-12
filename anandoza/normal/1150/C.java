import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

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
        CPrefixSumPrimes solver = new CPrefixSumPrimes();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPrefixSumPrimes {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            int ones = 0, twos = 0;
            for (int i = 0; i < n; i++) {
                int a = in.nextInt();

                if (a == 1) {
                    ones++;
                } else {
                    twos++;
                }
            }

            LinkedList<String> twoStrings = new LinkedList<>();
            for (int i = 0; i < twos; i++) {
                twoStrings.add("2");
            }
            for (int i = 0; i < (ones - 1) / 2; i++) {
                twoStrings.add("1 1");
            }

            ArrayList<String> answer = new ArrayList<>();

            if (ones == 0) {
                for (int i = 0; i < n; i++) {
                    answer.add("2");
                }
            } else if (twos == 0) {
                for (int i = 0; i < n; i++) {
                    answer.add("1");
                }
            } else if (ones % 2 == 0) {
                if (!twoStrings.isEmpty()) answer.add(twoStrings.poll());
                answer.add("1");
                while (!twoStrings.isEmpty()) answer.add(twoStrings.poll());
                answer.add("1");
            } else if (ones % 2 == 1) {
                if (!twoStrings.isEmpty()) answer.add(twoStrings.poll());
                answer.add("1");
                while (!twoStrings.isEmpty()) answer.add(twoStrings.poll());
            }

            out.println(String.join(" ", answer));
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