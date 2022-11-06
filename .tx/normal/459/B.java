import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO io;

    // File names!!!

    void solve() throws Exception {
        int n = io.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
        }
        shuffleSort(a);
        if (a[0] == a[n - 1]) {
            io.print("0 ");
            io.println(n * (n - 1L) / 2);
        } else {
            long c1 = 0, c2 = 0;
            for (int i = 0; a[i] == a[0]; i++) {
                c1++;
            }
            for (int i = n - 1; a[i] == a[n - 1]; i--) {
                c2++;
            }
            io.printf("%d %d", a[n - 1] - a[0], c1 * c2);
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

    void shuffleSort(int[] a) {
        Random rand = new Random();
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int chg = a[i];
            a[i] = a[x];
            a[x] = chg;
        }
        Arrays.sort(a);
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