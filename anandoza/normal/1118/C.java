import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CPalindromicMatrix solver = new CPalindromicMatrix();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPalindromicMatrix {
        private static final int MAX = 1000 + 5;
        private static final int ONE = 1;
        private static final int TWO = 2;
        private static final int FOUR = 4;
        private static final int M = 5;
        private static final int[] SIZES = {4, 2, 1};
        private static final String YES = "YES";
        private static final String NO = "NO";
        int n;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();

            int[] spotCount = new int[M];
            spotCount[ONE] = n % 2;
            spotCount[TWO] = (n % 2) * (n * 2 - 1);
            spotCount[FOUR] = n * n - spotCount[ONE] - spotCount[TWO];

            int[] count = new int[MAX];
            for (int i = 0; i < n * n; i++) {
                count[in.nextInt()]++;
            }

            Queue<Integer>[] numbers = new Queue[]{null,
                                                   new ArrayDeque<>(),
                                                   new ArrayDeque<>(),
                                                   null,
                                                   new ArrayDeque<>()};
            for (int i = 0; i < MAX; i++) {
                for (int s : SIZES) {
                    while (count[i] >= s) {
                        numbers[s].add(i);
                        count[i] -= s;
                    }
                }
            }

            Queue<Set<Pii>>[] spots = new Queue[]{null,
                                                  new ArrayDeque<>(),
                                                  new ArrayDeque<>(),
                                                  null,
                                                  new ArrayDeque<>()};

            boolean[][] visited = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (visited[i][j])
                        continue;

                    Set<Pii> s = flips(i, j);
                    spots[s.size()].add(s);
                    for (Pii p : s) {
                        visited[p.first][p.second] = true;
                    }
                }
            }

            int[][] answer = new int[n][n];
            for (int size : SIZES) {
                while (!spots[size].isEmpty()) {
                    if (numbers[size].isEmpty()) {
                        out.println(NO);
                        return;
                    }
                    Set<Pii> s = spots[size].poll();
                    int num = numbers[size].poll();
                    for (Pii p : s) {
                        answer[p.first][p.second] = num;
                    }
                }

                while (!numbers[size].isEmpty()) {
                    int num = numbers[size].poll();
                    numbers[size / 2].add(num);
                    numbers[size / 2].add(num);
                }
            }

            out.println(YES);
            for (int[] row : answer) {
                out.println(Util.join(row));
            }
        }

        private Set<Pii> flips(int i, int j) {
            HashSet<Pii> s = new HashSet<>();
            for (int x : new int[]{i, n - 1 - i}) {
                for (int y : new int[]{j, n - 1 - j}) {
                    s.add(Pii.of(x, y));
                }
            }
            return s;
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

    static class Util {
        public static String join(int... i) {
            StringBuilder sb = new StringBuilder();
            for (int o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

        private Util() {
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