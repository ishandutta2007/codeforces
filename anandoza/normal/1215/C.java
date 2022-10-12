import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
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
        CSwapLetters solver = new CSwapLetters();
        solver.solve(1, in, out);
        out.close();
    }

    static class CSwapLetters {
        private static final boolean DEBUG = false;
        Queue<Integer> ab;
        Queue<Integer> ba;
        CSwapLetters.S[] s;
        int n;
        List<String> moves;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            moves = new ArrayList<>();

            n = in.nextInt();
            String line1 = in.next(), line2 = in.next();

            s = new CSwapLetters.S[n];
            ab = new ArrayDeque<>();
            ba = new ArrayDeque<>();
            for (int i = 0; i < n; i++) {
                if (line1.charAt(i) == line2.charAt(i)) {
                    set(i, CSwapLetters.S.EQ);
                } else if (line1.charAt(i) == 'a') {
                    set(i, CSwapLetters.S.AB);
                } else {
                    set(i, CSwapLetters.S.BA);
                }
            }

            boolean possible = process();

            if (possible) {
                out.println(moves.size());
                for (String x : moves) {
                    out.println(x);
                }
            } else {
                out.println(-1);
            }
        }

        private boolean process() {
            if (DEBUG)
                System.out.println(Arrays.toString(s));
            while (!ab.isEmpty() || !ba.isEmpty()) {
                if (ab.size() >= 2) {
                    swap(ab.poll(), ab.poll());
                } else if (ba.size() >= 2) {
                    swap(ba.poll(), ba.poll());
                } else if (!ab.isEmpty() && !ba.isEmpty()) {
                    int i = ab.poll();
                    swap(i, i);
                } else {
                    return false;
                }
                if (DEBUG)
                    System.out.println(Arrays.toString(s));
            }
            return true;
        }

        private void swap(int i, int j) {
            Util.ASSERT(s[i] != CSwapLetters.S.EQ);
            if (i == j) {
                set(i, s[i] == CSwapLetters.S.AB ? CSwapLetters.S.BA : CSwapLetters.S.AB);
            } else if (s[i] == s[j]) {
                set(i, CSwapLetters.S.EQ);
                set(j, CSwapLetters.S.EQ);
            } else {
                if (s[i] == CSwapLetters.S.AB) {
                    set(i, CSwapLetters.S.AB);
                    set(j, CSwapLetters.S.AB);
                } else {
                    set(i, CSwapLetters.S.BA);
                    set(i, CSwapLetters.S.BA);
                }
            }

            moves.add(Util.join(i + 1, j + 1));
        }

        private void set(int i, CSwapLetters.S v) {
            s[i] = v;
            if (v == CSwapLetters.S.AB) {
                ab.add(i);
            } else if (v == CSwapLetters.S.BA) {
                ba.add(i);
            }
        }

        enum S {
            EQ,
            AB,
            BA,
            ;
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

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
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