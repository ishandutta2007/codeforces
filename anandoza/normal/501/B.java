import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        BMishaAndChangingHandles solver = new BMishaAndChangingHandles();
        solver.solve(1, in, out);
        out.close();
    }

    static class BMishaAndChangingHandles {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            HashMap<String, String> map = new HashMap<>();
            for (int i = 0; i < q; i++) {
                String a = in.next(), b = in.next();
                map.put(b, map.getOrDefault(a, a));
                map.remove(a);
            }

            out.println(map.size());
            for (Map.Entry<String, String> e : map.entrySet()) {
                out.println(e.getValue() + " " + e.getKey());
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