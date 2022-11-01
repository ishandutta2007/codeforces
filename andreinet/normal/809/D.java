import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.IOException;
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
        static Random rnd = new Random();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            TaskD.Node root = null;
            for (int i = 0; i < n; ++i) {
                int l = in.nextInt(), r = in.nextInt();

                TaskD.Node left, mid, right;
                Pair<TaskD.Node, TaskD.Node> spl = split(root, l);
                left = spl.first;
                spl = split(spl.second, r);
                mid = spl.first;
                right = spl.second;

                int cvalue;
                if (left == null) {
                    cvalue = 1;
                } else {
                    left.doLazy();
                    cvalue = left.maxDp + 1;
                }
                if (mid != null) {
                    mid.lazyDp += 1;
                    mid.lazyKey += 1;
                }
                mid = insert(mid, l, cvalue);
                TaskD.Node lastMid = getLast(mid), firstRight = getFirst(right);
                if (lastMid != null && firstRight != null && lastMid.dp == firstRight.dp) {
                    right = remove(right, firstRight.key);
                }

                root = merge(merge(left, mid), right);
            }

            int ans;
            if (root == null) {
                ans = 0;
            } else {
                root.doLazy();
                ans = root.maxDp;
            }
            out.println(ans);
        }

        static Pair<TaskD.Node, TaskD.Node> split(TaskD.Node node, int value) {
            if (node == null) {
                return Pair.makePair(null, null);
            }

            node.doLazy();
            if (value <= node.key) {
                Pair<TaskD.Node, TaskD.Node> spl = split(node.left, value);
                node.left = spl.second;
                node.update();
                spl.second = node;
                return spl;
            } else {
                Pair<TaskD.Node, TaskD.Node> spl = split(node.right, value);
                node.right = spl.first;
                node.update();
                spl.first = node;
                return spl;
            }
        }

        static TaskD.Node merge(TaskD.Node left, TaskD.Node right) {
            if (left == null && right == null) return null;
            if (left == null) return right;
            if (right == null) return left;

            if (left.pry > right.pry) {
                left.doLazy();
                left.right = merge(left.right, right);
                left.update();
                return left;
            } else {
                right.doLazy();
                right.left = merge(left, right.left);
                right.update();
                return right;
            }
        }

        static TaskD.Node insert(TaskD.Node root, int key, int dp) {
            return insert(root, key, rnd.nextInt(), dp);
        }

        static TaskD.Node insert(TaskD.Node node, int key, int pry, int dp) {
            if (node == null) {
                return new TaskD.Node(key, pry, dp);
            } else {
                node.doLazy();
                if (pry > node.pry) {
                    TaskD.Node aux = new TaskD.Node(key, pry, dp);
                    Pair<TaskD.Node, TaskD.Node> spl = split(node, key);
                    aux.left = spl.first;
                    aux.right = spl.second;
                    aux.update();
                    return aux;
                } else if (key <= node.key) {
                    node.left = insert(node.left, key, pry, dp);
                    node.update();
                    return node;
                } else {
                    node.right = insert(node.right, key, pry, dp);
                    node.update();
                    return node;
                }
            }
        }

        static TaskD.Node remove(TaskD.Node node, int key) {
            if (node == null) {
                return null;
            } else {
                node.doLazy();
                if (node.key == key) {
                    return merge(node.left, node.right);
                } else if (key < node.key) {
                    node.left = remove(node.left, key);
                    node.update();
                    return node;
                } else {
                    node.right = remove(node.right, key);
                    node.update();
                    return node;
                }
            }
        }

        static TaskD.Node getFirst(TaskD.Node node) {
            if (node == null) {
                return null;
            }
            node.doLazy();
            if (node.left == null) {
                return node;
            } else {
                return getFirst(node.left);
            }
        }

        static TaskD.Node getLast(TaskD.Node node) {
            if (node == null) {
                return null;
            }
            node.doLazy();
            if (node.right == null) {
                return node;
            } else {
                return getLast(node.right);
            }
        }

        static class Node {
            int key;
            int pry;
            int dp;
            int maxDp;
            int lazyKey;
            int lazyDp;
            TaskD.Node left;
            TaskD.Node right;

            Node(int key, int pry, int dp) {
                this.key = key;
                this.pry = pry;
                this.dp = dp;
                this.maxDp = dp;
                this.lazyKey = 0;
                this.lazyDp = 0;
            }

            void doLazy() {
                if (lazyDp != 0) {
                    dp += lazyDp;
                    maxDp += lazyDp;
                    if (left != null) {
                        left.lazyDp += lazyDp;
                    }
                    if (right != null) {
                        right.lazyDp += lazyDp;
                    }
                    lazyDp = 0;
                }
                if (lazyKey != 0) {
                    key += lazyKey;
                    if (left != null) {
                        left.lazyKey += lazyKey;
                    }
                    if (right != null) {
                        right.lazyKey += lazyKey;
                    }
                    lazyKey = 0;
                }
            }

            void update() {
                doLazy();
                maxDp = dp;
                if (left != null) {
                    left.doLazy();
                    maxDp = Math.max(maxDp, left.maxDp);
                }
                if (right != null) {
                    right.doLazy();
                    maxDp = Math.max(maxDp, right.maxDp);
                }
            }

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

    static class Pair<T, V> implements Comparable<Pair<T, V>> {
        public T first;
        public V second;

        public static <T, V> Pair<T, V> makePair(T first, V second) {
            return new Pair(first, second);
        }

        public Pair() {
        }

        private Pair(T first, V second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair<T, V> other) {
            int comp = ((Comparable<T>) first).compareTo(other.first);
            if (comp != 0) return comp;
            return ((Comparable<V>) second).compareTo(other.second);
        }

        public boolean equals(Object other) {
            if (this == other) return true;
            if (other == null || getClass() != other.getClass()) return false;

            Pair pair = (Pair) other;

            return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);
        }

        public int hashCode() {
            int h1 = first == null ? 0 : first.hashCode();
            int h2 = second == null ? 0 : second.hashCode();
            return 31 * h1 + h2;
        }

    }
}