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
import java.util.Queue;
import java.util.ArrayDeque;
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
        BNumbersOnTree solver = new BNumbersOnTree();
        solver.solve(1, in, out);
        out.close();
    }

    static class BNumbersOnTree {
        List<Integer>[] child;
        int[] parent;
        int[] score;
        int[] answer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            child = new List[n];
            for (int i = 0; i < n; i++) {
                child[i] = new ArrayList<>();
            }
            parent = new int[n];
            score = new int[n];
            int root = -1;
            for (int i = 0; i < n; i++) {
                int p = in.nextInt() - 1;
                score[i] = in.nextInt();
                parent[i] = p;
                if (p != -1)
                    child[p].add(i);
                else
                    root = i;
            }

            answer = new int[n];

            List<Integer> res = solve(root);

            if (res == null) {
                out.println("NO");
                return;
            }

            out.println("YES");
            out.println(Util.join(answer));
        }

        private List<Integer> solve(int root) {
            List<List<Integer>> subtrees = new ArrayList<>();
            int assign = 0;
            Queue<Integer> thresholds = new ArrayDeque<>();
            int sc = score[root];
            int count = 0;
            for (int c : child[root]) {
                List<Integer> indices = solve(c);
                if (indices == null)
                    return null;
                subtrees.add(indices);

                List<Integer> values = new ArrayList<>();
                int max = 0;
                for (int i : indices) {
                    answer[i] += count;
                    values.add(answer[i]);
                    max = Math.max(max, answer[i]);
                }
                count = max;
                Collections.sort(values);
                int lastUnchanged = -1;
                for (int i = 0; i < Math.min(values.size(), sc); i++) {
                    lastUnchanged = values.get(i);
                }
                sc -= Math.min(values.size(), sc);
                thresholds.add(lastUnchanged);
                assign = Math.max(assign, lastUnchanged);
            }
            if (sc > 0)
                return null;

            List<Integer> result = new ArrayList<>();
            for (List<Integer> indices : subtrees) {
                result.addAll(indices);
                int lastUnchanged = thresholds.remove();
                int diff = assign - lastUnchanged;

                for (int i : indices) {
                    if (answer[i] > lastUnchanged) {
                        answer[i] += 1 + diff;
                    }
                }
            }
            answer[root] = assign + 1;
            result.add(root);

            return result;
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

    }
}