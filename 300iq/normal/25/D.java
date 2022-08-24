import java.util.*;
import java.io.*;

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

    int parent[] = new int[1001];

    int find(int a) {
        if (parent[a] == a)
            return a;
        parent[a] = find(parent[a]);
        return parent[a];
    }

    boolean union(int a, int b) {
        if (find(a) == find(b)) return false;
        parent[find(a)] = parent[find(b)];
        return true;
    }

    void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++)
            parent[i] = i;
        int l[] = new int[n + 1];
        int r[] = new int[n + 1];
        int head = 0;
        for (int i = 0; i < n - 1; i++) {
            int a = nextInt(), b = nextInt();
            a--;
            b--;
            if (!union(a, b)) {
                l[head] = a;
                r[head] = b;
                head++;
            }
        }
        out.println(head);
        int tail = 0;
        for (int i = 0; i < n; i++) {
            if (union(0, i)) {
                out.println((l[tail] + 1) + " " + (r[tail] + 1) + " " + 1 + " " + (i + 1));
                tail++;
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