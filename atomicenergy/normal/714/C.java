import java.util.*;
import java.util.Arrays;
import java.math.*;
import java.io.*;
/**
 *
 * @author Zach
 */



public class ACM {    
    public static long simplify(long i){
        long x = 2000000000;
        x*=1000000000;
        while(x>1){
        while(i%(5*x)>=x){
            i-=x;
        }
        x/=10;
        }
        return i;
    }
    
    public static void main(String[] args){
        
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Hashtable<Long, Integer> h = new Hashtable<Long,Integer>();
        for(int i=0; i<n; i++){
            String c = in.next();
            long x = in.nextLong();
            if(c.equals("+")){
                if(h.containsKey(simplify(x))){
                    h.put(simplify(x), h.get(simplify(x))+1);
                }
                else{
                    h.put(simplify(x), 1);
                }
            }
            if(c.equals("-")){
                h.put(simplify(x), h.get(simplify(x))-1);
            }
            if(c.equals("?")){
                if(h.containsKey(x)){
                    System.out.println(h.get(x));
                }
                else{
                    System.out.println(0);
                }
            }
        }
        
        
    }
}