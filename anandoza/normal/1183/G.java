import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.ArrayDeque;
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
        GCandyBoxHardVersion solver = new GCandyBoxHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class GCandyBoxHardVersion {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Integer[] typeCount = new Integer[n];
            Integer[] goodCount = new Integer[n];
            Arrays.fill(typeCount, 0);
            Arrays.fill(goodCount, 0);
            for (int i = 0; i < n; i++) {
                int type = in.nextInt() - 1;
                typeCount[type]++;
                boolean good = in.nextInt() == 1;
                if (good)
                    goodCount[type]++;
            }
            GCandyBoxHardVersion.Type[] types = new GCandyBoxHardVersion.Type[n];
            for (int i = 0; i < n; i++) {
                types[i] = new GCandyBoxHardVersion.Type(typeCount[i], goodCount[i]);
            }

            Arrays.sort(typeCount, Comparator.reverseOrder());

            ArrayDeque<Integer> typeCountsUsed = new ArrayDeque<>();

            long answer = 0;
            typeCountsUsed.add(typeCount[0]);
            answer += typeCount[0];
            for (int i = 1; i < n; i++) {
                if (typeCount[i] >= typeCount[i - 1]) {
                    typeCount[i] = typeCount[i - 1] - 1;
                }
                if (typeCount[i] < 0)
                    break;
                answer += typeCount[i];
                typeCountsUsed.add(typeCount[i]);
            }

            Arrays.sort(goodCount, Comparator.reverseOrder());

            Arrays.sort(types, Comparator.comparingInt(t -> -t.count));

            PriorityQueue<Integer> goodCountQ = new PriorityQueue<>(Comparator.reverseOrder());

            long good = 0;
            int index = 0;
            while (true) {
                Integer tc = typeCountsUsed.pollFirst();
                while (index < n && types[index].count >= tc) {
                    goodCountQ.add(types[index].goodCount);
                    index++;
                }

                good += Math.min(tc, goodCountQ.poll());

                if (typeCountsUsed.isEmpty())
                    break;
            }

            out.println(answer);
            out.println(good);
        }

        static final class Type implements Comparable<GCandyBoxHardVersion.Type> {
            final int count;
            final int goodCount;

            Type(int count, int goodCount) {
                this.count = count;
                this.goodCount = Math.max(0, goodCount);
            }

            public int compareTo(GCandyBoxHardVersion.Type o) {
                int ret = -Integer.compare(count, o.count);
                if (ret != 0)
                    return ret;
                ret = -Integer.compare(goodCount, o.goodCount);
                return ret;
            }

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