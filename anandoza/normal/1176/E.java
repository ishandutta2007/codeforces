import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
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
        ECoverIt solver = new ECoverIt();
        solver.solve(1, in, out);
        out.close();
    }

    static class ECoverIt {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        public void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            List<Integer>[] adj = new List[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }

            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;

                adj[a].add(b);
                adj[b].add(a);
            }

            int[] distance = new int[n];
            Arrays.fill(distance, -1);
            distance[0] = 0;
            Queue<Integer> q = new ArrayDeque<>();
            q.add(0);
            while (!q.isEmpty()) {
                int cur = q.poll();
                for (int next : adj[cur]) {
                    if (distance[next] == -1) {
                        distance[next] = distance[cur] + 1;
                        q.add(next);
                    }
                }
            }

            List<Integer> odd = new ArrayList<>();
            List<Integer> even = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int d = distance[i];
                if (d % 2 == 0) even.add(i);
                else odd.add(i);
            }

            List<Integer> answer = even;
            if (odd.size() < even.size()) answer = odd;

            out.println(answer.size());
            StringBuilder sb = new StringBuilder();
            for (int x : answer) {
                sb.append((x + 1) + " ");
            }
            sb.deleteCharAt(sb.length() - 1);
            out.println(sb);
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