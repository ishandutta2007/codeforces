import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    Random rand = new Random(31);

    void solve() throws IOException {
        String s = "qwertyuiopasdfghjkl;zxcvbnm,./";
        int x = next().equals("R") ? -1 : 1;
        String m = next();
        for (char i : m.toCharArray()) {
            print(s.charAt(s.indexOf(i) + x));
        }
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