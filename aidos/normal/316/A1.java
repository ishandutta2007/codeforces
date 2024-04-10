import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        String s = in.next();
        int n = s.length(), k = 0, a[] = new int[15];
        for(int i = 0; i<n; i++){
            char c = s.charAt(i);
            if(c=='?') k++;
            else if(c>='A' && c<='J') a[c-'A']++;
        }
        BigInteger b = BigInteger.ONE, u = BigInteger.valueOf(10);
        boolean z = false;
        if(s.charAt(0)=='?') {
            k--;
            b = b.multiply(BigInteger.valueOf(9));
        }
        else if(s.charAt(0)>='A' && s.charAt(0) <= 'J') z = true;
        b = b.multiply((u).pow(k));
        if(z){
            int t = 0, x = 9;
            for(int i = 0; i<11; i++)
                if(a[i]>0) t++;
            for(int i = 1; i<t; i++){
                b=b.multiply(BigInteger.valueOf(x));                                            
                x--;
            }
            b = b.multiply(BigInteger.valueOf(9));
        }
        else {
            int t = 0, x = 10;
            for(int i = 0; i<11; i++)
                if(a[i]>0) t++;
            for(int i = 0; i<t; i++){
                b=b.multiply(BigInteger.valueOf(x));                                            
                x--;
            }
        }
        pw.print(b.toString());
        pw.close();
    }
}