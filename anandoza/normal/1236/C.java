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
        CLabs solver = new CLabs();
        solver.solve(1, in, out);
        out.close();
    }

    static class CLabs {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            List<Integer>[] answer = new List[n];
            for (int i = 0; i < n; i++) {
                answer[i] = new ArrayList<>();
            }

            int cur = 0, dir = 1;
            for (int i = 1; i <= n * n; i++) {
                answer[cur].add(i);
                if (cur == n - 1 && dir == 1) {
                    dir *= -1;
                } else if (cur == 0 && dir == -1) {
                    dir *= -1;
                } else {
                    cur += dir;
                }
            }

            for (int i = 0; i < n; i++) {
                out.println(Util.join(answer[i]));
            }

//        int check = Integer.MAX_VALUE;
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                if (i == j)
//                    continue;
//
//                int count = 0;
//                for (int x : answer[i]) {
//                    for (int y : answer[j]) {
//                        if (x < y)
//                            count++;
//                    }
//                }
//                check = Math.min(count, check);
//            }
//        }
//
//        System.out.println(check + " " + (n * n / 2));
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