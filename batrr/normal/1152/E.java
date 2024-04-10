import java.util.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static Scanner sc = new Scanner(System.in);
    private static HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
    private static HashMap<Integer, Integer> mh = new HashMap<Integer, Integer>();
    private static int m;
    public static void main(String[] args) {
        int n = sc.nextInt();
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];

        //Vector[] g = new Vector[2 * n];
        List<Integer>[] g = new List[2 * n];
        for(int i = 0; i < 2 * n; i++)
            g[i] = new ArrayList<Integer>();

        Vector< Integer > ans = new Vector<Integer>();
        int[] ptr = new int[2 * n];
        boolean[] used = new boolean[2 * n];
        for (int i = 1; i < n; i++)
            a[i] = get(sc.nextInt());
        for (int i = 1; i < n; i++)
            b[i] = get(sc.nextInt());
        for (int i = 1; i < n; i++) {
            if (mh.get(a[i])> mh.get(b[i])) {
                System.out.print("-1");
                return;
            }
        }
        for (int i = 1; i < n; i++) {
            g[a[i]].add(i);
            g[b[i]].add(i);
        }
        int v1 = -1, v2 = -1;
        for (int i = 0; i < 2 * n; i++)
            if ((g[i].size() & 1) == 1) {
                if(v1 == -1)
                    v1 = i;
                else if(v2 == -1)
                    v2 = i;
                else{
                    System.out.print(-1);
                    return;
                }
            }
        if(v1 != -1) {
            a[n] = v1;
            b[n] = v2;
            g[v1].add(n);
            g[v2].add(n);
        }
        Stack<Integer> st = new Stack<Integer>();
        st.add(0);
        while (!st.empty()) {
            int v = st.peek();
            while (ptr[v] < g[v].size() && used[(int) g[v].get(ptr[v])])
                ptr[v]++;
            if (ptr[v] == g[v].size()) {
                st.pop();
                ans.add(v);
            } else {
                used[(int) g[v].get(ptr[v])] = true;
                if (v == b[(int) g[v].get(ptr[v])])
                    st.add(a[(int) g[v].get(ptr[v])]);
                else
                    st.add(b[(int) g[v].get(ptr[v])]);
            }
        }
        boolean ok = true;
        for(int i = 1; i < n; i++)
            ok &= used[i];
        if (!ok) {
            System.out.println(-1);
            return;
        }
        int j = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (ans.get(i) == v1 && ans.get(i + 1) == v2)
                j = i + 1;
            if (ans.get(i) == v2 && ans.get(i + 1) == v1)
                j = i + 1;
        }
        for (int i = 0; i < n; i++)
            System.out.print(mh.get(ans.get((i + j) % n)) + " ");
    }
    public static int get(int x){
        if (!hm.containsKey(x)) {
            mh.put(m, x);
            hm.put(x, m++);
        }
        return hm.get(x);
    }

}