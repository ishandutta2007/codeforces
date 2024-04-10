import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
}

class TaskE {
    private final int Valmax = 2000001;

    private ArrayList<Integer>[] G;
    private int[] Values;
    private int[] Primes;
    private int[] Level;
    private int[] Next;
    private int[][] NodeDiv;
    private int[] Ans;

    private void GetPrimes() {
        boolean[] Prime = new boolean[Valmax];
        ArrayList<Integer> P = new ArrayList<Integer>();
        P.add(2);

        for (int i = 3; i * i < Valmax; i += 2) {
            if (!Prime[i]) {
                for (int j = i * i; j < Valmax; j += i)
                    Prime[j] = true;
            }
        }

        for (int i = 3; i < Valmax; i += 2)
            if (!Prime[i])
                P.add(i);

        Primes = new int[P.size()];
        for (int i = 0; i < Primes.length; ++i)
            Primes[i] = P.get(i);
    }

    private void GetLevel(int node, int father) {
        for (int p: G[node]) {
            if (p == father)
                continue;

            Level[p] = Level[node] + 1;
            GetLevel(p, node);
        }
    }

    private int[] GetDivs(int N) {
        ArrayList<Integer> Divs = new ArrayList<Integer>();

        for (int i = 0; i < Primes.length && Primes[i] * Primes[i] <= N; ++i) {
            if (N % Primes[i] == 0) {
                Divs.add(Primes[i]);

                while (N % Primes[i] == 0)
                    N /= Primes[i];
            }
        }

        if (N > 1)
            Divs.add(N);

        int[] ret = new int[Divs.size()];
        for (int i = 0; i < ret.length; ++i)
            ret[i] = Divs.get(i);

        return ret;
    }

    private void Dfs(int node, int father, int where) {
        if (where == 0 || where == node)
            NodeDiv[node] = GetDivs(Values[node]);
        int[] Divs = NodeDiv[node];

        int[] NextSaved = new int[Divs.length];
        int F = -1;
        for (int i = 0; i < Divs.length; ++i) {
            NextSaved[i] = Next[Divs[i]];
            if (Next[Divs[i]] != 0 && (F == -1 || Level[Next[Divs[i]]] > Level[F]))
                F = Next[Divs[i]];
            Next[Divs[i]] = node;
        }
        
        Ans[node] = F;

        for (int p: G[node]) {
            if (p == father)
                continue;

            Dfs(p, node, where);
        }

        for (int i = 0; i < Divs.length; ++i)
            Next[Divs[i]] = NextSaved[i];
    }

    private void UpdateStuff(int where) {
        Dfs(1, 0, where);
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), Q = in.nextInt();

        G = new ArrayList[N + 1];
        for (int i = 0; i <= N; ++i)
            G[i] = new ArrayList<Integer>();

        Values = new int[N + 1];
        for (int i = 1; i <= N; ++i)
            Values[i] = in.nextInt();

        for (int i = 1; i < N; ++i) {
            int x = in.nextInt(), y = in.nextInt();

            G[x].add(y);
            G[y].add(x);
        }

        GetPrimes();

        Level = new int[N + 1];
        GetLevel(1, 0);

        Next = new int[Valmax];
        Ans = new int[N + 1];
        NodeDiv = new int[N + 1][];
        UpdateStuff(0);

        while (Q-- > 0) {
            int op = in.nextInt();

            if (op == 1) {
                int x = in.nextInt();
                out.println(Ans[x]);
            } else {
                int x = in.nextInt(), y = in.nextInt();
                Values[x] = y;

                UpdateStuff(x);
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