import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    class Item {
        String name;
        int p, t, g;

        public Item(String name) {
            this.name = name;
            p = t = g = 0;
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int mp = 0, mt = 0, mg = 0;
        Item[] a = new Item[n];
        for (int i = 0; i < n; i++) {
            int s = nextInt();
            Item it = a[i] = new Item(next());
            for (int j = 0; j < s; j++) {
                char[] t = next().replace("-", "").toCharArray();
                boolean allOne = true;
                boolean desc = true;
                for (int k = 1; k < t.length; k++) {
                    if (t[k] != t[k - 1]) {
                        allOne = false;
                    }
                    if (t[k] >= t[k - 1]) {
                        desc = false;
                    }
                }
                if (allOne) {
                    it.t++;
                } else if (desc) {
                    it.p++;
                } else {
                    it.g++;
                }
            }
            mp = max(mp, it.p);
            mg = max(mg, it.g);
            mt = max(mt, it.t);
        }
        print("If you want to call a taxi, you should call:");
        boolean first = true;
        for (int i = 0; i < n; i++) {
            if (a[i].t == mt) {
                if (!first) {
                    print(",");
                }
                print(" ");
                print(a[i].name);
                first = false;
            }
        }
        println(".");
        print("If you want to order a pizza, you should call:");
        first = true;
        for (int i = 0; i < n; i++) {
            if (a[i].p == mp) {
                if (!first) {
                    print(",");
                }
                print(" ");
                print(a[i].name);
                first = false;
            }
        }
        println(".");
        print("If you want to go to a cafe with a wonderful girl, you should call:");
        first = true;
        for (int i = 0; i < n; i++) {
            if (a[i].g == mg) {
                if (!first) {
                    print(",");
                }
                print(" ");
                print(a[i].name);
                first = false;
            }
        }
        print(".");

    }

    Main() {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String fileIn, String fileOut) throws IOException {
        super(fileOut);
        in = new BufferedReader(new FileReader(fileIn));
    }

    public static void main(String[] args) throws IOException {
        Main main;
        if ("_std".equals(IO)) {
            main = new Main();
        } else if ("_iotxt".equals(IO)) {
            main = new Main("input.txt", "output.txt");
        } else {
            main = new Main(IO + ".in", IO + ".out");
        }
        main.solve();
        main.close();
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

    int[] nextIntArraySorted(int len) throws IOException {
        int[] a = nextIntArray(len);
        shuffle(a);
        Arrays.sort(a);
        return a;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[i];
            a[i] = a[x];
            a[x] = _;
        }
    }

    void shuffleAndSort(int[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    boolean nextPermutation(int[] p) {
        for (int a = p.length - 2; a >= 0; --a) {
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
        }
        return false;
    }

    <T> List<T>[] createAdjacencyList(int n) {
        List<T>[] res = new List[n];
        for (int i = 0; i < n; i++) {
            res[i] = new ArrayList<>();
        }
        return res;
    }
}