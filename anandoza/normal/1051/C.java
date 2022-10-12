import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Iterator;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
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
        CVasyaAndMultisets solver = new CVasyaAndMultisets();
        solver.solve(1, in, out);
        out.close();
    }

    static class CVasyaAndMultisets {
        static final int MAX = 101;
        private static final boolean DEBUG = false;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] s = new int[n];
            int[] count = new int[MAX];

            for (int i = 0; i < n; i++) {
                s[i] = in.nextInt();
                count[s[i]]++;
            }

            HashSet<Integer> one = new HashSet<>();
            HashSet<Integer> two = new HashSet<>();
            HashSet<Integer> many = new HashSet<>();

            for (int x : s) {
                switch (count[x]) {
                    case 1:
                        one.add(x);
                        break;
                    case 2:
                        two.add(x);
                        break;
                    default:
                        many.add(x);
                        break;
                }
            }

            int imbalance = one.size();

            if (imbalance % 2 == 1 && many.size() == 0) {
                out.println("NO");
                return;
            }

            out.println("YES");

            boolean[] color = new boolean[n];

            HashSet<Integer> first = new HashSet<>();
            HashSet<Integer> second = new HashSet<>();
            for (int x : one) {
                if (first.size() < imbalance / 2) {
                    first.add(x);
                } else {
                    second.add(x);
                }
            }
            if (first.size() < second.size()) {
                first.add(many.iterator().next());
            }

            outer:
            for (int x : one) {
                boolean c = first.contains(x);
                for (int i = 0; i < n; i++) {
                    if (s[i] == x) {
                        color[i] = c;
                    }
                }
            }
            for (int x : many) {
                boolean putInFirst = first.contains(x);
                if (putInFirst) {
                    boolean f = true;
                    for (int i = 0; i < n; i++) {
                        if (s[i] == x) {
                            color[i] = f;
                            f = false;
                        }
                    }
                }
            }

            if (DEBUG) {
                int[] score = new int[2];
                for (int c = 0; c <= 1; c++) {
                    boolean co = c == 0;
                    int[] count1 = new int[MAX];
                    for (int i = 0; i < n; i++) {
                        if (color[i] == co) {
                            count1[s[i]]++;
                        }
                    }
                    score[c] = 0;
                    for (int x : count1) {
                        if (x == 1)
                            score[c]++;
                    }
                }
                System.out.println(Arrays.toString(score));
                ASSERT(score[0] == score[1]);
            }

            StringBuilder sb = new StringBuilder();
            for (boolean a : color) {
                sb.append(a ? 'A' : 'B');
            }
            out.println(sb);
        }

        private static void ASSERT(boolean assertion) {
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