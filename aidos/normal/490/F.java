import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;


public class SolutionF {
    public static void main(String [] args){
        new SolutionF().run();
    }
    PrintWriter out;
    FastScanner in;
    HashMap<Integer, Integer> hm;
    HashSet<Integer> hs;
    int n;
    int rr[];
    int dis[];
    ArrayList<Integer> arr[];
    int ans = 0;
    void dfs(int cur, int p){
        int l = 0;
        int r = n - 1;
        int a = n-1;
        while( l <= r){
            int mid = (l+r) >> 1;
            if(dis[mid] >= rr[cur]){
                a = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        int val = dis[a];
        dis[a] = rr[cur];
        ans = Math.max(ans, a+1);
        for(int t: arr[cur]){
            if( t == p) continue;
            dfs(t, cur);
        }
        dis[a] = val;
    }
    void solve(){
        n = in.nextInt();
        arr=new ArrayList[n];
        hs = new HashSet<Integer>();
        hm = new HashMap<Integer, Integer>();
        dis = new int[n];
        rr = new int[n];
        for(int i = 0; i<n; i++){
            rr[i] = in.nextInt();
            dis[i] = Integer.MAX_VALUE;
            arr[i] = new ArrayList<Integer>();
        }
        int cnt = 0;
        
        for(int i = 1; i<n; i++){
            int x = in.nextInt()-1;
            int y = in.nextInt()-1;
            arr[x].add(y);
            arr[y].add(x);
        }
        for(int i = 0; i < n; i++) dfs(i, -1);
        out.println(ans);
    }
    public void run(){
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }
    class FastScanner{
        BufferedReader bf;
        StringTokenizer st;
        public FastScanner(InputStream is){
            bf = new BufferedReader(new InputStreamReader(is));
        }
        String next(){
            while(st == null || !st.hasMoreTokens()){
                try{
                    st = new StringTokenizer(bf.readLine());
                }
                catch(Exception ex){
                    ex.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
    }
}