import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class SolutionE {
    public static void main(String [] args){
        new SolutionE().run();
    }
    PrintWriter out;
    FastScanner in;
    String str[];
    int n;
    String last = "";
    boolean can(char x, char y){
        if( x=='?') return true;
        if( x == y) return true;
        return false;
    }
    void solve(){
        n = in.nextInt();
        str = new String[n];
        boolean ok = true;
        for(int i = 0; i < n; i++){
            String cur = in.next();
            if(last.length() < cur.length()){
                last = "";
                for(int j = 0; j < cur.length(); j++){
                    if(cur.charAt(j) == '?'){
                        if( j == 0) last += '1';
                        else last += '0';
                    }
                    else last += cur.charAt(j);
                }
            }
            else if( cur.length() == last.length()){
                String ne="";
                int t = -1;
                for(int j = cur.length()- 1; t == -1 && j>=0; j--){
                    if(last.charAt(j) == '9' || (cur.charAt(j) !='?' && cur.charAt(j) <= last.charAt(j))) continue;
                    boolean ok2 = true;
                    for(int k = 0; k<j && ok2; k++){
                        if(!can(cur.charAt(k), last.charAt(k)) ){
                            ok2 = false;
                        }
                    }
                    if(ok2) t = j;
                }
                if(t != -1){
                    for(int j = 0; j < t; j++){
                        ne += last.charAt(j);
                    }
                    if(cur.charAt(t) == '?') ne += (char) (last.charAt(t) + 1);
                    else ne += cur.charAt(t);
                    for(int j = t+1; j < cur.length(); j++){
                        if(cur.charAt(j) != '?') ne += cur.charAt(j); 
                        else ne += '0';
                    }
                    last = ne;
                    //out.println(ne);
                }
                else ok = false;
            }
            else ok = false;
            str[i] = last;
        }
        if(ok && str[0].equals("0")) ok  = false;
        if(!ok) out.println("NO");
        else {
            out.println("YES");
            for(int i = 0; i < n; i++) out.println(str[i]);
        }
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