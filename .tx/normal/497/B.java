import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    class Item implements Comparable<Item> {
        int t, s;

        public Item(int t, int s) {
            this.t = t;
            this.s = s;
        }

        @Override
        public int compareTo(Item o) {
            return s == o.s ? t - o.t : s - o.s;
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int x = nextInt();
            if (x == 1) {
                a[i] = 1;
            } else {
                b[i] = 1;
            }
            a[i] += a[i - 1];
            b[i] += b[i - 1];
        }

        List<Item> ans = new ArrayList<>();
        for (int t = 1; t <= n; t++) {
            int pa = 0, pb = 0;
            boolean ok = true;
            int sa = 0;
            int sb = 0;
            int lastwon = -1;
            while (pa < n && pb < n) {
                int npa = binarySearch(a, pa, n + 1, a[pa] + t);
                int npb = binarySearch(b, pb, n + 1, b[pb] + t);
                if (npa < 0 && npb < 0) {
                    ok = false;
                    break;
                }
                if (npa < 0) {
                    pa = n - 1;
                    pb = npb;
                    sb++;
                    lastwon = 2;
                } else if (npb < 0) {
                    pa = npa;
                    pb = n - 1;
                    sa++;
                    lastwon = 1;
                } else {
                    int m = min(npa, npb);
                    if (npa < npb) {
                        sa++;
                        lastwon = 1;
                    } else {
                        sb++;
                        lastwon = 2;
                    }
                    pa = m;
                    pb = m;
                }
            }
            if (ok) {
                if (sa > sb && lastwon == 1) {
                    ans.add(new Item(t, sa));
                }
                if (sa < sb && lastwon == 2) {
                    ans.add(new Item(t, sb));
                }
            }
        }
        Collections.sort(ans);
        println(ans.size());
        for (Item an : ans) {
            print(an.s);
            print(" ");
            println(an.t);
        }
    }

    int binarySearch(int[] a, int l, int r, int key) {
        int m;
        while (r - l > 1) {
            m = (r + l) >> 1;
            if (a[m] < key) {
                l = m;
            } else {
                r = m;
            }
        }
        if (l + 1 < a.length && a[l + 1] == key) {
            return l + 1;
        }
        return -1;
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