import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        DGameWithModulo solver = new DGameWithModulo();
        solver.solve(1, in, out);
        out.close();
    }

    static class DGameWithModulo {
        InputReader in;
        PrintWriter out;
        final int one = 0;
        final int doubling = 1;
        final int narrowing = 2;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            in.next();

            game:
            for (; ; ) {
                int phase = one;


                int min = -1, max = -1;
                int lastGuess = 1;
                askIfOne();

                input:
                for (; ; ) {
                    String next = this.in.next();
                    if (next.equals("start")) {
                        continue game;
                    } else if (next.equals("end")) {
                        break game;
                    }

                    boolean y = next.equals("y");
                    switch (phase) {
                        case one:
                            if (!y) {
                                guess(1);
                                continue input;
                            }
                            phase++;
                            askDouble(lastGuess);
                            lastGuess *= 2;
                            break;

                        case doubling:
                            if (y) {
                                phase++;
                                min = lastGuess / 2 + 1;
                                max = lastGuess;
                                lastGuess = (min + max) / 2;
                                askNarrowing(lastGuess, max);
                            } else {
                                askDouble(lastGuess);
                                lastGuess *= 2;
                                continue input;
                            }
                            break;

                        case narrowing:
                            if (y) {
                                min = lastGuess + 1;
                            } else {
                                max = lastGuess;
                            }
                            if (max - min > 0) {
                                lastGuess = (min + max) / 2;
                                askNarrowing(lastGuess, max);
                            } else {
                                guess(max);
                            }

                            break;
                    }
                }
            }
        }

        public void askDouble(int guess) {
            out.println("? " + 2 * guess + " " + guess);
            out.flush();
        }

        public void askNarrowing(int guess, int max) {
            out.println("? " + (max + 1) + " " + guess);
            out.flush();
        }

        public void askIfOne() {
            out.println("? 0 1");
            out.flush();
        }

        public void guess(int a) {
            out.println("! " + a);
            out.flush();
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

    }
}