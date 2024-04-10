import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author 6aren
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        int MOD = 998244353;
        int n;
        ArrayList<Integer>[] tree;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            tree = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) {
                tree[i] = new ArrayList<Integer>();
            }
            for (int i = 1; i < n; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                tree[u].add(v);
                tree[v].add(u);
            }
            out.println(((long) n * dfs(1, 0)) % MOD);
        }

        private int dfs(int u, int v) {
            int cnt = 0;
            long res = 1;
            for (int i = 0; i < tree[u].size(); i++) {
                int t = tree[u].get(i);
                if (t == v) {
                    continue;
                }
                cnt++;
                res = (res * cnt) % MOD;
                res = (res * dfs(t, u)) % MOD;
            }
            if (u != 1) {
                res = (res * (cnt + 1)) % MOD;
            }
            return (int) res;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}