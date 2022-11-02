import java.util.*;
import java.io.*;
import java.math.*;

public class ClassB
{
	public static void main(String args[])
	{
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		long n = in.nextLong(), k = in.nextLong(), a[] = new long[111], b[] = new long[111];
		a[1] = 9;
		b[0] = 1;
		for(int i = 1; i<19; i++)
			b[i] = b[i-1] * 10L;
		for(int i = 2; i<19; i++)
			a[i] = a[i-1] * 10L + 9;
		long get = n;
        for(int i = 18; i>0; i--){
        	long ans = a[i];
			for( ; ; ){
				boolean ok = true;
				for(int j=18; j>=i; j--)
					if(ans + b[j] <= n && ok) {ans += b[j]; ok = false;}
				if(ok) break;
			}
			if(n>= ans&& n-ans<= k){
				get = ans;
				break;				
			}
        }
        System.out.println(get);
	}
}