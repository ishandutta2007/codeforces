import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.BitSet;
import java.util.Queue;
import java.io.BufferedReader;
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
        CFriendsAndGifts solver = new CFriendsAndGifts();
        solver.solve(1, in, out);
        out.close();
    }

    static class CFriendsAndGifts {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] f = in.readIntArray(n);
            for (int i = 0; i < n; i++)
                f[i]--;

            BitSet alreadyGave = new BitSet();
            BitSet alreadyReceived = new BitSet();
            for (int i = 0; i < n; i++) {
                if (f[i] < 0)
                    continue;
                alreadyGave.set(i);
                alreadyReceived.set(f[i]);
            }

            Queue<Integer> needToGive = new ArrayDeque<>();
            Queue<Integer> needToReceive = new ArrayDeque<>();
            Queue<Integer> both = new ArrayDeque<>();

            for (int i = 0; i < n; i++) {
                if (!alreadyGave.get(i) && !alreadyReceived.get(i))
                    both.add(i);
                if (alreadyGave.get(i) && !alreadyReceived.get(i))
                    needToReceive.add(i);
                if (!alreadyGave.get(i) && alreadyReceived.get(i))
                    needToGive.add(i);
            }

            Queue<Integer> give = new ArrayDeque<>();
            Queue<Integer> receive = new ArrayDeque<>();
            while (!both.isEmpty()) {
                int i = both.poll();
                give.add(i);
                receive.add(i);
            }
            while (!needToGive.isEmpty()) {
                give.add(needToGive.poll());
                receive.add(needToReceive.poll());
            }

            if (!receive.isEmpty())
                receive.add(receive.poll());

            while (!give.isEmpty()) {
                f[give.poll()] = receive.poll();
            }

            for (int i = 0; i < n; i++)
                f[i]++;

            out.println(Util.join(f));
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}