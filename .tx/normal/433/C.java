import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO io;

    // File names!!!

    void solve() throws Exception {
        int n = io.nextInt();
        int m = io.nextInt();
        int[] a = new int[m];
        IntArray[] b = new IntArray[n];
        for (int i = 0; i < n; i++) {
            b[i] = new IntArray();
        }
        for (int i = 0; i < m; i++) {
            a[i] = io.nextInt() - 1;
            if (i > 0 && a[i] != a[i - 1]) {
                b[a[i]].add(a[i - 1]);
                b[a[i - 1]].add(a[i]);
            }
        }

        long orig = 0;
        for (int i = 1; i < m; i++) {
            orig += abs(a[i - 1] - a[i]);
        }

        long ans = orig;

        for (int i = 0; i < n; i++) {
            if (b[i].size == 0) {
                continue;
            }
            IntArray v = b[i];
            v.sort();
            int x = v.get(v.size / 2);
            long s = orig;
            for (int j = 0; j < v.size; j++) {
                s += abs(v.get(j) - x) - abs(v.get(j) - i);
            }
            ans = min(s, ans);
        }
        io.println(ans);
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

        void sort() {
            Arrays.sort(data, 0, size);
        }
    }

    void randomShuffle(int[] a) {
        Random random = new Random();
        for (int i = 1; i < a.length; i++) {
            int x = random.nextInt(i + 1);
            int xchg = a[i];
            a[i] = a[x];
            a[x] = xchg;
        }
    }
}