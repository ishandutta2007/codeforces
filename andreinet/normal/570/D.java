import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        List<Integer>[] levelNodes;
        int eulerPos;
        int[] firstSon;
        int[] nextSon;
        int[] firstQuery;
        int[] nextQuery;
        int[] first;
        int[] last;
        String values;
        int[] aib;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt(), M = in.nextInt();
            firstSon = new int[N];
            nextSon = new int[N];
            Arrays.fill(firstSon, -1);

            for (int i = 1; i < N; ++i) {
                int x = in.nextInt() - 1;
                nextSon[i] = firstSon[x];
                firstSon[x] = i;
            }

            values = in.next();
            levelNodes = new List[N];
            for (int i = 0; i < N; ++i)
                levelNodes[i] = new ArrayList<>();
            first = new int[N];
            last = new int[N];
            eulerPos = 0;

            dfs(0, 0);

            firstQuery = new int[N];
            nextQuery = new int[M];
            Arrays.fill(firstQuery, -1);

            int[] vq = new int[M];
            for (int i = 0; i < M; ++i) {
                int v = in.nextInt() - 1, h = in.nextInt() - 1;
                nextQuery[i] = firstQuery[h];
                firstQuery[h] = i;

                vq[i] = v;
            }

            boolean[] ans = new boolean[M];

            aib = new int[N + 1];
            for (int i = 0; i < N; ++i) {
                for (int p : levelNodes[i])
                    update(first[p], values.charAt(p) - 'a');
                for (int pos = firstQuery[i]; pos != -1; pos = nextQuery[pos])
                    ans[pos] = query(first[vq[pos]], last[vq[pos]]);
                for (int p : levelNodes[i])
                    update(first[p], values.charAt(p) - 'a');
            }

            for (boolean p : ans)
                out.println(p ? "Yes" : "No");
        }

        private void update(int pos, int where) {
            for (; pos < aib.length; pos += pos & -pos)
                aib[pos] ^= (1 << where);
        }

        private int query(int pos) {
            int ret = 0;
            for (; pos > 0; pos -= pos & -pos)
                ret ^= aib[pos];
            return ret;
        }

        private boolean query(int left, int right) {
            return good(query(right) ^ query(left - 1));
        }

        private void dfs(int node, int level) {
            levelNodes[level].add(node);
            first[node] = ++eulerPos;
            for (int p = firstSon[node]; p != -1; p = nextSon[p])
                dfs(p, level + 1);
            last[node] = eulerPos;
        }

        private boolean good(int x) {
            return x == 0 || (x & (x - 1)) == 0;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}