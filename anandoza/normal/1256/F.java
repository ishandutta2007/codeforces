import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.HashMap;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.BitSet;
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
        FEqualizingTwoStrings solver = new FEqualizingTwoStrings();
        solver.solve(1, in, out);
        out.close();
    }

    static class FEqualizingTwoStrings {
        static final String NO = "NO";
        static final String YES = "YES";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] s = new int[26];
            char[] first = in.next().toCharArray();
            for (char c : first) {
                s[c - 'a']++;
            }
            int[] t = new int[26];
            char[] second = in.next().toCharArray();
            for (char c : second) {
                t[c - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                if (s[i] != t[i]) {
                    out.println(NO);
                    return;
                }
            }

            for (int i = 0; i < 26; i++) {
                if (s[i] > 1) {
                    out.println(YES);
                    return;
                }
            }

            if (Permutations.isOdd(Permutations.getPermutation(first, second))) {
                out.println(NO);
                return;
            }
            out.println(YES);
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

    static class Permutations {
        public static int[] getPermutation(char[] before, char[] after) {
            Util.ASSERT(before.length == after.length);

            HashMap<Character, Integer> afterIndex = new HashMap<>();
            int n = after.length;
            for (int i = 0; i < n; i++) {
                afterIndex.put(after[i], i);
            }

            int[] permutation = new int[n];
            for (int i = 0; i < n; i++) {
                permutation[i] = afterIndex.remove(before[i]);
            }

            return permutation;
        }

        public static boolean isOdd(int[] permutation) {
            return isOdd(findCycles(permutation));
        }

        public static boolean isOdd(List<List<Integer>> cycles) {
            boolean parity = false;
            for (List<Integer> c : cycles) {
                parity ^= (c.size() % 2 == 0);
            }
            return parity;
        }

        public static List<List<Integer>> findCycles(int[] permutation) {
            List<List<Integer>> cycles = new ArrayList<>();
            int n = permutation.length;
            BitSet visited = new BitSet(n);

            for (int i = 0; i < n; i++) {
                if (visited.get(i))
                    continue;

                List<Integer> c = new ArrayList<>();
                for (int j = i; c.isEmpty() || j != i; j = permutation[j]) {
                    c.add(j);
                    visited.set(j);
                }

                if (c.size() > 1) {
                    cycles.add(c);
                }
            }

            return cycles;
        }

    }

    static class Util {
        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

    }
}