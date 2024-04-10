import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
        EOpenStreetMap solver = new EOpenStreetMap();
        solver.solve(1, in, out);
        out.close();
    }

    static class EOpenStreetMap {
        IntMinQueue q;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            solveMinQueue(testNumber, in, out);
        }

        public void solveMinQueue(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int a = in.nextInt(), b = in.nextInt();

            long g0 = in.nextLong();
            long x = in.nextLong();
            long y = in.nextLong();
            long z = in.nextLong();

            q = new IntMinQueue(Math.max(a + 1, b + 1));

            int[] curRow = new int[m];
            int[][] rows = new int[n][];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    curRow[j] = (int) g0;
                    g0 = (g0 * x + y) % z;
                }
                rows[i] = minimaOfFixedRanges(curRow, b);
            }

            long answer = 0;
            int[] col = new int[n];
            for (int j = 0; j + b <= m; j++) {
                for (int i = 0; i < n; i++) {
                    col[i] = rows[i][j];
                }
                int[] res = minimaOfFixedRanges(col, a);

                for (int i = 0; i + a <= n; i++) {
                    answer += res[i];
                }
            }

            out.println(answer);
        }

        public int[] minimaOfFixedRanges(int[] x, int width) {
            int n = x.length;
            int[] answer = new int[n - (width - 1)];
            q.clear();
            for (int i = 0; i < n; i++) {
                q.push(x[i]);
                int start = i - (width - 1);
                if (start >= 0) {
                    answer[start] = q.getMin();
                    q.pop();
                }
            }
            return answer;
        }

    }

    static class IntStack {
        int[] array;
        int size = 0;

        public IntStack() {
            this(10);
        }

        public IntStack(int capacity) {
            array = new int[capacity];
        }

        public void push(int item) {
            if (size >= array.length)
                array = resize(array);
            array[size++] = item;
        }

        public int pop() {
            return array[--size];
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public int peek() {
            return array[size - 1];
        }

        public void clear() {
            size = 0;
        }

        private static int[] resize(int[] array) {
            int newSize = 1 + ((array.length * 16) / 10);
            int[] newPrimes = new int[newSize];
            System.arraycopy(array, 0, newPrimes, 0, array.length);
            return newPrimes;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }

    static class IntMinStack {
        IntStack items;
        IntStack mins;

        public IntMinStack() {
            items = new IntStack();
            mins = new IntStack();
        }

        public IntMinStack(int capacity) {
            items = new IntStack(capacity);
            mins = new IntStack(capacity);
        }

        public void push(int item) {
            int min;
            if (isEmpty()) {
                min = item;
            } else {
                min = Math.min(item, getMin());
            }
            items.push(item);
            mins.push(min);
        }

        public int pop() {
            mins.pop();
            return items.pop();
        }

        public boolean isEmpty() {
            return items.isEmpty();
        }

        public int getMin() {
            return mins.peek();
        }

        public void clear() {
            items.clear();
            mins.clear();
        }

    }

    static class IntMinQueue {
        private IntMinStack s1;
        private IntMinStack s2;

        public IntMinQueue() {
            s1 = new IntMinStack();
            s2 = new IntMinStack();
        }

        public IntMinQueue(int capacity) {
            s1 = new IntMinStack(capacity);
            s2 = new IntMinStack(capacity);
        }

        public void push(int item) {
            s1.push(item);
        }

        public int pop() {
            ensureItems();

            return s2.pop();
        }

        private void ensureItems() {
            if (s2.isEmpty()) {
                while (!s1.isEmpty()) {
                    s2.push(s1.pop());
                }
            }
        }

        public int getMin() {
            if (s1.isEmpty())
                return s2.getMin();
            if (s2.isEmpty())
                return s1.getMin();
            return Math.min(s1.getMin(), s2.getMin());
        }

        public void clear() {
            s1.clear();
            s2.clear();
        }

    }
}