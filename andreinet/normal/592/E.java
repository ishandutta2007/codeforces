import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Comparator;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), c = in.nextInt(), d = in.nextInt();
            int zeroPositive = 0, zeroNegative = 0;

            List<Pairii> poz = new ArrayList<>();
            List<Pairii> neg = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt() - c;
                int y = in.nextInt() - d;
                if (y == 0) {
                    if (x < 0) {
                        zeroNegative++;
                    } else {
                        zeroPositive++;
                    }
                } else {
                    (y < 0 ? neg : poz).add(new Pairii(x, y));
                }
            }

            Comparator<Pairii> cmp = (o1, o2) ->
                    Long.compare((long) o1.first * o2.second,
                            (long) o2.first * o1.second);

            Collections.sort(poz, cmp);
            Collections.sort(neg, cmp);

            int[] nl = new int[neg.size()], pl = new int[neg.size()];
            int[] nr = new int[neg.size()], pr = new int[neg.size()];


            long ans = 0;
            for (Pairii p : poz) {
                int p1 = search1(neg, p, cmp);
                int p2 = search2(neg, p, cmp);

                ans += (long) (p1 + 1) * (neg.size() - p2);
            }
            for (Pairii p : neg) {
                int p1 = search1(poz, p, cmp);
                int p2 = search2(poz, p, cmp);
                ans += (long) (p1 + 1) * (poz.size() - p2);
            }
            for (Pairii p : poz) {
                int p1 = search1(neg, p, cmp);
                int p2 = search2(neg, p, cmp);

                ans += (long) (neg.size() - p2) * zeroPositive;
                ans += (long) (p1 + 1) * zeroNegative;
            }

            out.println(ans);
        }

        private int search1(List<Pairii> a, Pairii e, Comparator<Pairii> cmp) {
            int pos = -1, step;
            for (step = 1; step < a.size(); step *= 2) ;
            for (; step > 0; step /= 2) {
                if (pos + step < a.size() && cmp.compare(a.get(pos + step), e) > 0)
                    pos += step;
            }
            return pos;
        }

        private int search2(List<Pairii> a, Pairii e, Comparator<Pairii> cmp) {
            int pos = a.size(), step;
            for (step = 1; step < a.size(); step *= 2) ;
            for (; step > 0; step /= 2) {
                if (pos - step >= 0 && cmp.compare(a.get(pos - step), e) < 0)
                    pos -= step;
            }
            return pos;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class Pairii implements Comparable<Pairii> {
        public int first;
        public int second;

        public Pairii() {
        }

        public Pairii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pairii other) {
            if (first != other.first) return first < other.first ? -1 : 1;
            if (second != other.second) return second < other.second ? -1 : 1;
            return 0;
        }

        public boolean equals(Object other) {
            if (!(other instanceof Pairii)) return false;
            return compareTo((Pairii) other) == 0;
        }

        public int hashCode() {
            return first * 31 + second;
        }

    }
}