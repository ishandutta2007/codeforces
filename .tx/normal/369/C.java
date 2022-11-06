import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO in;
    PrintWriter out;

    class Edge {
        int to;
        boolean bad, exist;

        Edge(int to, boolean bad) {
            this.to = to;
            this.bad = bad;
            exist = true;
        }
    }

    List<Edge>[] gr;

    boolean dfs(int v, int p) {
        boolean need = false;
        for (Edge i : gr[v]) {
            if (i.to == p) continue;
            if (!dfs(i.to, v) && !i.bad) {
                i.exist = false;
            } else {
                need = true;
            }
        }
        return need;
    }

    List<Integer> ans = new ArrayList<>();
    void dfs1(int v, int p) {
        boolean chExist = false;
        for (Edge i : gr[v]) {
            if (i.to != p && i.exist) {
                chExist = true;
                dfs1(i.to, v);
            }
        }
        if (!chExist && v != 0) {
            ans.add(v + 1);
        }
    }

    // File names!!!

    void solve() throws IOException {
        int n = in.nextInt();
        gr = new List[n];
        for (int i = 0; i < n; i++) {
            gr[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int f = in.nextInt() - 1;
            int t = in.nextInt() - 1;
            boolean bad = in.nextInt() == 2;
            gr[f].add(new Edge(t, bad));
            gr[t].add(new Edge(f, bad));
        }
        dfs(0, -1);
        dfs1(0, -1);
        out.println(ans.size());
        for (int i : ans) {
            out.print(i + " ");
        }

    }

    void run() {
        try {
            in = new FastIO();
            solve();
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    public static void main(String[] args) {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignore) {
        }
        new Main().run();
    }

    class FastIO {
        private BufferedReader in;

        private StringTokenizer stok;

        FastIO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }

        FastIO(String s) throws FileNotFoundException {
            if ("".equals(s)) {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            } else {
                in = new BufferedReader(new FileReader(s + ".in"));
                out = new PrintWriter(s + ".out");
            }
        }

        void close() throws IOException {
            in.close();
            out.close();
        }

        String next() {
            while (stok == null || !stok.hasMoreTokens()) {
                try {
                    stok = new StringTokenizer(in.readLine());
                } catch (Exception e) {
                    return null;
                }
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
    }
}