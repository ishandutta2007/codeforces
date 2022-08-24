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

    private void solve() throws IOException {
        Set <Integer> s = new HashSet<>();
        int n = nextInt();
        int p = nextInt();
        for (int i = 0; i < p; i++) {
            s.add(nextInt());
        }
        int q = nextInt();
        for (int i = 0; i < q; i++) {
            s.add(nextInt());
        }
        if (s.size() == n) {
            out.println("I become the guy.");
        }
        else {
            out.println("Oh, my keyboard!");
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