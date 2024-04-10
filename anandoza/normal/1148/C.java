import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CCrazyDiamond solver = new CCrazyDiamond();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCrazyDiamond {
        List<String> answer = new ArrayList<>();
        int n;
        int[] p;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();

            p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = in.nextInt() - 1;
            }

            solve();

            out.println(answer.size());
            for (String s : answer) {
                out.println(s);
            }
        }

        void solve() {
            int start = 0;
            int end = n - 1;
            int findStart = -1;
            int findEnd = -1;
            for (int i = 0; i < n; i++) {
//            System.out.println(Arrays.toString(p));

                if (p[i] == start) {
                    findStart = i;
                }
            }

            if (start != findStart) {
                megaswap(start, findStart, start, end);
            }
//        System.out.println("START -=---- - " + Arrays.toString(p));

            for (int i = 0; i < n; i++) {
//            System.out.println(Arrays.toString(p));

                if (p[i] == end) {
                    findEnd = i;
                }
            }

            if (end != findEnd) {
                megaswap(end, findEnd, start, end);
            }

//        System.out.println("START AND END - " + Arrays.toString(p));

            int[] inv = new int[n];
            for (int i = 1; i < n - 1; i++) {
                inv[p[i]] = i;
            }

            for (int i = 1; i < n - 1; i++) {
//            System.out.println(Arrays.toString(p));

                if (i == inv[i]) {
                    continue;
                }
                if (p[i] == start || p[i] == end) {
                    System.out.println("oh no!");
                }

                inv[p[i]] = inv[i];
                megaswap(i, inv[i], start, end);

//            System.out.println(Arrays.toString(p));
//            System.out.println(i + " " + p[i] + " " + a + " " + b);
            }
//        System.out.println(Arrays.toString(p));

//        System.out.println(Arrays.toString(p));
        }

        private boolean megaswap(int a, int b, int start, int end) {
            int first = Math.min(a, b);
            int second = Math.max(a, b);
            a = first;
            b = second;

            if (valid(a, b)) {
                swap(a, b);
                return true;
            }

            if (valid(a, end) && valid(b, end)) {
                swap(a, end);
                swap(b, end);
                swap(a, end);
                return true;
            }

            if (valid(a, start) && valid(b, start)) {
                swap(a, start);
                swap(b, start);
                swap(a, start);
                return true;
            }

            if (valid(a, end) && valid(start, b)) {
                swap(a, end);
                swap(start, b);
                swap(start, end);
                swap(a, end);
                swap(start, b);
                return true;
            }
//        System.out.println(Arrays.toString(p));
//        System.out.println(a + " " + b);

            return false;
        }

        private boolean valid(int a, int b) {
            return a != b && 2 * Math.abs(a - b) >= n;
        }

        void swap(int a, int b) {
//        if (!valid(a, b)) {
//            System.out.println("Oh no!");
//            System.out.println(a + " " + b);
//        }
            int t = p[a];
            p[a] = p[b];
            p[b] = t;
            a++;
            b++;
            answer.add(a + " " + b);
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