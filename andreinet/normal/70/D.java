import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NavigableSet;
import java.io.IOException;
import java.util.TreeSet;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();

            PointContainer ref = new PointContainer();
            TreeSet<Point> S = new TreeSet<>((o1, o2) -> {
            /*double s1 = slope(ref.e, o1);
            double s2 = slope(ref.e, o2);*/
                int sgn = signCrossProduct(ref.e, o1, o2);
                if (sgn != 0) {
                    return -sgn;
                } else if (o1.x != o2.x) {
                    return Integer.compare(o1.x, o2.x);
                } else {
                    return Integer.compare(o1.y, o2.y);
                }
            });
            int maxx = -0x3f3f3f3f;
            while (q-- > 0) {
                int type = in.nextInt();
                Point p = new Point(in.nextInt(), in.nextInt());

                if (type == 1) {
                    maxx = Math.max(maxx, p.x);
                    if (ref.e == null) {
                        ref.e = p;
                        continue;
                    }
                    if (p.compareTo(ref.e) < 0) {
                        workHull(S, p, maxx);
                        Point prev = ref.e;
                        ref.e = p;
                        p = prev;
                    }
                    NavigableSet<Point> smaller = S.headSet(p, false);
                    while (smaller.size() >= 1) {
                        Point s = smaller.last();
                        Point f = smaller.lower(s);
                        if (f == null) f = ref.e;
                        if (signCrossProduct(f, s, p) <= 0) {
                            smaller.pollLast();
                        } else {
                            break;
                        }
                    }
                    Point d = S.higher(p);
                    if ((d == null || smaller.size() < 1) ||
                            (signCrossProduct(smaller.last(), p, d) > 0)) {
                        S.add(p);
                        NavigableSet<Point> bigger = S.tailSet(p, false);
                        while (bigger.size() >= 1) {
                            Point f = bigger.first();
                            Point s = bigger.higher(f);
                            if (s == null) s = ref.e;
                            if (signCrossProduct(p, f, s) <= 0) {
                                bigger.pollFirst();
                            } else {
                                break;
                            }
                        }
                    }
                } else {
                    //check(S, ref.e);
                    if (p.compareTo(ref.e) < 0) {
                        out.println("NO");
                    } else if (p.compareTo(ref.e) == 0) {
                        out.println("YES");
                    } else {
                        Point f = S.lower(p);
                        Point s = S.ceiling(p);
                        if (f != null && signCrossProduct(ref.e, p, f) == 0 &&
                                between(ref.e, p, f)) {
                            out.println("YES");
                        } else if (s != null && signCrossProduct(ref.e, p, s) == 0 &&
                                between(ref.e, p, s)) {
                            out.println("YES");
                        } else if (f == null || s == null) {
                            out.println("NO");
                        } else if (signCrossProduct(ref.e, f, s) *
                                signCrossProduct(p, f, s) >= 0) {
                            out.println("YES");
                        } else {
                            out.println("NO");
                        }
                    }
                }
            }
        }

        private void workHull(TreeSet<Point> S, Point p, int maxx) {
            while (S.size() >= 2) {
                Point f = S.first();
                Point s = S.higher(f);
                if (f.x == maxx) break;
                if (signCrossProduct(p, f, s) <= 0) {
                    S.pollFirst();
                } else {
                    break;
                }
            }
            while (S.size() >= 2) {
                Point s = S.last();
                Point f = S.lower(s);
                if (s.x == maxx) break;
                if (signCrossProduct(p, f, s) <= 0) {
                    S.pollLast();
                } else {
                    break;
                }
            }
        }

        private boolean between(Point a, Point b, Point c) {
            if (a.x == c.x) {
                return a.y <= b.y && b.y <= c.y;
            } else {
                return a.x <= b.x && b.x <= c.x;
            }
        }

        private int signCrossProduct(Point o, Point a, Point b) {
            long c = (long) (a.x - o.x) * (b.y - o.y) -
                    (long) (a.y - o.y) * (b.x - o.x);
            if (c < 0) return -1;
            else if (c > 0) return 1;
            return 0;
        }

        private class Point {
            int x;
            int y;

            Point(int x, int y) {
                this.x = x;
                this.y = y;
            }

            private int compareTo(Point other) {
                return x != other.x ? Integer.compare(x, other.x) :
                        Integer.compare(y, other.y);
            }


            public String toString() {
                return "(" + x + ", " + y + ")";
            }

        }

        private class PointContainer {
            public Point e;

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
}