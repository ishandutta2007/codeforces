import java.util.*;

public class HelloWorld{

     public static void main(String []args){
        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt(), l = inp.nextInt(), r = inp.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for(int i = 0; i < n; ++i) a[i] = inp.nextInt();
        for(int i = 0; i < n; ++i) b[i] = inp.nextInt();
        --l; --r;
        boolean cond = true;
        for(int i = 0; i < n; ++i)
        {
            if (i < l || i > r) cond = cond && (a[i] == b[i]);
        }
        if (cond) System.out.println("TRUTH");
        else System.out.println("LIE");
     }
}