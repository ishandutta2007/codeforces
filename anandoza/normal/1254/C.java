import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        CPointOrdering solver = new CPointOrdering();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPointOrdering {
        InputReader in;
        PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;

            int n = in.nextInt();

            // let's partition into two halves
            List<Integer> first = new ArrayList<>();
            List<Integer> second = new ArrayList<>();
            for (int k = 2; k < n; k++) {
                int sign = getSign(0, 1, k);
                if (sign > 0) {
                    first.add(k);
                } else {
                    second.add(k);
                }
            }

            List<Integer> answer = new ArrayList<>();
//        System.err.println("FIRST: " + first);
//        System.err.println("SECOND: " + second);
//        System.err.println("FIRST: " + sort(first));
//        System.err.println("SECOND: " + sort(second));
            answer.add(0);
            answer.addAll(sort(first));
            answer.add(1);
            answer.addAll(sort(second));

            printAnswer(answer);
        }

        private void printAnswer(List<Integer> answer) {
            List<Integer> output = new ArrayList<>();
            output.add(0);
            for (int x : answer) {
                output.add(x + 1);
            }
            //System.out.println("PRINTING: " + output);
            out.println(Util.join(output));
            out.flush();
        }

        private List<Integer> sort(List<Integer> half) {
            if (half.isEmpty())
                return half;
            // Let's sort
            List<Pair<Integer, Long>> areas = new ArrayList<>();
            for (int k : half) {
                areas.add(Pair.of(k, getArea(0, 1, k)));
            }
            long maxArea = 0;
            int maxIndex = -1;
            for (int i = 0; i < areas.size(); i++) {
                if (areas.get(i).second > maxArea) {
                    maxIndex = areas.get(i).first;
                    maxArea = areas.get(i).second;
                }
            }
            // Now partition into two halves again
            List<Integer> first = new ArrayList<>();
            List<Integer> second = new ArrayList<>();
            for (int k : half) {
                if (k == maxIndex)
                    continue;
                int sign = getSign(0, maxIndex, k);
                if (sign > 0) {
                    first.add(k);
                } else {
                    second.add(k);
                }
            }

            HashMap<Integer, Long> area = new HashMap<>();
            for (Pair<Integer, Long> p : areas) {
                area.put(p.first, p.second);
            }

            first.sort(Comparator.comparingLong(i -> area.get(i)));
            second.sort(Comparator.comparingLong(i -> -area.get(i)));
            List<Integer> result = new ArrayList<>();
            result.addAll(first);
            result.add(maxIndex);
            result.addAll(second);
            return result;
        }

        private int getSign(int i, int j, int k) {
            out.println(Util.join(2, i + 1, j + 1, k + 1));
            out.flush();
            return -in.nextInt();
        }

        private long getArea(int i, int j, int k) {
            out.println(Util.join(1, i + 1, j + 1, k + 1));
            out.flush();
            return in.nextLong();
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

        public long nextLong() {
            return Long.parseLong(next());
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
}