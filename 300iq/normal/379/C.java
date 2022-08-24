import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Main {

    PrintWriter out;
    BufferedReader b;
    StringTokenizer s;

    String next() throws IOException {
        while (s == null || !s.hasMoreTokens()) {
            String k = b.readLine();
            if (k == null) {
                return null;
            }
            s = new StringTokenizer(k);
        }
        return s.nextToken();
    }

    char nextChar() throws IOException {
        return (char) (b.read());
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }
    class Present implements Comparable <Present> {
        int need, id;
        public Present(int n, int i) {
            this.need = n;
            this.id = i;
        }
        @Override
        public int compareTo(Present present) {
            return Integer.compare(this.need, present.need);
        }
    }
    private void solve() throws IOException {
        int n = nextInt();
        int b[] = new int[n];
        ArrayList <Present> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new Present(nextInt(), i));
        }
        Collections.sort(a);
        int mini = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if (a.get(i).need > mini) {
                mini = a.get(i).need + 1;
            }
            else if (a.get(i).need <= mini) {
                a.get(i).need = mini;
                mini++;
            }
        }
        for (int i = 0; i < n; i++) {
            b[a.get(i).id] = a.get(i).need;
        }
        for (int i = 0; i < n; i++) {
            out.print(b[i] + " ");
        }
    }

    private void run() throws IOException {
        out = new PrintWriter(System.out);
        b = new BufferedReader(new InputStreamReader(System.in));
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}