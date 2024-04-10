import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
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
        FDestroyIt solver = new FDestroyIt();
        solver.solve(1, in, out);
        out.close();
    }

    static class FDestroyIt {
        static final int ten = 10;
        static final int maxCost = 3;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            long[][] dp = new long[n + 1][ten]; // dp[i][j] is the max damage after i turns with j cards (mod 10)
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j < ten; j++) {
                    dp[i][j] = Integer.MIN_VALUE;
                }
            }
            dp[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                int k = in.nextInt();
                int[] c = new int[k];
                long[] d = new long[k];
                long[] turn = new long[4]; // turn[cards used]
                List<Long>[] cardsOfCost = new List[maxCost];
                for (int j = 0; j < maxCost; j++) {
                    cardsOfCost[j] = new ArrayList<>();
                }
                for (int j = 0; j < k; j++) {
                    c[j] = in.nextInt();
                    d[j] = in.nextInt();
                    cardsOfCost[c[j] - 1].add(d[j]);
                }
                for (int j = 0; j < maxCost; j++) {
                    Collections.sort(cardsOfCost[j], Comparator.reverseOrder());
                }

                for (int previousTurnCards = 0; previousTurnCards < ten; previousTurnCards++) {
                    for (int used = 0; used <= maxCost; used++) {
                        turn[used] = Long.MIN_VALUE;
                    }
                    turn[0] = 0;
                    for (int ones = 0; ones <= maxCost; ones++) {
                        if (cardsOfCost[0].size() < ones) {
                            continue;
                        }
                        for (int twos = 0; ones + twos * 2 <= maxCost; twos++) {
                            if (cardsOfCost[1].size() < twos) {
                                continue;
                            }
                            for (int threes = 0; ones + twos * 2 + threes * 3 <= maxCost; threes++) {
                                if (cardsOfCost[2].size() < threes) {
                                    continue;
                                }

                                int thisTurnCards = ones + twos + threes;
                                long thisTurnDamage = 0;
                                long maxIndivDamage = 0;
                                for (int count = 0; count < ones; count++) {
                                    thisTurnDamage += cardsOfCost[0].get(count);
                                    maxIndivDamage = Math.max(maxIndivDamage, cardsOfCost[0].get(count));
                                }
                                for (int count = 0; count < twos; count++) {
                                    thisTurnDamage += cardsOfCost[1].get(count);
                                    maxIndivDamage = Math.max(maxIndivDamage, cardsOfCost[1].get(count));
                                }
                                for (int count = 0; count < threes; count++) {
                                    thisTurnDamage += cardsOfCost[2].get(count);
                                    maxIndivDamage = Math.max(maxIndivDamage, cardsOfCost[2].get(count));
                                }

                                if (previousTurnCards + thisTurnCards >= ten) {
                                    thisTurnDamage += maxIndivDamage;
                                }

                                turn[thisTurnCards] = Math.max(turn[thisTurnCards], thisTurnDamage);
                            }
                        }
                    }

                    for (int thisTurnCards = 0; thisTurnCards <= maxCost; thisTurnCards++) {
                        long damage = turn[thisTurnCards];
                        if (damage < 0) continue;
                        int totalCards = previousTurnCards + thisTurnCards;
                        totalCards %= ten;
                        dp[i][totalCards] = Math.max(dp[i][totalCards], dp[i - 1][previousTurnCards] + damage);
                    }
                }
            }

            long answer = 0;
            for (int j = 0; j < ten; j++) {
                answer = Math.max(answer, dp[n][j]);
            }

//        for (int i = 0; i <= n; i++) {
//            for (int j = 0; j < ten; j++) {
//                if (dp[i][j] < 0) {
//                    System.out.print("X\t");
//                } else System.out.print(dp[i][j] + "\t");
//            }
//            System.out.println();
//        }

            out.println(answer);
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

    }
}