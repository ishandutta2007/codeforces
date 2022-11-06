import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    int[] l;
    int[] r;

    int getR(int i) {
        if (r[i] == -1) {
            return i;
        }
        return r[i] = getR(r[i]);
    }

    void solve() throws IOException {
        int n = nextInt();
        int[] a = nextIntArray(n);
        int[] sa = Arrays.copyOf(a, n);
        Arrays.sort(sa);
        int[] back = new int[n];
        for (int i = 0; i < n; i++) {
            int x = Arrays.binarySearch(sa, a[i]);
            back[x] = a[i];
            a[i] = x;
        }
        l = new int[n];
        r = new int[n];
        Arrays.fill(l, -1);
        Arrays.fill(r, -1);
        TreeSet<Integer> st = new TreeSet<>();
        int root = a[0];
        st.add(a[0]);
        for (int i = 1; i < n; i++) {
            Integer x = st.ceiling(a[i]);
            if (x == null) {
                int y = getR(root);
                r[y] = a[i];
                print(back[y]);
                print(" ");
            } else {
                if (l[x] == -1) {
                    print(back[x]);
                    print(" ");
                    l[x] = a[i];
                } else {
                    int y = getR(l[x]);
                    print(back[y]);
                    print(" ");
                    r[y] = a[i];
                }
            }
            st.add(a[i]);
        }
    }

    BufferedReader in;
    StringTokenizer stok;

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

    void println(Object... a) {
        for (int i = 0; i < a.length; i++) {
            if (i != 0) {
                print(" ");
            }
            print(a[i]);
        }
        println();
    }
}