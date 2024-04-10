import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.NavigableSet;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        F1ChessStrikesBackEasyVersion solver = new F1ChessStrikesBackEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class F1ChessStrikesBackEasyVersion {
        private static final String NO = "NO";
        private static final String YES = "YES";
        int n;
        int m;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt() * 2;
            m = in.nextInt() * 2;
            int queries = in.nextInt();
            Pii[] q = new Pii[queries];
            Pii[] qInverse = new Pii[queries];
            for (int i = 0; i < queries; i++) {
                q[i] = Pii.of(in.nextInt() - 1, in.nextInt() - 1);
                qInverse[i] = Pii.of(n - 1 - q[i].first, m - 1 - q[i].second);
            }

            TreeSet<Pii>[] set = new TreeSet[2];
            for (int i = 0; i < 2; i++) {
                set[i] = new TreeSet<>(Comparator.comparingInt(p -> p.first));
                set[i].add(Pii.of(Integer.MAX_VALUE, -1));
                set[i].add(Pii.of(-1, Integer.MAX_VALUE));
            }

            boolean valid = true;
            for (int i = 0; i < queries; i++) {
                Pii a = q[i], t = qInverse[i];
                TreeSet<Pii> add = set[0], test = set[1];
                if (!forward(a)) {
                    a = qInverse[i];
                    t = q[i];
                    add = set[1];
                    test = set[0];
                }

                if (test.floor(t).second < t.second)
                    valid = false;

                Iterator<Pii> it = add.tailSet(a, true).iterator();
                while ((it.next()).second > a.second)
                    it.remove();
                if (add.floor(a).second > a.second)
                    add.add(a);

                out.println(valid ? YES : NO);
            }
        }

        private static boolean forward(Pii a) {
            return a.first % 2 == 0;
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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

    static class Pii implements Comparable<Pii> {
        public final int first;
        public final int second;

        public Pii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public static Pii of(int first, int second) {
            return new Pii(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pii pair = (Pii) o;
            return first == pair.first && second == pair.second;
        }

        public int hashCode() {
            return Arrays.hashCode(new int[]{first, second});
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

        public int compareTo(Pii o) {
            if (first != o.first)
                return Integer.compare(first, o.first);
            return Integer.compare(second, o.second);
        }

    }
}