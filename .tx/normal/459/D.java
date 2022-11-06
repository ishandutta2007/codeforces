import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main extends PrintWriter {
    class Fenv {
        long[] a;

        Fenv(int n) {
            a = new long[n];
        }

        long get(int r) {
            long s = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1) {
                s += a[r];
            }
            return s;
        }

        void add(int i, long x) {
            for (; i < a.length; i |= i + 1) {
                a[i] += x;
            }
        }
    }

    class Item implements Comparable<Item> {
        int x, id;

        public Item(int x, int id) {
            this.x = x;
            this.id = id;
        }

        @Override
        public int compareTo(Item o) {
            return x == o.x ? Integer.compare(id, o.id) : Integer.compare(x, o.x);
        }
    }

    void run() {
        int n = nextInt();
        int[] l = new int[n];
        int[] r = new int[n];
        Item[] a = new Item[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Item(nextInt(), i);
        }
        Arrays.sort(a);
        int lst = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].x != a[lst].x) {
                lst = i;
            }
            l[a[i].id] = i - lst + 1;
        }

        lst = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i].x != a[lst].x) {
                lst = i;
            }
            r[a[i].id] = lst - i + 1;
        }

        Fenv f = new Fenv(n + 1);
        for (int i = 0; i < n; i++) {
            f.add(r[i], 1);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            f.add(r[i], -1);
            ans += f.get(l[i] - 1);
        }

        println(ans);
    }

    public static void main(String[] args) throws IOException {
        InputStream is = args.length == 0 ? System.in : new FileInputStream("input.txt");
        OutputStream os = args.length == 0 ? System.out : System.out;
        try (Main main = new Main(is, os)) {
            main.run();
        }
    }

    public Main(InputStream is, OutputStream os) {
        super(os, false);
        br = new BufferedReader(new InputStreamReader(is));
        stok = new StringTokenizer("");
    }

    BufferedReader br;
    StringTokenizer stok;

    String nextToken() {
        while (!stok.hasMoreTokens()) {
            String s;
            try {
                s = br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    long nextLong() {
        return Long.parseLong(nextToken());
    }
}