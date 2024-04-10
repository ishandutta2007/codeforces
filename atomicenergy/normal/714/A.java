import java.util.*;
import java.util.Arrays;
import java.math.*;
import java.io.*;
/**
 *
 * @author Zach
 */


public class ACM2 {    
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        long a = in.nextLong();
        long b = in.nextLong();
        long c = in.nextLong();
        long d = in.nextLong();
        long e = Math.max(a,c);
        long f = Math.min(b,d);
        long k = in.nextLong();
        if(f<e){
            System.out.println(0);
        }
        else if(k>=e&&k<=f){
            System.out.println(f-e);
        }
        else{
            System.out.println(f-e+1);
        }
        
        
    }
}