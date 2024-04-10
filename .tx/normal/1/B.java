import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    char[] t = new char[1000000];
    int to(int x) {
        int i = 0;
        while (x > 0) {
            t[i] = x % 26 == 0 ? 'Z' : (char) (x % 26 + 'A' - 1);
            x = (x - 1) / 26;
            i++;
        }
        return i;
    }

    int from(String s) {
        int res = 0;
        int p = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            res += (s.charAt(i) - 'A' + 1) * p;
            p *= 26;
        }
        return res;
    }

    public void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String s = next();
            if (s.matches("R\\d+C\\d+")) {
                StringTokenizer st = new StringTokenizer(s, "RC");
                int r = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                int p = to(c);
                for (int j = p - 1; j >= 0; j--) {
                    print(t[j]);
                }
                println(r);
            } else {
                int p = -1;
                for (int j = 0; j < s.length(); j++) {
                    if (Character.isDigit(s.charAt(j))) {
                        p = j;
                        break;
                    }
                }
                String c = s.substring(0, p);
                String r = s.substring(p);
                println("R" + r + "C" + from(c));
            }
        }
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