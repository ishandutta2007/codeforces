import java.util.*;
import java.math.*;
import java.io.*;
/**
 *
 * @author Zach
 */

public class ACM2 {
  
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a = -1;
        int b =-1;
        int c = -1;
        for(int i=0; i<n; i++){
            int x = in.nextInt();
            if(x!=a){
                if(a == -1){
                    a = x;
                }
                else{
                  if(x!=b){
                if(b == -1){
                    b = x;
                }
                else{
                    if(x!=c){
                if(c == -1){
                    c = x;
                }
                else{
                    System.out.println("NO");
                    return;
                }
            }
                }
            }  
                }
            }
        }
        if(c==-1 || a+b==2*c || a+c==2*b || b+c==2*a){
            System.out.println("YES");

        }
        else{
            System.out.println("NO");
        }
    }
}