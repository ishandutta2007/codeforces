import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.Comparator;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        private List<Integer> ans;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String S = in.next();
            int N = S.length();

            int[] next = new int[N], length = new int[N];
            char[] end = new char[N];

            Comparator<Integer> cmp = (a, b) -> length[b] == length[a] ? b - a : length[b] - length[a];
            TreeSet<Integer> ls = new TreeSet<>(cmp), rs = new TreeSet<>(cmp);
            for (int i = N - 1; i >= 0; --i) {
                if (S.charAt(i) == 'L') {
                    if (rs.isEmpty()) {
                        end[i] = 'L';
                        next[i] = -1;
                        length[i] = 1;
                    } else {
                        next[i] = rs.pollFirst();
                        end[i] = end[next[i]];
                        length[i] = length[next[i]] + 1;
                    }
                    ls.add(i);
                } else {
                    if (ls.isEmpty()) {
                        end[i] = 'R';
                        next[i] = -1;
                        length[i] = 1;
                    } else {
                        next[i] = ls.pollFirst();
                        end[i] = end[next[i]];
                        length[i] = length[next[i]] + 1;
                    }
                    rs.add(i);
                }
            }

            List<Integer> ll = new ArrayList<>(), rr = new ArrayList<>();
            List<Integer> lr = new ArrayList<>(), rl = new ArrayList<>();

            for (int p : ls) (end[p] == 'L' ? ll : lr).add(p);
            for (int p : rs) (end[p] == 'R' ? rr : rl).add(p);

            out.println(ll.size() + rr.size() + lr.size() + rl.size() - 1);

            ans = new ArrayList<>();
            if (ll.isEmpty() && rr.isEmpty()) {
                if (!lr.isEmpty() && !rl.isEmpty()) throw new RuntimeException();
                for (int p : lr) addToAnswer(p, next);
                for (int p : rl) addToAnswer(p, next);
            } else {
                if (ll.size() > rr.size()) buildSolution(lr, rl, ll, rr, next);
                else buildSolution(rl, lr, rr, ll, next);
            }

            for (int p : ans) out.print(p + " ");
            out.println();
        }

        private void buildSolution(List<Integer> lr, List<Integer> rl, List<Integer> ll, List<Integer> rr,
                                   int[] next) {
            for (int p : lr) addToAnswer(p, next);
            addToAnswer(ll.remove(ll.size() - 1), next);
            for (int p : rl) addToAnswer(p, next);

            while (true) {
                if (rr.isEmpty()) break;
                addToAnswer(rr.remove(rr.size() - 1), next);
                if (ll.isEmpty()) break;
                addToAnswer(ll.remove(ll.size() - 1), next);
            }
        }

        private void addToAnswer(int pos, int[] next) {
            while (pos != -1) {
                ans.add(pos + 1);
                pos = next[pos];
            }
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