import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
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
        DDirtyDeedsDoneDirtCheap solver = new DDirtyDeedsDoneDirtCheap();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDirtyDeedsDoneDirtCheap {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                b[i] = in.nextInt();
            }

            List<DDirtyDeedsDoneDirtCheap.DescendingPair> desc = new ArrayList<>();
            List<DDirtyDeedsDoneDirtCheap.AscendingPair> asc = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (a[i] > b[i]) {
                    desc.add(new DDirtyDeedsDoneDirtCheap.DescendingPair(a[i], b[i], i));
                } else if (a[i] < b[i]) {
                    asc.add(new DDirtyDeedsDoneDirtCheap.AscendingPair(a[i], b[i], i));
                }
            }

            List<Integer> answer = new ArrayList<>();

            if (desc.size() > asc.size()) {
                Collections.sort(desc, Comparator.comparingInt(p -> p.b));

                for (DDirtyDeedsDoneDirtCheap.DescendingPair p : desc) {
                    answer.add(p.i);
                }
            } else {
                Collections.sort(asc, Comparator.comparingInt(p -> -p.b));

                for (DDirtyDeedsDoneDirtCheap.AscendingPair p : asc) {
                    answer.add(p.i);
                }
            }

            out.println(answer.size());
            StringBuilder sb = new StringBuilder();
            for (int x : answer) {
                x++;
                sb.append(x + " ");
            }
            sb.deleteCharAt(sb.length() - 1);
            out.println(sb);
        }

        static class DescendingPair {
            final int a;
            final int b;
            final int i;

            DescendingPair(int a, int b, int i) {
                this.a = a;
                this.b = b;
                this.i = i;
            }

        }

        static class AscendingPair {
            final int a;
            final int b;
            final int i;

            AscendingPair(int a, int b, int i) {
                this.a = a;
                this.b = b;
                this.i = i;
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