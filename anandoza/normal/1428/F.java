import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.Comparator;
import java.util.ArrayDeque;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        FFruitSequences solver = new FFruitSequences();
        solver.solve(1, in, out);
        out.close();
    }

    static class FFruitSequences {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] s = in.readBitString();

            out.println(solve(s));
        }

        private static long solve(int[] s) {
            final int n = s.length;
            List<FFruitSequences.B> blocks = new ArrayList<>();
            for (int i = 0, j = 0; i < n; i = j) {
                while (j < n && s[i] == s[j])
                    j++;

                if (s[i] == 1)
                    blocks.add(new FFruitSequences.B(i, j, FFruitSequences.Type.FULL));
            }

            Collections.sort(blocks, Comparator.comparingInt(p -> -(p.second - p.first)));
            Queue<FFruitSequences.B> startQ = new ArrayDeque<>();
            Queue<FFruitSequences.B> endQ = new ArrayDeque<>();
            startQ.addAll(blocks);
            endQ.addAll(blocks);
            for (FFruitSequences.B p : startQ) {
                int l = p.first, r = p.second;
                for (int i = l + 1; i < r; i++) {
                    blocks.add(new FFruitSequences.B(i, r, FFruitSequences.Type.RIGHT));
                }
                for (int i = l + 1; i < r; i++) {
                    blocks.add(new FFruitSequences.B(l, i, FFruitSequences.Type.LEFT));
                }
            }
            Collections.sort(blocks, Comparator.comparingInt(p -> -(p.second - p.first)));

            long ans = 0;
            TreeSet<Integer> ends = new TreeSet<>();
            ends.add(0);
            TreeSet<Integer> starts = new TreeSet<>();
            starts.add(n);
            for (FFruitSequences.B p : blocks) {
                // System.out.println("p = " + p);
                int l = p.first, r = p.second;
                while (!startQ.isEmpty() && startQ.peek().second - startQ.peek().first >= r - l + 1) {
                    FFruitSequences.B next = startQ.poll();
                    starts.add(next.first);
                }

                while (!endQ.isEmpty() && endQ.peek().second - endQ.peek().first >= r - l) {
                    FFruitSequences.B next = endQ.poll();
                    ends.add(next.second);
                }

                if (p.type == FFruitSequences.Type.FULL) {
                    int size = r - l;
                    long leftBoundary = Math.max(ends.floor(l) - size + 1, 0);
                    long rightBoundary = Math.min(starts.ceiling(r) + size, n);
                    long poss = (l - leftBoundary + 1) * (rightBoundary - r + 1);
                    // System.out.println("poss * size = " + poss + " " + size);
                    ans += poss * size;

                    for (int len = size - 2; len > 0; len--) {
                        ans += (long) len * (size - len - 1);
                    }
                }
                if (p.type == FFruitSequences.Type.RIGHT) {
                    int size = r - l;
                    long leftBoundary = l;
                    long rightBoundary = Math.min(starts.ceiling(r) + size, n);
                    long poss = (l - leftBoundary + 1) * (rightBoundary - r + 1);
                    // System.out.println("poss * size = " + poss + " " + size);
                    ans += poss * size;
                }
                if (p.type == FFruitSequences.Type.LEFT) {
                    int size = r - l;
                    long leftBoundary = Math.max(ends.floor(l) - size + 1, 0);
                    long rightBoundary = r;
                    long poss = (l - leftBoundary + 1) * (rightBoundary - r + 1);
                    // System.out.println("poss * size = " + poss + " " + size);
                    ans += poss * size;
                }
            }

            return ans;
        }

        enum Type {
            LEFT,
            RIGHT,
            FULL,
            ;
        }

        private static class B {
            final int first;
            final int second;
            final FFruitSequences.Type type;

            private B(int first, int second, FFruitSequences.Type type) {
                this.first = first;
                this.second = second;
                this.type = type;
            }

            public String toString() {
                return "B{" + "first=" + first + ", second=" + second + ", type=" + type + '}';
            }

        }

    }

    static class InputReader {
        public final BufferedReader reader;
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

        public int[] readBitString() {
            char[] chars = next().toCharArray();
            int[] x = new int[chars.length];
            for (int i = 0; i < x.length; i++) {
                x[i] = chars[i] - '0';
            }
            return x;
        }

    }
}