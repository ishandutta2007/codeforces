import java.util.*;
import java.io.*;

public class Library {
    public static void main(String [] args) {
        Reader in = new Reader ();
        Writer out = new Writer ();
        int n = in.nextInt();
        int k = in.nextInt();

        int [] a = new int [n + 5];
        for(int i = 1; i <= n; i++) {
            a[i] = in.nextInt();
        }

        int ans = 0;
        TreeSet <Integer> t = new TreeSet <> ();
        TreeSet <Pair> s = new TreeSet <> (new Pair());

        int [] nxt = new int [n + 5];
        int [] last = new int [n + 5];
        Arrays.fill(last, n+1);
        for(int i = n; i >= 1; i--) {
            nxt[i] = last[a[i]];
            last[a[i]] = i;    
        }   
        Arrays.fill(last, 0);

        for(int i = 1; i <= n; i++) {
            last[a[i]] = i;
            if(t.contains(a[i])) {
                s.remove(new Pair(i, a[i]));
                s.add(new Pair(nxt[i], a[i]));
            } 
            else {
                ++ans;
                if(t.size() == k) {
                    int good = s.last().second;
                    t.remove(good);
                    s.remove(new Pair(nxt[last[good]], good));
                }
                t.add(a[i]);
                s.add(new Pair(nxt[i], a[i]));
            }
        }
        System.out.println(ans);
    } 
    static class Reader {
        private StringTokenizer a;
        private BufferedReader b;
        Reader () {
            a = null;
            b = new BufferedReader (new InputStreamReader (System.in));
        }
        public String next () {
            while(a == null || !a.hasMoreTokens()) {
                try {
                    a = new StringTokenizer (b.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return a.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(this.next());
        }
        public long nextLong () {
            return Long.parseLong(this.next());
        }
        public double nextDouble () {
            return Double.parseDouble(this.next());
        }
        public String nextLine() {
            try {
                return b.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return "";
        }
    }
    static class Writer {
        private PrintWriter a;
        private StringBuffer b;
        Writer () {
            a = new PrintWriter (System.out);
            b = new StringBuffer ("");
        }
        public void write (Object s) {
            b.append(s);
        }
        public void writeln(Object s) {
            b.append(s).append('\n');
        }
        public void flush () {
            a.print(b);
            a.flush();
            a.close();
        }
    }
    static class Pair implements Comparator <Pair> {
        int first;
        int second;
        Pair  (int a, int b) {
            this.first = a;
            this.second = b;
        }
        Pair (Pair a) {
            this.first = a.first;
            this.second = a.second;
        } 
        Pair () {}
        public String toString () {
            return "[" + first + ", " + second + "]";
        }
        public int compare (Pair a, Pair b) {
            if(a.first == b.first) {
                return a.second - b.second;
            } else {
                return a.first - b.first;
            }
        }
    } 
}