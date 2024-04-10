import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    class MinMaxStack {
        Deque<Integer> a = new ArrayDeque<>();
        Deque<Integer> min = new ArrayDeque<>();
        Deque<Integer> max = new ArrayDeque<>();

        void add(int x) {
            min.addLast(min(x, getMin()));
            max.addLast(max(x, getMax()));
            a.addLast(x);
        }

        int poll() {
            if (!isEmpty()) {
                min.pollLast();
                max.pollLast();
                return a.pollLast();
            }
            return inf;
        }

        int getMin() {
            if (isEmpty()) {
                return inf;
            }
            return min.getLast();
        }

        int getMax() {
            if (isEmpty()) {
                return -inf;
            }
            return max.getLast();
        }

        boolean isEmpty() {
            return a.isEmpty();
        }

        int size() {
            return a.size();
        }

        @Override
        public String toString() {
            return a.toString();
        }
    }

    class MinMaxQueue {
        MinMaxStack a = new MinMaxStack();
        MinMaxStack b = new MinMaxStack();

        void add(int x) {
            b.add(x);
        }

        int poll() {
            if (a.isEmpty()) {
                transfer();
            }
            return a.poll();
        }

        int getMin() {
            return min(a.getMin(), b.getMin());
        }

        int getMax() {
            return max(a.getMax(), b.getMax());
        }

        void transfer() {
            while (!b.isEmpty()) {
                a.add(b.poll());
            }
        }

        boolean isEmpty() {
            return a.isEmpty() && b.isEmpty();
        }

        int size() {
            return a.size() + b.size();
        }

        @Override
        public String toString() {
            return "a: " + a.toString() + ", b: " + b.toString();
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        int s = nextInt();
        int l = nextInt();
        int[] a = nextIntArray(n);
        MinMaxQueue q = new MinMaxQueue();
        MinMaxQueue b = new MinMaxQueue();
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            q.add(a[i]);
            if (q.size() - l + 1 > b.size()) {
                if (i >= l) {
                    b.add(d[i - l]);
                } else {
                    b.add(0);
                }
            }
            boolean fl = false;
            while (q.getMax() - q.getMin() > s) {
                q.poll();
                if (fl) {
                    fl = false;
                } else {
                    b.poll();
                }
            }
            d[i] = min(inf, b.getMin() + 1);
        }
        println(d[n - 1] == inf ? -1 : d[n - 1]);
    }

    public void run() {
        try {
            solve();
            close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    Main() throws IOException {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws IOException {
        super("".equals(s) ? "output.txt" : (s + ".out"));
        in = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : (s + ".in")));
    }

    public static void main(String[] args) throws IOException {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignored) {
        }
        new Main().run();
    }

    String next() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    int[] nextIntArray(int len) throws IOException {
        int[] a = new int[len];
        for (int i = 0; i < len; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[x];
            a[x] = t;
        }
    }

    boolean nextPerm(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
            if (p[a] < p[a + 1])
                for (int b = p.length - 1; ; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        return false;
    }

    <T> List<T>[] createAdjacencyList(int countVertex) {
        List<T>[] res = new List[countVertex];
        for (int i = 0; i < countVertex; i++) {
            res[i] = new ArrayList<T>();
        }
        return res;
    }
}