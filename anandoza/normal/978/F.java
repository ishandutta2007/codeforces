import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.*;
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
        Soln solver = new Soln();
        solver.solve(1, in, out);
        out.close();
    }

    static class Soln {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = 1; //in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
        	int n = in.nextInt();
        	int m = in.nextInt();
        	int[] r = in.readIntArray(n);
        	Pair<Integer, Integer>[] p = new Pair[n];
        	for (int i=0;i<n;i++) {
        		p[i] = Pair.of(i, r[i]);
        	}
        	Arrays.sort(p, Comparator.comparingInt(x -> x.second));
        	int[] score = new int[n];
        	for (int i=0, j =0;i<n;i=j) {
        		while (j < n && p[j].second.equals(p[i].second)) j++;
        		
        		for (int k = i; k < j; k++) {
        			score[p[k].first] = i;
        		}
        	}
        	
        	Pair<Integer, Integer>[] q = new Pair[m];
        	for (int i=0;i<m;i++) {
        		int a = in.nextInt() - 1, b = in.nextInt() - 1;
        		if (r[a] < r[b]) score[b]--;
        		if (r[b] < r[a]) score[a]--;
        	}
        	
        	for (int x : score) out.print(x + " ");
        	out.println();
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }
        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        public static <F, S> Pair<F, S> of(F first, S second) {
            return new Pair<>(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        public int hashCode() {
            return Objects.hash(first, second);
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

    }
}