import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
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
        E2StringColoringHardVersion solver = new E2StringColoringHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class E2StringColoringHardVersion {
        public static final int L = 26;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] sInput = in.next().toCharArray();
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = sInput[i] - 'a';
            }

            Queue<List<Integer>>[] queues = new Queue[L];
            for (int i = 0; i < L; i++) {
                queues[i] = new ArrayDeque<>();
            }

            for (int i = 0; i < n; i++) {
                int v = s[i];
                for (int j = v; j >= -1; j--) {
                    if (j == -1) {
                        queues[v].add(new ArrayList<>());
                        queues[v].peek().add(i);
                        break;
                    }
                    if (!queues[j].isEmpty()) {
                        List<Integer> l = queues[j].poll();
                        l.add(i);
                        queues[v].add(l);
                        break;
                    }
                }
            }

            int color = 0;
            int[] answer = new int[n];
            for (Queue<List<Integer>> q : queues) {
                for (List<Integer> l : q) {
                    for (int i : l) {
                        answer[i] = color + 1;
                    }
                    color++;
                }
            }

            out.println(color);
            out.println(Util.join(answer));
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
}