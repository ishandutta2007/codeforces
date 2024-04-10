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

    class Event implements Comparable <Event> {
        int t, e;

        public Event(int t, int e) {
            this.t = t;
            this.e = e;
        }

        @Override
        public int compareTo(Event event) {
            if (this.t > event.t) {
                 return 1;
            }
            else if (this.t < event.t) {
                return -1;
            }
            else if (this.t == event.t) {
                if (this.e > event.e) {
                    return 1;
                }
                else if (this.e < event.e) {
                    return -1;
                }
                else {
                    return 0;
                }
            }
            return 0;
        }
    }

    private void solve() throws IOException {
        ArrayList <Event> f = new ArrayList<>();
        ArrayList <Event> g = new ArrayList<>();
        int n = in.nextInt();
        int k = in.nextInt();
        for (int i = 0; i < n; i++) {
            f.add(new Event(in.nextInt(), -1));
            f.add(new Event(in.nextInt(), 1));
        }
        Collections.sort(f);
        int l = 0;
        int r = 0;
        int x = 0;
        for (int i = 0; i < f.size(); i++) {
            if (x == k - 1 && f.get(i).e == -1) {
                l = f.get(i).t;
            }
            else if (x == k && f.get(i).e == 1) {
                r = f.get(i).t;
                g.add(new Event(l, r));
            }
            x -= f.get(i).e;
        }
        out.println(g.size());
        for (int i = 0; i < g.size(); i++) {
            out.println(g.get(i).t + " " + g.get(i).e);
        }
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