import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    int killAtk(List<Integer> atk, List<Integer> def, int[] a) {
        int x = min(atk.size(), a.length);
        int res = 0;
        int ats = 0, as = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j <= i; j++) {
                if (a[a.length - 1 - j] < atk.get(i - j)) {
                    return res;
                }
            }
            ats += atk.get(i);
            as += a[a.length - 1 - i];
            res = max(res, as - ats);
        }
        return res;
    }

    int killAll(List<Integer> atk, List<Integer> def, int[] a) {
        if (atk.size() + def.size() >= a.length) {
            return 0;
        }
        boolean[] used = new boolean[a.length];
        int kk = 0;
        for (int x : def) {
            int m = -1;
            for (int i = 0; i < a.length; i++) {
                if (!used[i] && a[i] > x && (m == -1 || a[i] < a[m])) {
                    m = i;
                }
            }
            if (m == -1) {
                return 0;
            }
            kk++;
            used[m] = true;
        }
        int ad = 0;
        List<Integer> ra = new ArrayList<>();
        for (int i = 0; i < a.length; i++) {
            if (!used[i]) {
                ra.add(a[i]);
            }
        }

        for (int i = 0; i < atk.size(); i++) {
            int x = atk.get(atk.size() - 1 - i);
            int y = ra.get(ra.size() - 1 - i);
            if (x > y) {
                return 0;
            }
            ad += y - x;
        }

        for (int i = atk.size(); i < ra.size(); i++) {
            ad += ra.get(ra.size() - 1 - i);
        }

        return ad;
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        List<Integer> atk = new ArrayList<>();
        List<Integer> def = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String x = next();
            int str = nextInt();
            if ("ATK".equals(x)) {
                atk.add(str);
            } else {
                def.add(str);
            }
        }
        atk.sort(Integer::compare);
        def.sort(Integer::compare);
        int[] a = nextIntArray(m);
        Arrays.sort(a);


        int all = killAll(atk, def, a);
        int at = killAtk(atk, def, a);
        println(max(all, at));
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
}