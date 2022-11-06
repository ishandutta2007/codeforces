import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO in;
    PrintWriter out;

    final static Random rand = new Random(3114);

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[i];
            a[i] = a[x];
            a[x] = _;
        }
    }

    <T> void add(Map<T, Integer> m, T key, int x) {
        Integer t = m.get(key);
        if (t == null ) {
            t = 0;
        }
        t += x;
        if (t == 0) {
            m.remove(key);
        } else {
            m.put(key, t);
        }
    }

    class Item implements Comparable<Item> {
        int s, id;

        Item(int s, int id) {
            this.s = s;
            this.id = id;
        }

        @Override
        public int compareTo(Item o) {
            return s == o.s ? id - o.id : s - o.s;
        }
    }

    // File names!!!

    void solve() throws IOException {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        shuffle(a);
        Arrays.sort(a);
        TreeSet<Item> ts = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            ts.add(new Item(a[i], i));
        }

        boolean[] used = new boolean[n];

        for (int i = n / 2 - 1; i >= 0; i--) {
//            if (used[i]) continue;

            Item c = new Item(a[i] * 2, -1);
            Item r = ts.ceiling(c);
            if (r == null) {
                continue;
            }
            used[r.id] = true;
            ts.remove(r);
            ts.remove(new Item(a[i], i));
        }

        int kused = 0;
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                kused++;
            }
        }
        out.println(n - kused);

    }

    void run() {
        try {
            in = new FastIO();
            solve();
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    public static void main(String[] args) {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignore) {
        }
        new Main().run();
    }

    class FastIO {
        private BufferedReader in;

        private StringTokenizer stok;

        FastIO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }

        FastIO(String s) throws FileNotFoundException {
            if ("".equals(s)) {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            } else {
                in = new BufferedReader(new FileReader(s + ".in"));
                out = new PrintWriter(s + ".out");
            }
        }

        void close() throws IOException {
            in.close();
            out.close();
        }

        String next() {
            while (stok == null || !stok.hasMoreTokens()) {
                try {
                    stok = new StringTokenizer(in.readLine());
                } catch (Exception e) {
                    return null;
                }
            }
            return stok.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}