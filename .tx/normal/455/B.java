import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO io;

    int n, k;
    List<String> a;

    boolean dfs(int l, int r, int d, int x) {
        if (l + 1 == r) {
            return (a.get(l).length() - d) % 2 == x;
        }
        boolean res = false;
        while (l < r) {
            char c = a.get(l).charAt(d);
            int l1 = l, r1 = r, m;
            while (r1 - l1 > 1) {
                m = (r1 + l1) / 2;
                if (a.get(m).charAt(d) == c) {
                    l1 = m;
                } else {
                    r1 = m;
                }
            }
            if (dfs(l, l1 + 1, d + 1, x)) {
                return false;
            }
            l = l1 + 1;
        }
        return true;
    }

    // File names!!!

    void solve() throws Exception {
        n = io.nextInt();
        k = io.nextInt();
        String[] t = new String[n];
        for (int i = 0; i < n; i++) {
            t[i] = io.nextLine();
        }
        Arrays.sort(t);
        a = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            if (!t[i + 1].startsWith(t[i])) {
                a.add(t[i]);
            }
        }
        a.add(t[n - 1]);
        boolean res1 = dfs(0, a.size(), 0, 0);
        boolean res2 = dfs(0, a.size(), 0, 1);
        if (res1) {
            io.println("Second");
        } else if (!res2) {
            io.println("First");
        } else {
            io.println(k % 2 == 0 ? "Second" : "First");
        }
    }

    void run() {
        try {
            io = new FastIO();
            solve();
            io.close();
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

    class FastIO extends PrintWriter {
        private BufferedReader in;
        private StringTokenizer stok;

        FastIO() {
            super(System.out);
            in = new BufferedReader(new InputStreamReader(System.in));
        }

        FastIO(String s) throws FileNotFoundException {
            super("".equals(s) ? "output.txt" : s + ".out");
            in = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
        }

        @Override
        public void close() {
            super.close();
            try {
                in.close();
            } catch (IOException ignored) {
            }
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

        char nextChar() {
            try {
                return (char) in.read();
            } catch (IOException e) {
                return (char) -1;
            }
        }

        String nextLine() {
            try {
                return in.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        char[] nextCharArray() {
            return next().toCharArray();
        }
    }

    void shuffle(int[] a) {
        Random rand = new Random();
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int chg = a[i];
            a[i] = a[x];
            a[x] = chg;
        }
    }

    class IntArray {
        private int capacity;
        private int[] data;
        private int size = 0;

        IntArray(int capacity) {
            this.capacity = capacity;
            this.data = new int[capacity];
        }

        IntArray() {
            this(16);
        }

        int get(int index) {
            return data[index];
        }

        void add(int x) {
            if (size == capacity) {
                int[] newData = new int[capacity * 2];
                System.arraycopy(data, 0, newData, 0, capacity);
                data = newData;
                capacity *= 2;
            }
            data[size++] = x;
        }
    }
}