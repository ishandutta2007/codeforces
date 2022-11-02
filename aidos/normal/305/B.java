import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	static long a[];
	public static void main (String []args) throws IOException, ArrayIndexOutOfBoundsException{
		Scanner in = new Scanner (System.in);
		PrintWriter pw = new PrintWriter(System.out);
		long p = in.nextLong(), q = in.nextLong(),n = in.nextLong();
		a = new long[110];
		for(int i = 0; i<n; i++){
			a[i] = in.nextLong();
		}
		Pair t = f((int)n, new Pair(BigInteger.ZERO, BigInteger.ONE));
		BigInteger b1 = t.a, b2 = t.b, b3 = BigInteger.valueOf(p), b4 = BigInteger.valueOf(q), bx = b1.multiply(b4), bt = b2.multiply(b3);
		if(bx.compareTo(bt)==0){
            pw.println("YES");
        }
		else pw.println("NO");
		pw.close();
    }
	public static Pair f(int n, Pair x){
		if(n==0) return new Pair(x.b, x.a);
		BigInteger t = BigInteger.valueOf(a[n-1]), u = x.b, z = (u.multiply(t)).add(x.a);
		return f(n-1, new Pair(u, z));
	}
}
class Pair{
	public BigInteger a, b;
	Pair(BigInteger c, BigInteger d){
		a = c; 
		b = d;
	}
}