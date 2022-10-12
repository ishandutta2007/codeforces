import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        BTokitsukazeAndMahjong solver = new BTokitsukazeAndMahjong();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTokitsukazeAndMahjong {
        static final int THREE = 3;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            List<String> tiles = new ArrayList<>();
            for (int i = 0; i < THREE; i++) {
                tiles.add(in.next());
            }

            int distinct = countDistinct(tiles);

            if (distinct == 1) {
                out.println(0);
                return;
            }

            if (distinct == 2) {
                out.println(1);
                return;
            }

            int answer = 3;
            for (char suit : "mps".toCharArray()) {
                List<Integer> suited = new ArrayList<>();
                for (String s : tiles) {
                    if (s.charAt(1) == suit) {
                        suited.add(s.charAt(0) - '0');
                    }
                }
                answer = Math.min(answer, 3 - have(suited));
            }
            out.println(answer);
        }

        private int have(List<Integer> suited) {
            int have = 0;
            for (int first : suited) {
                int cand = 1;
                if (suited.contains(first + 1)) {
                    cand++;
                }
                if (suited.contains(first + 2)) {
                    cand++;
                }
                have = Math.max(have, cand);
            }
            return have;
        }

        private int countDistinct(Iterable<String> tiles) {
            HashSet<String> set = new HashSet<>();
            for (String s : tiles)
                set.add(s);
            return set.size();
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

    }
}