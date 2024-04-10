import java.util.*;
import static java.lang.Math.*;

public class contest1
{
    private static Scanner sc=new Scanner(System.in);

    public static void main(String args[])
    {
        problem_2 a=new problem_2();
    }

    static class problem_1
    {
        problem_1()
        {
            int n=sc.nextInt() , m=sc.nextInt();
            int p=(int)pow(2,(min(32,n)));

            System.out.printf("%d",m%p);
        }
    }

    static class problem_2
    {
        graph.search gs;

        public boolean check(int x,int p)
        {
            boolean b=true;
            int cnt=0;
            for (int i:gs.adj[x])
            {
                if(gs.adj[i].size()==1)
                {
                    cnt++;
                }
                if(gs.adj[i].size()!=1 && i!=p && b)
                {
                    b=check(i,x);
                }
            }

            return(cnt>=3 && b);
        }

        problem_2()
        {
            int n=sc.nextInt();
            gs=new graph.search(n);

            for(int i=2;i<=n;i++)
            {
                int x=sc.nextInt();
                gs.add(i,x);
            }

            if(check(1,-1))
            {
                System.out.printf("%s","Yes");
            }
            else
            {
                System.out.printf("%s","No");
            }
        }

        static class graph {
            static class search {
                private int size;
                public ArrayList<Integer> adj[];
                public int start[];
                public boolean visited[];
                public int t=0;

                search(int n) {
                    size = n + 2;

                    visited = new boolean[size];
                    start = new int[size];
                    adj = new ArrayList[size];

                    for (int i = 0; i < size; i++) {
                        adj[i] = new ArrayList<>();
                    }
                }

                public void add(int x, int y) {
                    adj[x].add(y);
                    adj[y].add(x);
                }

                public void bfs(int st) {
                    start[st] = 0;
                    visited[st] = true;

                    ArrayList<Integer> l = new ArrayList<>();
                    l.add(st);

                    while (l.size() != 0) {
                        st = l.get(0);
                        l.remove(0);

                        for (int i : adj[st]) {
                            if (!visited[i]) {
                                visited[i] = true;
                                start[i] = start[st] + 1;
                                l.add(i);
                            }
                        }
                    }
                }

                public void dfs(int x, int p) {
                    start[x] = (p == -1 ? 0 : start[p] + 1);
                    boolean b=true;

                    for (int i : adj[x]) {
                        if (i != p) {
                            dfs(i, x);
                            b=false;
                        }
                    }

                    if(b)
                    {
                        t++;
                    }
                }
            }

            static class Dijkstra {
                private static final int MAXN = 1000 + 10;
                private static final int INF = 1000 * 1000 * 1000;
                public boolean adj[][];
                public boolean mark[];
                public int w[][];
                public int dist[];
                public int n, m;

                Dijkstra(int n1, int m1) {
                    n = n1 + 1;
                    m = m1;

                    adj = new boolean[n][n];
                    mark = new boolean[n];
                    w = new int[n][n];
                    dist = new int[n];

                    for (int i = 0; i < m; i++) {
                        int u = sc.nextInt(), v = sc.nextInt(), z = sc.nextInt();
                        adj[u][v] = true;
                        w[u][v] = z;
                        adj[v][u] = true;
                        w[v][u] = z;
                    }
                }

                public void dijkstra(int s) {
                    dist[s] = 0;
                    for (int i = 0; i < n; ++i) {
                        if (i != s) {
                            dist[i] = INF;
                        }
                        mark[i] = false;
                    }

                    for (int rep = 0; rep < n; ++rep) {
                        int u = -1;
                        int du = INF;
                        for (int i = 0; i < n; ++i) {
                            if (!mark[i] && dist[i] < du) {
                                u = i;
                                du = dist[i];
                            }
                        }

                        if (u != -1) {
                            mark[u] = true;
                            for (int v = 0; v < n; ++v)
                                if (adj[u][v])
                                    dist[v] = Math.min(dist[v], dist[u] + w[u][v]);
                        }
                    }
                }
            }

            static class BellmanFord {
                private static final int MAXN = 1000 + 10;
                private static final int INF = 1000 * 1000 * 1000;
                public int[][] edge;
                public ArrayList<Integer> w = new ArrayList<>();
                public int dist[];
                public int n, m;

                BellmanFord(int n1, int m1) {
                    n = n1 + 1;
                    m = m1;

                    edge = new int[m][2];
                    dist = new int[n];

                    for (int i = 0; i < m; i++) {
                        int u = sc.nextInt(), v = sc.nextInt(), z = sc.nextInt();
                        edge[i][0]=u;
                        edge[i][1]=v;
                        w.add(z);
                    }
                }

                public void bellmanFord(int s) {
                    dist[s] = 0;
                    for (int i = 0; i < n; ++i)
                        if (i != s)
                            dist[i] = INF;
                    for (int i = 0; i < n - 1; ++i) {
                        boolean br=true;
                        for (int j = 0; j < m; j++) {
                            int u = edge[j][0];
                            int v = edge[j][1];
                            if(dist[u] + w.get(j)<dist[v])
                            {
                                br=false;
                                dist[v]=dist[u] + w.get(j);
                            }
                            if(dist[v] + w.get(j)<dist[u])
                            {
                                br=false;
                                dist[u]=dist[v] + w.get(j);
                            }
                        }

                        if (br)
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
}