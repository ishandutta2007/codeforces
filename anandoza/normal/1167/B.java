import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
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
        BLostNumbers solver = new BLostNumbers();
        solver.solve(1, in, out);
        out.close();
    }

    static class BLostNumbers {
        static final int[] nums = {4, 8, 15, 16, 23, 42};
        static final int n = nums.length;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] input = new int[4];

            for (int i = 1; i <= 4; i++) {
                out.println(String.format("? %d %d", i, i + 1));
                out.flush();

                input[i - 1] = in.nextInt();
            }

            int[] answer = new int[n];
            for (int i = 0; i + 1 < 4; i++) {
                List<Integer> factors1 = factors(input[i]);
                List<Integer> factors2 = factors(input[i + 1]);

                for (int x : nums) {
                    if (factors1.contains(x) && factors2.contains(x)) {
                        answer[i + 1] = x;
                        break;
                    }
                }

                factors1.remove((Integer) answer[i + 1]);
                answer[i] = factors1.get(0);
                factors2.remove((Integer) answer[i + 1]);
                answer[i + 2] = factors2.get(0);
            }

            HashSet<Integer> set = new HashSet<>();
            for (int x : nums) {
                set.add(x);
            }
            for (int x : answer) {
                if (set.contains(x)) set.remove(x);
            }
            answer[5] = set.iterator().next();

            StringBuilder sb = new StringBuilder();
            sb.append("!");
            for (int x : answer) {
                sb.append(" " + x);
            }
            out.println(sb);
            out.flush();
        }

        public static List<Integer> factors(int x) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (nums[i] * nums[j] == x) {
                        ArrayList<Integer> list = new ArrayList<>();
                        list.add(nums[i]);
                        list.add(nums[j]);
                        return list;
                    }
                }
            }
            return new ArrayList<>();
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