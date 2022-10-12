import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.HashMap;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.ArrayDeque;
import java.util.Collections;
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
        DCalendar solver = new DCalendar();
        solver.solve(1, in, out);
        out.close();
    }

    static class DCalendar {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String[] s = new String[n];
            for (int i = 0; i < n; i++) {
                s[i] = in.next();
            }
            char sep = in.next().charAt(0);
            int len = 0;
            for (int i = 0; i < n; i++) {
                len += s[i].length();
            }
            len += n / 2;
            len /= (n / 2);

            if (sep < 'x') {
                Arrays.sort(s);
            } else {
                Arrays.sort(s, (a, b) -> {
                    String x = a.substring(0, Math.min(a.length(), b.length()));
                    String y = b.substring(0, Math.min(a.length(), b.length()));
                    int c = x.compareTo(y);
                    if (c != 0)
                        return c;
                    return Integer.compare(b.length(), a.length());
                });
            }
            Queue<String>[] buckets = new Queue[11];
            for (int i = 0; i < 11; i++) {
                buckets[i] = new ArrayDeque<>();
            }
            for (int i = 0; i < n; i++) {
                buckets[s[i].length()].add(s[i]);
            }
            Counter<String> avail = new Counter<>(s);

            List<String> ans = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (!avail.contains(s[i])) {
                    continue;
                }
                avail.decr(s[i]);
                int pair = len - 1 - s[i].length();
                String second = buckets[pair].poll();
                while (!avail.contains(second))
                    second = buckets[pair].poll();

                ans.add(s[i] + sep + second);

                avail.decr(second);
            }
            Collections.sort(ans);

            for (String x : ans)
                out.println(x);
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

    static class Counter<T> {
        public final HashMap<T, Integer> count = new HashMap<>();

        public Counter() {
        }

        public Counter(T[] elements) {
            for (T t : elements)
                incr(t);
        }

        public Counter(Iterable<T> elements) {
            for (T t : elements)
                incr(t);
        }

        public void incr(T key) {
            count.merge(key, 1, Integer::sum);
        }

        public void decr(T key) {
            count.compute(key, (k, v) -> v - 1 == 0 ? null : v - 1);
        }

        public boolean contains(T key) {
            return count.containsKey(key);
        }

    }
}