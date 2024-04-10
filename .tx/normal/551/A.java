import java.io.*;
import java.util.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    class Item {
        int x, y, ans;

        public Item(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        Item[] a = new Item[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Item(nextInt(), i);
        }
        Arrays.sort(a, (x, y) -> x.x == y.x ? x.y - y.y : y.x - x.x);
        a[0].ans = 1;
        for (int i = 1; i < n; i++) {
            if (a[i].x == a[i - 1].x) {
                a[i].ans = a[i - 1].ans;
            } else {
                a[i].ans = i + 1;
            }
        }
        Arrays.sort(a, (x, y) -> x.y - y.y);
        for (Item item : a) {
            print(item.ans);
            print(" ");
        }
    }

    public static void main(String[] args) throws IOException {
        try (Main main = new Main()) {
            main.solve();
        }
    }

    Main() throws IOException {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws IOException {
        super("".equals(s) ? "output.txt" : s + ".out");
        br = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
    }

    String next() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = br.readLine();
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
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    <T> List<T>[] createAdjacencyList(int verticesNumber) {
        List<T>[] res = new List[verticesNumber];
        for (int i = 0; i < verticesNumber; i++) {
            res[i] = new ArrayList<>();
        }
        return res;
    }
}