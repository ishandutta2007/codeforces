import java.io.*;
import java.util.*;

public class Main extends PrintWriter {
    BufferedReader br;

    void run() {
        int t = nextInt();
        for (int it = 0; it < t; it++) {
            int l = nextInt();
            int r = nextInt();
            if (2 * l <= r) {
                print(l);
                print(" ");
                println(2 * l);
            } else {
                println("-1 -1");
            }
        }
    }

    public Main() {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public static void main(String[] args) {
        try (Main main = new Main()) {
            main.run();
        }
    }

    StringTokenizer stok = null;

    String next() {
        while (stok == null || !stok.hasMoreElements()) {
            String s = null;
            try {
                s = br.readLine();
            } catch (IOException e) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }
}