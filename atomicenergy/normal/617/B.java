import java.util.*;
import java.math.*;
import java.io.*;
/**
 *
 * @author Zach
 */

public class ACM {
   
    
   
   
    
    public static void main(String[] args){
        int i;
        Scanner r = new Scanner(System.in); 
        i = r.nextInt();
        int[] b = new int[100];
        int c=0;
        int[] d = new int[100];
        boolean hitOne=false;
        d[0]=0;
        for(int j=0; j<i; j++){ 
            b[j]=r.nextInt();
            if(b[j]==1&&!hitOne){
                hitOne=true;
                //System.out.println('a');
            }
            else if(b[j]==1){
                c++;
                d[c]=0;
                //System.out.println('b');
            }
            else if(hitOne){
                d[c]++;
                //System.out.println('c');
            }
        }
        long e = 1;
        //5System.out.println(c);
        //System.out.println(d[0] + " " + d[1]);
        for(int f=0; f<c; f++){
            e*=(d[f]+1);
        }
        if(c==0){
            e=1;
        }
        if(!hitOne){
            e=0;
        }
        System.out.println(e);
          
    } 
    
}