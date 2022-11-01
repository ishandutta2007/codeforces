import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Collection;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;

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
}

class TaskE {
    final int Mod = (int) (1e9 + 7);
    int[] fact;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), K = in.nextInt();

        HashMap<Integer, Integer> count = new HashMap<>();
        fact = new int[N + 1];
        fact[0] = 1;

        int cntp = 0;
        for (int i = 1; i <= N; ++i) {
            fact[i] = (int) (1L * fact[i - 1] * i % Mod);
            int x = in.nextInt();
            if (lucky(x)) {
                if (!count.containsKey(x)) count.put(x, 1);
                else count.put(x, count.get(x) + 1);
            } else ++cntp;
        }

        int[] values = new int[count.size()];
        int pos = 0;
        for (int p: count.values())
            values[pos++] = p;
        N = values.length;

        int ans = Comb(cntp, K);
        int[] dp = new int[N + 1];
        Arrays.fill(dp, 1);
        for (int i = 1; i <= K; ++i) {
            int[] ndp = new int[N + 1];
            for (int j = i; j <= N; ++j)
                ndp[j] = (int) ((1L * dp[j - 1] * values[j - 1] + ndp[j - 1]) % Mod);
            dp = ndp;
            ans = (int) ((ans + 1L * Comb(cntp, K - i) * dp[N]) % Mod);
        }
        out.println(ans);
    }

    private int Pow(int x, int y) {
        int ret = 1;
        for (; y > 0; y >>= 1) {
            if ((y & 1) != 0) ret = (int) (1L * ret * x % Mod);
            x = (int) (1L * x * x % Mod);
        }
        return ret;
    }

    private int invmod(int x) {
        return Pow(x, Mod - 2);
    }

    private int Comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return (int) (1L * fact[n] * invmod((int) (1L * fact[k] * fact[n - k] % Mod)) % Mod);
    }

    private boolean lucky(int x) {
        while (x > 0) {
            if (x % 10 != 4 && x % 10 != 7) return false;
            x /= 10;
        }
        return true;
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
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