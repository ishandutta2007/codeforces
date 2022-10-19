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
        long[] a = new long[26];
        int size = in.nextInt();
        long total = 0;
        for(int i=0; i<size; i++){
            long curr = in.nextInt();
            for(int j=0; j<i; j++){
                if (a[j]==curr&&curr>0){
                    j=-1;
                    curr--;
                }
            }
            total+=curr;
            a[i]=curr;
        }
        System.out.println(total);
    } 
}