import java.util.*;
import java.io.*;
import java.math.*;

public class ClassA
{
	public static void main(String args[])
	{
		solve();
	}
	static void solve(){
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		int n = in.nextInt(), cnt = 0;
		int a[]=new int[30], b[] = new int[1111];
		String s = in.next();
		int z = s.length();
		for(int i = 0; i<28; i++)
			a[i] = 0;
		for(int i = 0; i<z; i++)
			a[(int)(s.charAt(i)-'a')]++;
		if(z % n != 0){
			System.out.println(-1);
			return;
		}
		for(int i=0; i<27; i++)
			if(a[i] % n != 0){
				System.out.println(-1);
				return;				
			}
		int k = n, u = z/n;;
		for(int i = 0; i<z; i++)
			{   boolean ok = true;
				for(int j = 0; j<26 && ok; j++){
					if(a[j] > 0){
						a[j] -= k;
						int t = i;
						while(t<z){
							b[t] = j;
							t= t + u;
						}
						ok = false;
					}
				}
			}
		for(int i = 0; i<z; i++){
//			System.out.print(( b[i] + " "));			
			System.out.print(((char)('a' + b[i])));
		}
	}
}