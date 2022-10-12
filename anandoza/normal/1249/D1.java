import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Objects;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        D2TooManySegmentsHardVersion solver = new D2TooManySegmentsHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class D2TooManySegmentsHardVersion {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();

            int[][] segments = new int[n][2];
            for (int i = 0; i < n; i++) {
                segments[i][0] = in.nextInt();
                segments[i][1] = in.nextInt() + 1;
            }

            Pair<Integer, Integer>[] endpoints = new Pair[2 * n];
            for (int i = 0; i < n; i++) {
                endpoints[2 * i] = Pair.of(i, 0);
                endpoints[2 * i + 1] = Pair.of(i, 1);
            }

            Arrays.sort(endpoints, Comparator.comparingInt((Pair<Integer, Integer> p) -> segments[p.first][p.second]).thenComparingInt(p -> -p.second));

            List<Integer> answer = new ArrayList<>();
            PriorityQueue<Integer> heap = new PriorityQueue<>(Comparator.comparingInt((Integer i) -> segments[i][1]).reversed());
            HashSet<Integer> currentSegments = new HashSet<>();
            for (Pair<Integer, Integer> p : endpoints) {
                if (p.second.equals(0)) {
                    currentSegments.add(p.first);
                    heap.add(p.first);
                } else {
                    currentSegments.remove(p.first);
                }

                if (currentSegments.size() > k) {
                    int s;
                    while (!currentSegments.contains(s = heap.poll()))
                        ;
                    answer.add(s + 1);
                    currentSegments.remove(s);
                }
            }

            answer.sort(Comparator.naturalOrder());

            out.println(answer.size());
            out.println(Util.join(answer));
        }

    }

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        public static <F, S> Pair<F, S> of(F first, S second) {
            return new Pair<>(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        public int hashCode() {
            return Objects.hash(first, second);
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

    }

    static class Util {
        public static String join(Iterable i) {
            StringBuilder sb = new StringBuilder();
            for (Object o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
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