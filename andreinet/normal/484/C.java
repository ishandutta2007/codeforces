import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
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
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    int[] whichVector, whichPos, from, sum;
    boolean[] used;
    ArrayList<Integer>[] cycles;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String S = in.nextString();

        int N = S.length(), Q = in.nextInt();

        whichPos = new int[N + 1];
        whichVector = new int[N + 1];
        sum = new int[N + 1];
        used = new boolean[N + 1];
        cycles = new ArrayList[N];
        from = new int[N];
        char[] newS = new char[N];
        while (Q-- > 0) {
            int k = in.nextInt(), d = in.nextInt();

            Arrays.fill(sum, 0);
            for (int i = 0; i < k; ++i)
                sum[i % d + 1]++;
            for (int i = 1; i <= d; ++i)
                sum[i] += sum[i - 1];

            genNextPos(k, d);
            for (int i = 0; i < N; ++i) {
                int c = Math.max(0, i - k + 1), o = i < k ? i: k - 1;
                int cnt = N - Math.max(i, k - 1);
                int vec = whichVector[o], pos = whichPos[o];
                int npos;
                if (vec == 0) {
                    if (pos + cnt >= cycles[vec].size() - 1) npos = cycles[vec].size() - 1 - pos + c - 1;
                    else npos = c + cnt + cycles[vec].get(pos + cnt);
                } else {
                    npos = c + cnt + cycles[vec].get((pos + cnt) % cycles[vec].size());
                }

                newS[npos] = S.charAt(i);
            }

            S = new String(newS);
            out.println(S);
        }
    }

    void genNextPos(int k, int d) {
        Arrays.fill(used, false);
        Arrays.fill(from, -1);
        for (int i = 1; i < k; ++i)
            from[sum[i % d] + i / d - 1] = i;

        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            if (!used[i]) {
                if (cycles[cnt] != null) cycles[cnt].clear();
                else cycles[cnt] = new ArrayList<>();
                for (int j = i; j != -1 && !used[j]; j = from[j]) {
                    used[j] = true;
                    cycles[cnt].add(j);
                }
                Collections.reverse(cycles[cnt]);
                if (cnt == 0) cycles[cnt].add(-1);

                int step = 0;
                for (int p: cycles[cnt]) {
                    if (p != -1) {
                        whichVector[p] = cnt;
                        whichPos[p] = step++;
                    }
                }
                cnt++;
            }
        }
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
        return Integer.parseInt(nextString());
    }

    public String nextString() {
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