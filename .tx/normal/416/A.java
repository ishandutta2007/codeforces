import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int m = -2 * 1000 * 1000 * 1000;
        int M = 2 * 1000 * 1000 * 1000;
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            String r = in.next();
            int x = in.nextInt();
            String a = in.next();
            if ("Y".equals(a)) {
                if (">=".equals(r)) {
                    m = Math.max(m, x);
                }
                if (">".equals(r)) {
                    m = Math.max(m, x + 1);
                }
                if ("<=".equals(r)) {
                    M = Math.min(M, x);
                }
                if ("<".equals(r)) {
                    M = Math.min(M, x - 1);
                }
            } else {
                if ("<".equals(r)) {
                    m = Math.max(m, x);
                }
                if ("<=".equals(r)) {
                    m = Math.max(m, x + 1);
                }
                if (">".equals(r)) {
                    M = Math.min(M, x);
                }
                if (">=".equals(r)) {
                    M = Math.min(M, x - 1);
                }
            }
        }
        if (m <= M) {
            out.println(m);
        } else {
            out.println("Impossible");
        }
    }
}

class FastScanner {
    private BufferedReader br;
    private StringTokenizer st;

    public FastScanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    public String next() {
        try {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        } catch (Exception e) {
            return null;
        }
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}