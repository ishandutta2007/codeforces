import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.BitSet;
import java.io.BufferedReader;
import java.util.Comparator;
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
        GAutocompletion solver = new GAutocompletion();
        solver.solve(1, in, out);
        out.close();
    }

    static class GAutocompletion {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            GAutocompletion.N[] input = new GAutocompletion.N[n];
            for (int i = 1; i <= n; i++) {
                input[i - 1] = new GAutocompletion.N(i, in.nextInt(), in.next().charAt(0) - 'a');
            }
            Arrays.sort(input, Comparator.comparingInt(i -> i.alpha));
            n++; // because there's a special root node
            IntStack[] adj = new IntStack[n];
            for (int i = 0; i < adj.length; i++) {
                adj[i] = new IntStack();
            }
            int[] parent = new int[n];
            parent[0] = -1;
            for (GAutocompletion.N p : input) {
                adj[p.parent].push(p.index);
                parent[p.index] = p.parent;
            }

            int k = in.nextInt();
            int[] specialArray = in.readIntArray(k);
            BitSet special = new BitSet();
            for (int i : specialArray) {
                special.set(i);
            }

            int[] answer = new int[n];
            Arrays.fill(answer, Integer.MAX_VALUE);
            answer[0] = 0;
            int specialIndex = 0;

            IntStack curStack = new IntStack();
            IntStack savingsStack = new IntStack();
            curStack.push(0);
            savingsStack.push(0);
            while (!curStack.isEmpty()) {
                int cur = curStack.pop();
                int savings = savingsStack.pop();

                if (special.get(cur)) {
                    specialIndex++;
                }

                if (special.get(cur))
                    answer[cur] = savings + specialIndex;
                if (parent[cur] != -1)
                    answer[cur] = Math.min(answer[cur], answer[parent[cur]] + 1);

                int newSavings = Math.min(savings, answer[cur] + (special.get(cur) ? 1 : 0) - specialIndex);
                for (int i = adj[cur].size() - 1; i >= 0; i--) {
                    int child = adj[cur].array[i];
                    curStack.push(child);
                    savingsStack.push(newSavings);
                }
            }

            for (int i : specialArray) {
                out.print(answer[i] + " ");
            }
            out.println();
        }

        private static class N {
            final int index;
            final int parent;
            final int alpha;

            private N(int index, int parent, int alpha) {
                this.index = index;
                this.parent = parent;
                this.alpha = alpha;
            }

        }

    }

    static class IntStack {
        public int[] array;
        int size = 0;

        public IntStack() {
            this(8);
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

        public int size() {
            return size;
        }

        private static int[] resize(int[] array) {
            int[] newArray = new int[array.length << 1];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        public String toString() {
            int[] trimmed = new int[size];
            System.arraycopy(array, 0, trimmed, 0, size);
            return Arrays.toString(trimmed);
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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