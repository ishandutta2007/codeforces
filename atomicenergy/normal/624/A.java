import java.util.*;
import java.math.*;
import java.io.*;
/**
 *
 * @author Zach
 */

public class ACM {    
    public static void main(String[] args){
        Scanner in = new Scanner (System.in);
        int a, b, c, d;
        a = in.nextInt();
        b = in.nextInt();
        c = in.nextInt();
        d = in.nextInt();
        double e = b-a;
        e/=(c+d);
        System.out.println(e);
    } 
}