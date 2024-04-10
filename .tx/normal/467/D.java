import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    Random rand = new Random(31);

    Map<String, Integer> map = new HashMap<>();
    List<Integer>[] gr;
    long[] r, len;

    int countR(String s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'r') {
                res++;
            }
        }
        return res;
    }

    boolean[] used;
    void dfs(int v, int from) {
        used[v] = true;
        r[v] = r[from];
        len[v] = len[from];
        for (int i : gr[v]) {
            if (!used[i]) {
                dfs(i, from);
            }
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        String[] a = new String[n];
        for (int i = 0; i < n; i++) {
            a[i] = next().toLowerCase();
        }
        List<String> b = new ArrayList<>();
        int m = nextInt();
        gr = genAdjacencyList(2 * m);
        r = new long[2 * m];
        len = new long[2 * m];
        int tt;
        for (int i = 0; i < m; i++) {
            String x = next().toLowerCase();
            String y = next().toLowerCase();
            if (!map.containsKey(x)) {
                map.put(x, tt = map.size());
                r[tt] = countR(x);
                len[tt] = x.length();
                b.add(x);
            }
            if (!map.containsKey(y)) {
                map.put(y, tt = map.size());
                r[tt] = countR(y);
                len[tt] = y.length();
                b.add(y);
            }
            gr[map.get(y)].add(map.get(x));
        }
        m = map.size();
        Collections.sort(b, (o1, o2) -> {
            int x = map.get(o1);
            int y = map.get(o2);
            return Long.signum(r[x] == r[y] ? len[x] - len[y] : r[x] - r[y]);
        });

        used = new boolean[m];
        for (String s : b) {
            int ns = map.get(s);
            if (!used[ns]) {
                dfs(ns, ns);
            }
        }

        long ansR = 0, ansLen = 0;
        for (String s : a) {
            Integer ns = map.get(s);
            if (ns == null) {
                ansR += countR(s);
                ansLen += s.length();
            } else {
                ansR += r[ns];
                ansLen += len[ns];
            }
        }
        printf("%d %d", ansR, ansLen);
    }

    void run() throws IOException {
        try {
            solve();
            close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    public static void main(String[] args) throws IOException {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignore) {
        }
        new Main().run();
    }

    Main() {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws FileNotFoundException {
        super("".equals(s) ? "output.txt" : s + ".out");
        br = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
    }

    String next() {
        try {
            while (stok == null || !stok.hasMoreTokens()) {
                stok = new StringTokenizer(br.readLine());
            }
        } catch (IOException e) {
            return null;
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

    int[] nextIntArray(int len) {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
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

    <T> List<T>[] genAdjacencyList(int countVertex) {
        List<T>[] res = new List[countVertex];
        for (int i = 0; i < countVertex; i++) {
            res[i] = new ArrayList<T>();
        }
        return res;
    }
}