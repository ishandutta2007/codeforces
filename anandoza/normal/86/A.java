import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        HReflection solver = new HReflection();
        solver.solve(1, in, out);
        out.close();
    }

    static class HReflection {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long l = in.nextLong(), r = in.nextLong();

//        System.out.println("l = " + l);
//        System.out.println("f(l) = " + f(l));
//        System.out.println("r = " + r);
//        System.out.println("f(r) = " + f(r));
            if (l < f(r)) {
                l = f(r);
            }

            long nines = 10 * f(r) - 1;

            ArrayList<Long> candidates = new ArrayList<>();
            candidates.add(l);
            candidates.add(r);
            for (long i = nines / 2 - 3; i < nines / 2 + 3; i++) {
                if (l <= i && i <= r && f(i) == f(r))
                    candidates.add(i);
            }

            long answer = 0;
            for (long c : candidates) {
                answer = Math.max(answer, c * (nines - c));
            }

            out.println(answer);
        }

        long f(long x) {
            long t = 1;
            while (t <= x) {
                t *= 10;
            }
            if (t > x)
                t /= 10;
            return t;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}