import java.awt.Point;
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class C {
    static class Solver {
        MyReader mr = new MyReader();
        Map<Character,Set<Character>> g;
        Set<Character> used;
        public void solve() {
            int t = mr.nextInt();
            out:
            while (t-- > 0){
                String s = mr.next();
                g = new HashMap<>();

                StringBuilder res = new StringBuilder();
                int n = s.length();
                if(n == 1){
                    res.append(s);
                    for(char c ='a';c<='z';c++){
                        if(c == s.charAt(0))continue;
                        res.append(c);
                    }

                    System.out.println("YES");
                    System.out.println(res.toString());
                    continue;
                }
                for(int i = 0;i<n-1;i++){
                    char u = s.charAt(i);
                    char v = s.charAt(i+1);

                    if(g.containsKey(u)){
                        g.get(u).add(v);
                    }
                    else{
                        Set<Character> tmp = new HashSet<>();
                        tmp.add(v);
                        g.put(u,tmp);
                    }

                    if(g.containsKey(v)){
                        g.get(v).add(u);
                    }
                    else{
                        Set<Character> tmp = new HashSet<>();
                        tmp.add(u);
                        g.put(v,tmp);
                    }

                    if(g.get(u).size() > 2 || g.get(v).size() > 2){
                        System.out.println("NO");
                        continue out;
                    }
                }

                used = new HashSet<>();



                boolean found = false;
                for(char c = 'a';c <= 'z';c++){
                    if(!g.containsKey(c) || g.get(c).size() > 1)continue;


                    found = true;
                    dfs(c,res,'.');
                    break;
                }

                if(!found){
                    System.out.println("NO");
                    continue;
                }

                for(char c = 'a';c<='z';c++){
                    if(used.contains(c))continue;
                    res.append(c);
                }

                System.out.println("YES");
                System.out.println(res.toString());
            }
        }

        private void dfs(char c, StringBuilder res, char parent) {
            res.append(c);
            used.add(c);

            for(char cc : g.get(c))if(cc!=parent){
                dfs(cc,res,c);
            }
        }
    }

    public static void main(String[] args) {
        new Solver().solve();
    }

    static class MyReader {
        BufferedReader br;
        StringTokenizer st;

        MyReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }

            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String res = "";
            try {
                res = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            return res;
        }

        Integer[] nextIntArray(int n) {
            Integer[] arr = new Integer[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }

            return arr;
        }

        Long[] nextLongArray(int n) {
            Long[] arr = new Long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }

            return arr;
        }

        String[] nextStringArray(int n) {
            String[] arr = new String[n];
            for (int i = 0; i < n; i++) {
                arr[i] = next();
            }
            return arr;
        }
    }

    static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

}