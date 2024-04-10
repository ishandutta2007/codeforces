//package codeforces;

import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[])
    {
        int n=sc.nextInt(),k=sc.nextInt(),st=0;

        graph a=new graph(n+5);

        for(int i=1;i<n;i++)
        {
            int t=sc.nextInt();
            if(i==1)
            {
                st=t;
            }
            a.add(i,t+i);
        }

        a.bfs(1);

        if(a.visited[k])
        {
            System.out.println("YES");
        }
        else
        {
            System.out.println("NO");
        }
    }


    static class graph {
        private int size;

        private ArrayList<Integer> adj[];
        public int start[];
        public boolean visited[];
        public int dist[];

        graph(int n) {
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
            //adj[y].add(x);
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

            for (int i : adj[x]) {
                if (i != p) {
                    dfs(i, x);
                }
            }
        }
    }
}