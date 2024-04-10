import java.math.BigInteger;
import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {

    StringTokenizer st;
    BufferedReader br;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }


    void solve() throws IOException {
        int n = nextInt();
        String s = next();
        Set <Integer> f = new HashSet<>();
        ArrayList <Integer> d = new ArrayList<>();
        int p[] = new int['R' + 1];
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!f.contains((int) s.charAt(i))) {
                d.add((int) s.charAt(i));
            }
            f.add((int) s.charAt(i));
            p[(int) s.charAt(i)]++;
            if (s.charAt(i) == 'B') c1++;
            if (s.charAt(i) == 'G') c2++;
            if (s.charAt(i) == 'R') c3++;
        }
        if (f.size() == 3)
            out.println("BGR");
        else if (f.size() == 1)
            out.println(s.charAt(0));
        else {
            boolean good = true;
            for (int i = 0; i < d.size(); i++) {
                if (p[d.get(i)] <= 1) {
                    good = false;
                }
            }
            if (good) {
                out.println("BGR");
            } else {
                if ((c1 > 1 && c2 > 1) || (c1 > 1 && c3 > 1) || (c2 > 1 && c3 > 1)) {
                    out.println("BGR");
                } else {
                    if (c1 == 1 && c2 == 1) {
                        out.println("R");
                    } else if (c2 == 1 && c3 == 1) {
                        out.println("B");
                    } else if (c1 == 1 && c3 == 1) {
                        out.println("G");
                    } else {
                        if (c1 == 1) {
                            if (c2 > 0)
                                out.println("BR");
                            else
                                out.println("BG");
                        } else if (c2 == 1) {
                            if (c1 > 0)
                                out.println("GR");
                            else
                                out.println("BG");
                        } else if (c3 == 1) {
                            if (c1 > 0)
                                out.println("GR");
                            else
                                out.println("BR");
                        } else {
                            assert(false);
                        }
                    }
                }
            }
        }
    }

    private void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        br.close();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}