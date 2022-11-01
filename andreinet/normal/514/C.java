import java.util.HashSet;
import java.util.InputMismatchException;
import java.io.InputStream;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    final int Mod1 = 666013, Mod2 = 666019;
    HashSet<Pairii> strings;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), M = in.nextInt();

        strings = new HashSet<>();
        for (int i = 0; i < N; ++i)
            strings.add(getHashKey(in.next()));

        for (int i = 0; i < M; ++i)
            out.println(query(in.next()));
    }

    private Pairii getHashKey(String A) {
        int key1 = 0, key2 = 0;
        for (int c: A.toCharArray()) {
            c -= 'a';
            key1 = (key1 * 3 + c) % Mod1;
            key2 = (key2 * 3 + c) % Mod2;
        }
        return new Pairii(key1, key2);
    }

    private String query(String A) {
        int N = A.length();
        int[] key1st = new int[N + 1], key2st = new int[N + 1];
        for (int i = 1; i <= N; ++i) {
            int c = A.charAt(i - 1) - 'a';
            key1st[i] = (key1st[i - 1] * 3 + c) % Mod1;
            key2st[i] = (key2st[i - 1] * 3 + c) % Mod2;
        }
        int key1dr = 0, key2dr = 0;
        for (int i = N, pw1 = 1, pw2 = 1; i > 0; --i) {
            int c = A.charAt(i - 1) - 'a';

            for (int c1 = 0; c1 < 3; ++c1) {
                if (c1 == c) continue;
                int key1 = (int) ((key1dr + pw1 * (c1 + 3L * key1st[i - 1])) % Mod1);
                int key2 = (int) ((key2dr + pw2 * (c1 + 3L * key2st[i - 1])) % Mod2);
                if (strings.contains(new Pairii(key1, key2)))
                    return "YES";
            }

            key1dr = (int) ((key1dr + 1L * pw1 * c) % Mod1);
            key2dr = (int) ((key2dr + 1L * pw2 * c) % Mod2);
            pw1 = 3 * pw1 % Mod1;
            pw2 = 3 * pw2 % Mod2;
        }

        return "NO";
    }
}

class Pairii implements Comparable<Pairii> {
    public int first, second;

    public Pairii(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public int compareTo(Pairii other) {
        if (first != other.first) return first < other.first ? -1: 1;
        if (second != other.second) return second < other.second ? -1: 1;
        return 0;
    }

    public boolean equals(Object other) {
        if (!(other instanceof Pairii)) return false;
        return compareTo((Pairii) other) == 0;
    }

    public int hashCode() {
        return first * 31 + second;
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