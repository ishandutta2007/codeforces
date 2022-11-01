import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
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
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int m = in.nextInt();
            int k = in.nextInt();

            int[] freq = new int[k];
            for (int i = 0; i < k; ++i) {
                freq[i] = in.nextInt();
            }
            boolean[] canBeFirst = new boolean[k];

            int[] dishes = new int[m - 1];
            int[] changes = new int[m - 1];
            int[] last = new int[k];
            Arrays.fill(last, -1);
            for (int i = 0; i < m - 1; ++i) {
                dishes[i] = in.nextInt() - 1;
                changes[i] = in.nextInt();
                if (dishes[i] != -1) {
                    last[dishes[i]] = i;
                }
            }

            int spare = 0;
            int minTake = -1;
            for (int i = 0; i < m - 1; ++i) {
                int dish = dishes[i];
                int took = changes[i];
                if (took == 1 && minTake == -1) {
                    for (int j = 0; j < k; ++j) {
                        if (spare >= freq[j] && last[j] < i) {
                            canBeFirst[j] = true;
                            if (minTake == -1 || minTake > freq[j]) {
                                minTake = freq[j];
                            }
                        }
                    }
                }
                if (dish != -1) {
                    freq[dish]--;
                } else {
                    spare++;
                }
            }
            if (minTake != -1) {
                spare -= minTake;
            }
            StringBuilder res = new StringBuilder();
            for (int i = 0; i < k; ++i) {
                if (freq[i] - spare > 0 && !canBeFirst[i]) {
                    res.append('N');
                } else {
                    res.append('Y');
                }
            }
            out.println(res);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}