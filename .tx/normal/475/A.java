import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    String toStr(int[] a) {
        char[] res = new char[22];
        Arrays.fill(res, '.');
        for (int i = 0; i < 11; i++) {
            if (a[i] == 1) {
                res[i * 2] = 'O';
            } else if (a[i] == 0) {
                res[i * 2] = '#';
            }
        }
        return String.valueOf(res);
    }

    void solve() throws IOException {
        int k = nextInt();
        int[][] a = new int[4][11];
        for (int i = 1; i < 11; i++) {
            a[2][i] = -1;
        }
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 4; j++) {
                if (k > 0 && a[j][i] == 0) {
                    a[j][i] = 1;
                    k--;
                }
            }
        }
        println("+------------------------+");
        printf("|%s|D|)%n", toStr(a[0]));
        printf("|%s|.|%n", toStr(a[1]));
        printf("|%s..|%n", toStr(a[2]));
        printf("|%s|.|)%n", toStr(a[3]));
        println("+------------------------+");
    }

    void run() {
        try {
            solve();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        } finally {
            close();
        }
    }

    Main() throws IOException {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String filename) throws IOException {
        super("".equals(filename) ? "output.txt" : filename + ".out");
        in = new BufferedReader(new FileReader("".equals(filename) ? "input.txt" : filename + ".in"));
    }

    public static void main(String[] args) throws IOException {
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

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    int[] nextIntArray(int len) throws IOException {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[i];
            a[i] = a[x];
            a[x] = _;
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