import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.BitSet;
import java.util.ArrayDeque;
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
        ETheCakeIsALie solver = new ETheCakeIsALie();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETheCakeIsALie {
        private static final int K = 3;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            ETheCakeIsALie.P[] pieces = new ETheCakeIsALie.P[n - 2];
            for (int i = 0; i < n - 2; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1, c = in.nextInt() - 1;
                pieces[i] = new ETheCakeIsALie.P(i, a, b, c);
            }

            int[] deg = new int[n];
            for (ETheCakeIsALie.P p : pieces) {
                for (int i = 0; i < K; i++) {
                    deg[p.a[i]]++;
                }
            }
            Queue<ETheCakeIsALie.P>[] piecesMap = new ArrayDeque[n];
            for (int i = 0; i < n; i++) {
                piecesMap[i] = new ArrayDeque<>(0);
            }
            for (ETheCakeIsALie.P p : pieces) {
                for (int i = 0; i < K; i++) {
                    piecesMap[p.a[i]].add(p);
                }
            }

            Queue<Integer> q = new ArrayDeque<>();
            int[] order = new int[n - 2];
            int orderIndex = 0;
            BitSet queued = new BitSet();
            BitSet processed = new BitSet();
            for (int i = 0; i < n; i++) {
                if (deg[i] == 1) {
                    q.add(i);
                    queued.set(i);
                }
            }
            while (!q.isEmpty()) {
                int cur = q.poll();
                outer:
                while (!piecesMap[cur].isEmpty()) {
                    ETheCakeIsALie.P p = piecesMap[cur].poll();
                    for (int j : p.a) {
                        if (processed.get(j))
                            continue outer;
                    }
                    order[orderIndex++] = p.i;
                    processed.set(cur);
                    for (int j : p.a) {
                        if (queued.get(j))
                            continue;
                        deg[j]--;
                        if (deg[j] == 1) {
                            q.add(j);
                            queued.set(j);
                        }
                    }
                }
            }

            int[] ll = new int[n];
            Arrays.fill(ll, -1);
            int last = processed.nextClearBit(0);
            int last2 = processed.nextClearBit(last + 1);
            ll[last] = last2;
            ll[last2] = last;

            int[] reverse = order.clone();
            Util.reverse(reverse);
            for (int i : reverse) {
                ETheCakeIsALie.P p = pieces[i];
                for (int cur : p.a) {
                    if (cur == -1 || ll[cur] == -1)
                        continue;
                    int o = p.match(cur, ll[cur]);
                    if (o != -1) {
                        ll[o] = ll[cur];
                        ll[cur] = o;
                        break;
                    }
                }
            }

            // Print output
            int cur = 0;
            do {
                out.print((cur + 1) + " ");
                cur = ll[cur];
            } while (cur != 0);
            out.println();

            for (int i : order) {
                out.print((i + 1) + " ");
            }
            out.println();
        }

        private static class P {
            final int i;
            final int[] a;

            private P(int i, int a, int b, int c) {
                this.i = i;
                this.a = new int[]{a, b, c};
                Arrays.sort(this.a);
            }

            public String toString() {
                return "P{" + "i=" + i + ", a=" + Arrays.toString(a) + '}';
            }

            public int match(int i, int j) {
                boolean m1 = false, m2 = false;
                for (int k = 0; k < K; k++) {
                    if (a[k] == i)
                        m1 = true;
                    if (a[k] == j)
                        m2 = true;
                }
                if (!m1 || !m2)
                    return -1;
                return a[0] ^ a[1] ^ a[2] ^ i ^ j;
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

    }

    static class Util {
        public static void swap(int[] x, int i, int j) {
            int t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        public static void reverse(int[] x) {
            for (int i = 0, j = x.length - 1; i < j; i++, j--) {
                swap(x, i, j);
            }
        }

        private Util() {
        }

    }
}