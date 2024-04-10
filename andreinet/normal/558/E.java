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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        final int blockSize = 500;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt(), Q = in.nextInt();
            char[] A = in.next().toCharArray();

            int M = (N - 1) / blockSize + 1;
            TaskE.Stuff[] blocks = new TaskE.Stuff[M];
            for (int i = 0; i < M; ++i) {
                int begin = i * blockSize, end = (i + 1) * blockSize;
                blocks[i] = new TaskE.Stuff(i);
                for (int j = begin; j < N && j < end; ++j)
                    blocks[i].count[A[j] - 'a']++;
            }

            while (Q-- > 0) {
                int left = in.nextInt() - 1, right = in.nextInt() - 1;
                int type = in.nextInt();

                int leftBlock = left / blockSize, rightBlock = right / blockSize;
                if (leftBlock == rightBlock) {
                    blocks[leftBlock].putElements(A);
                    int[] count = new int[26];
                    for (int i = left; i <= right; ++i)
                        count[A[i] - 'a']++;

                    if (type == 1) {
                        int s = 0;
                        for (int k = 0; k < 26; ++k) {
                            int b = left + s, e = left + s + count[k];
                            for (int i = b; i < e; ++i)
                                A[i] = (char) (k + 'a');
                            s += count[k];
                        }
                    } else {
                        int s = 0;
                        for (int k = 25; k >= 0; --k) {
                            int b = left + s, e = left + s + count[k];
                            for (int i = b; i < e; ++i)
                                A[i] = (char) (k + 'a');
                            s += count[k];
                        }
                    }
                } else {
                    int[] count = new int[26];
                    blocks[leftBlock].putElements(A);
                    blocks[rightBlock].putElements(A);

                    for (int i = left; i < N && i / blockSize == leftBlock; ++i) {
                        count[A[i] - 'a']++;
                        blocks[leftBlock].count[A[i] - 'a']--;
                    }
                    for (int i = right; i >= 0 && i / blockSize == rightBlock; --i) {
                        count[A[i] - 'a']++;
                        blocks[rightBlock].count[A[i] - 'a']--;
                    }
                    for (int i = leftBlock + 1; i < rightBlock; ++i) {
                        for (int j = 0; j < 26; ++j)
                            count[j] += blocks[i].count[j];
                    }

                    if (type == 1) {
                        int pos = 0;
                        for (int i = left; i < N && i / blockSize == leftBlock; ++i) {
                            while (count[pos] == 0) pos++;
                            A[i] = (char) (pos + 'a');
                            blocks[leftBlock].count[pos]++;
                            count[pos]--;
                        }
                        for (int i = leftBlock + 1; i < rightBlock; ++i) {
                            int b = i * blockSize, e = Math.min(N, (i + 1) * blockSize);
                            int need = e - b;

                            blocks[i].clear();
                            while (need > 0) {
                                int x = Math.min(need, count[pos]);
                                blocks[i].count[pos] += x;
                                count[pos] -= x;
                                need -= x;

                                if (count[pos] == 0) pos++;
                            }
                            blocks[i].sorted = 1;
                        }
                        pos = 25;
                        for (int i = right; i >= 0 && i / blockSize == rightBlock; --i) {
                            while (count[pos] == 0) pos--;
                            A[i] = (char) (pos + 'a');
                            blocks[rightBlock].count[pos]++;
                            count[pos]--;
                        }
                    } else {
                        int pos = 25;
                        for (int i = left; i < N && i / blockSize == leftBlock; ++i) {
                            while (count[pos] == 0) pos--;
                            A[i] = (char) (pos + 'a');
                            blocks[leftBlock].count[pos]++;
                            count[pos]--;
                        }
                        for (int i = leftBlock + 1; i < rightBlock; ++i) {
                            int b = i * blockSize, e = Math.min(N, (i + 1) * blockSize);
                            int need = e - b;

                            blocks[i].clear();
                            while (need > 0) {
                                int x = Math.min(need, count[pos]);
                                blocks[i].count[pos] += x;
                                count[pos] -= x;
                                need -= x;

                                if (count[pos] == 0) pos--;
                            }
                            blocks[i].sorted = 2;
                        }
                        pos = 0;
                        for (int i = right; i >= 0 && i / blockSize == rightBlock; --i) {
                            while (count[pos] == 0) pos++;
                            A[i] = (char) (pos + 'a');
                            blocks[rightBlock].count[pos]++;
                            count[pos]--;
                        }
                    }
                }
            }

            for (int i = 0; i < M; ++i)
                blocks[i].putElements(A);

            out.println(new String(A));
        }

        private class Stuff {
            int[] count;
            int index;
            int sorted;

            Stuff(int index) {
                count = new int[26];
                this.index = index;
                sorted = 0;
            }

            void clear() {
                Arrays.fill(count, 0);
            }

            public void putElements(char[] A) {
                if (sorted == 0) return;
                int begin = index * blockSize, end = (index + 1) * blockSize;
                if (sorted == 1) {
                    int s = 0;
                    for (int k = 0; k < 26; ++k) {
                        int b = begin + s, e = begin + s + count[k];
                        for (int i = b; i < e; ++i)
                            A[i] = (char) (k + 'a');
                        s += count[k];
                    }
                } else {
                    int s = 0;
                    for (int k = 25; k >= 0; --k) {
                        int b = begin + s, e = begin + s + count[k];
                        for (int i = b; i < e; ++i)
                            A[i] = (char) (k + 'a');
                        s += count[k];
                    }
                }
                sorted = 0;
            }

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