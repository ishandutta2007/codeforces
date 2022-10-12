import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        ECountTheRectangles solver = new ECountTheRectangles();
        solver.solve(1, in, out);
        out.close();
    }

    static class ECountTheRectangles {
        private static final int MAX = 5000;
        private static final int SIZE = MAX * 2 + 1;
        ECountTheRectangles.Item[] items;
        int itemCount = 0;
        IntSumSegmentTree tree;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            items = new ECountTheRectangles.Item[2 * n];
            itemCount = 0;
            for (int i = 0; i < n; i++) {
                int x1 = MAX + in.nextInt();
                int y1 = MAX + in.nextInt();
                int x2 = MAX + in.nextInt();
                int y2 = MAX + in.nextInt();

                if (x1 == x2) {
                    int yl = Math.min(y1, y2);
                    int yh = Math.max(y1, y2);
                    items[itemCount++] = new ECountTheRectangles.Item(x1, yl, yh);
                } else {
                    int xl = Math.min(x1, x2);
                    int xh = Math.max(x1, x2);
                    items[itemCount++] = new ECountTheRectangles.Item(xl, y1, true);
                    items[itemCount++] = new ECountTheRectangles.Item(xh, y1, false);
                }
            }

            Arrays.sort(items, 0, itemCount, Comparator.comparingInt((ECountTheRectangles.Item i) -> i.x).thenComparingInt(i -> {
                if (!i.isPoint)
                    return 0;
                return i.start ? -1 : 1;
            }));

            long answer = 0;
            tree = new IntSumSegmentTree(SIZE);
            for (int i = 0; i < itemCount; i++) {
                ECountTheRectangles.Item item = items[i];
                if (!item.isPoint) {
                    answer += count(i);
                }
            }

            out.println(answer);
        }

        private long count(int start) {
            ECountTheRectangles.Item left = items[start];
            long result = 0;
            for (int i = 0; i < start; i++) {
                ECountTheRectangles.Item item = items[i];
                if (item.isPoint) {
                    if (item.y >= left.y && item.y <= left.y2) {
                        if (item.start)
                            tree.update_LAZY(item.y, 1);
                        else
                            tree.update_LAZY(item.y, 0);
                    }
                }
            }

            tree.rebuild();

            for (int i = start + 1; i < itemCount; i++) {
                ECountTheRectangles.Item item = items[i];
                if (item.isPoint) {
                    if (!item.start && item.y >= left.y && item.y <= left.y2) {
                        if (tree.get(item.y) == 1)
                            tree.update(item.y, 0);
                    }
                } else {
                    int yl = Math.max(left.y, item.y);
                    int yh = Math.min(left.y2, item.y2);

                    result += nc2(tree.query(yl, yh + 1));
                }
            }

            return result;
        }

        private static long nc2(long n) {
            return n * (n - 1) / 2;
        }

        private static class Item {
            int x;
            int y;
            int y2;
            boolean isPoint;
            boolean start;

            Item(int x, int y1, int y2) {
                this.x = x;
                this.y = y1;
                this.y2 = y2;
                isPoint = false;
            }

            Item(int x, int y, boolean start) {
                this.x = x;
                this.y = y;
                isPoint = true;
                this.start = start;
            }

            public String toString() {
                return String.format("(%d, %d, %d, %s, %s)", x - MAX, y - MAX, y2 - MAX, isPoint ? "P" : "L", start ? "S" : "E");
            }

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

    static class IntSumSegmentTree {
        public int size;
        public int[] value;

        public IntSumSegmentTree(int size) {
            this.size = size;
            value = new int[2 * size];
        }

        public void rebuild() {
            for (int i = size - 1; i > 0; i--) {
                value[i] = value[2 * i] + value[2 * i + 1];
            }
        }

        public int get(int i) {
            return value[size + i];
        }

        public void update(int i, int v) {
            i += size;
            value[i] = v;
            while (i > 1) {
                i /= 2;
                value[i] = value[2 * i] + value[2 * i + 1];
            }
        }

        public void update_LAZY(int i, int v) {
            i += size;
            value[i] = v;
        }

        public int query(int i, int j) {
            int res_left = 0, res_right = 0;
            for (i += size, j += size; i < j; i /= 2, j /= 2) {
                if ((i & 1) == 1) {
                    int b = value[i++];
                    res_left = res_left + b;
                }
                if ((j & 1) == 1) {
                    int a = value[--j];
                    res_right = a + res_right;
                }
            }
            return res_left + res_right;
        }

    }
}