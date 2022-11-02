import java.util.*;
import java.io.*;
import java.math.*;

public class ClassC
{
    public static void main(String args[])
    {
        solve();
    }
    static void solve(){
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int z = in.nextInt(), n = in.nextInt(), cnt = 0;
        String s = in.next();
        int a[] = new int[z+2], b[] = new int[z+2];
        if(z == 1){
            System.out.println("0\n" + s);
            return;
        }
        if(n == 2){
            a[0]=0;
            b[0] = 1;
            for(int i = 1; i<z; i++)
                if(s.charAt(i) == s.charAt(i-1)){
                    a[i] = b[i-1];
                    b[i] = a[i-1]+1;
                }
                else {
                    a[i] = a[i-1];
                    b[i] = b[i-1] + 1;
                }
            int u = 0;
            StringBuffer st = new StringBuffer();
            if(a[z-1] < b[z-1]) {
                System.out.println(a[z-1]);
                st.append(s.charAt(z-1));
                u = 1;
            }
            else {
                System.out.println(b[z-1]);
                if(s.charAt(z-1) == 'A')st.append('B');
                else st.append('A');
            }
            for(int i=z-2; i>=0; i--){
                if(s.charAt(i) == s.charAt(i+1)){
                    if(u == 0) st.append(s.charAt(i));
                    else if(s.charAt(i) == 'A'){st.append('B');}
                    else st.append('A');
                    u = 1-u;
                }
                else {
                    if(u == 1) st.append(s.charAt(i));
                    else if(s.charAt(i) == 'A') st.append('B');
                    else st.append('A');
                }
            }
            for(int i = z-1; i>=0; i--)
                System.out.print((char)(st.charAt(i)));
        }
        else {
            for(int i = 0; i<z; i++)
                b[i] = s.charAt(i) - 'A';
            int ans = 0;
            for(int i = 1; i<z; i++)    
                if(b[i] == b[i-1]){
                    ans ++;
                    if(i == z-1){
                        b[i] = get(b[i-1], 5);
                    }
                    else b[i] = get(b[i-1], b[i+1]);
                }
            System.out.println(ans);
            for(int i = 0; i<z; i++)
                System.out.print((char)(b[i] + 'A'));
        }
    }
    static int get(int x, int z){
        for(int i = 0; i<3; i++)
            if(x != i && z!= i) return i;
        return 0;
    }
}