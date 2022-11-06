import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

import static java.lang.Math.*;
import static java.util.Collections.*;
import static java.util.Arrays.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    boolean ok(String s) {
        if (s.isEmpty()) {
            return false;
        }
        if ("0".equals(s)) {
            return true;
        }
        if (s.charAt(0) == '0') {
            return false;
        }
        for (char i : s.toCharArray()) {
            if (!Character.isDigit(i)) {
                return false;
            }
        }
        return true;
    }

    void solve() throws IOException {
        String s = next() + ",3##";
        String[] a = s.split("[,;]");
        List<String> ans = new ArrayList<>();
        List<String> bans = new ArrayList<>();
        for (String i : a) {
            if ("3##".equals(i)) {
                continue;
            }
            if (ok(i)) {
                ans.add(i);
            } else {
                bans.add(i);
            }
        }
        String a1 = ans.stream().collect(Collectors.joining(","));
        String a2 = bans.stream().collect(Collectors.joining(","));
        if (ans.isEmpty()) {
            a1 = "-";
        } else {
            a1 = "\"" + a1 + "\"";
        }
        if (bans.isEmpty()) {
            a2 = "-";
        } else {
            a2 = "\"" + a2 + "\"";
        }
        println(a1);
        println(a2);

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

    class Pair<A extends Comparable<A>, B extends Comparable<B>> implements Comparable<Pair<A, B>> {
        A first;
        B second;

        public Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair<A, B> o) {
            int cmpFirst = first.compareTo(o.first);
            return cmpFirst != 0 ? cmpFirst : second.compareTo(o.second);
        }
    }
}