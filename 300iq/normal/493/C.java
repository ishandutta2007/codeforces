import java.io.*;
import java.util.*;


public class Main {

    class FastScanner {
        BufferedReader br;
        StringTokenizer stok;

        FastScanner(InputStream is) throws FileNotFoundException {
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

    FastScanner in;
    PrintWriter out;

    class Goal implements Comparable<Goal> {
        int team, distance;
        public Goal(int t, int d) {
            team = t;
            distance = d;
        }
        @Override
        public int compareTo(Goal goal) {
            if (this.distance > goal.distance) {
                return 1;
            }
            else {
                return -1;
            }
        }
    }
    private void solve() throws IOException {
        int n = in.nextInt();
        ArrayList <Goal> x = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            x.add(new Goal(1, in.nextInt()));
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            x.add(new Goal(2, in.nextInt()));
        }
        Collections.sort(x);
        int t1, t2;
        int ans1, ans2;
        ans1 = t1 = n * 2;
        ans2 = t2 = m * 2;
        n += m;
        for (int i = n - 1; i >= 0;) {
            do {
                if (x.get(i).team == 1) {
                    t1++;
                }
                else {
                    t2++;
                }
                i--;
            }while(i >= 0 && x.get(i).distance == x.get(i + 1).distance);
            if (t1 - t2 > ans1 - ans2 || (t1 - t2 == ans1 - ans2 && t1 > ans1)) {
                ans1 = t1;
                ans2 = t2;
            }

        }
        out.println(ans1 + ":" + ans2);
    }

    private void run() throws IOException {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}