import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.lang.Long;

public class Test {
    static long mod = 1000000007;
    static int[] dp;

    static int contains;

    public static void main(String[] args) throws FileNotFoundException {
        PrintWriter out = new PrintWriter(System.out);
        Scanner in = new Scanner();
        int n = in.nextInt();
        int m = in.nextInt();
        Edge[] data = new Edge[m];
        for (int i = 0; i < m; i++) {
            data[i] = new Edge(in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
        }
        Arrays.sort(data);

        int reval = 0;
        int[] max = new int[n];
        ArrayList<Edge>[] set = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            set[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int start = 0;
            int end = set[data[i].x].size() - 1;
            int re = 0;
            while (start <= end) {
                int mid = (start + end) >> 1;
                if (set[data[i].x].get(mid).w < data[i].w) {
                    re = Math.max(re, set[data[i].x].get(mid).x);
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            int tmp = 1 + re;
            reval = Math.max(tmp, reval);

            if (max[data[i].y] < tmp) {
                max[data[i].y] = tmp;
                Edge e = new Edge(tmp, data[i].y, data[i].w);
                int l = set[data[i].y].size();
                while (l > 0 && set[data[i].y].get(l - 1).w >= data[i].w) {
                    set[data[i].y].remove(l - 1);
                    l--;
                }
                set[data[i].y].add(e);
            }

        }

        out.println(reval);

        out.close();
    }

    static class Edge implements Comparable<Edge> {
        int x, y, w;

        public Edge(int x, int y, int w) {
            this.x = x;
            this.y = y;
            this.w = w;
        }

        public int compareTo(Edge o) {
            if (w != o.w)
                return w - o.w;
            return x - o.x;
        }

    }

    static int crossProduct(Point a, Point b) {
        return a.x * b.y + a.y * b.x;
    }

    static long squareDist(Point a) {
        long x = a.x;
        long y = a.y;
        return x * x + y * y;
    }

    static Point minus(Point a, Point b) {
        return new Point(a.x - b.x, a.y - b.y);
    }

    public static boolean nextPer(int[] data) {
        int i = data.length - 1;
        while (i > 0 && data[i] < data[i - 1]) {
            i--;
        }
        if (i == 0) {
            return false;
        }
        int j = data.length - 1;
        while (data[j] < data[i - 1]) {
            j--;
        }
        int temp = data[i - 1];
        data[i - 1] = data[j];
        data[j] = temp;
        Arrays.sort(data, i, data.length);
        return true;
    }

    static class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "{" + x + " " + y + "}";
        }

    }

    static class Entry implements Comparable<Entry> {
        int x, cost;

        public Entry(int x, int cost) {
            super();
            this.x = x;
            this.cost = cost;
        }

        public int compareTo(Entry o) {
            // TODO Auto-generated method stub
            if (cost > o.cost) {
                return 1;
            } else if (cost == o.cost) {
                return -1;
            }

            return 0;
        }
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static class Scanner {

        BufferedReader br;
        StringTokenizer st;

        public Scanner() throws FileNotFoundException {
            // System.setOut(new PrintStream(new
            // BufferedOutputStream(System.out), true));
            br = new BufferedReader(new InputStreamReader(System.in));
            // br = new BufferedReader(new InputStreamReader(new
            // FileInputStream(new File("B-large.in"))));
        }

        public String next() {

            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    throw new RuntimeException();
                }
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }

        public boolean endLine() {
            try {
                String next = br.readLine();
                while (next != null && next.trim().isEmpty()) {
                    next = br.readLine();
                }
                if (next == null) {
                    return true;
                }
                st = new StringTokenizer(next);
                return st.hasMoreTokens();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }
    }
}