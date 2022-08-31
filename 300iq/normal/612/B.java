import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {

    class FastScanner {
        BufferedReader br;
        StringTokenizer stok;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String nextToken() throws IOException {
            while (stok == null || !stok.hasMoreTokens()) {
                String s = br.readLine();
                if (s == null) {
                    return null;
                }
                stok = new StringTokenizer(s);
            }
            return stok.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        long nextLong() throws IOException {
            return Long.parseLong(nextToken());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(nextToken());
        }

        char nextChar() throws IOException {
            return (char) (br.read());
        }

        String nextLine() throws IOException {
            return br.readLine();
        }
    }

    FastScanner in = new FastScanner(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int n, p, q, t;
    boolean logic, flag;
    public class Pair implements Comparable <Pair> {
        int a;
        int b;
        public Pair (int f, int s) {
            a = f;
            b = s;
        }
        @Override
        public int compareTo(Pair pair) {
            if (this.a > pair.a) {
                return 1;
            }
            else if (this.a < pair.a) {
                return -1;
            }
            else if (this.a == pair.a) {
                if (this.b > pair.b) {
                    return 1;
                }
                else if (this.b < pair.b) {
                    return -1;
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
    }
    ArrayList <Pair> a = new ArrayList<>();
    private void solve() throws IOException {
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            a.add(new Pair(in.nextInt(), i));
        }
        Collections.sort(a);
        long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans += Math.abs(a.get(i).b - a.get(i + 1).b);
        }
        out.println(ans);
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}