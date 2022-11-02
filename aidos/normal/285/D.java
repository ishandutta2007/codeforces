import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main (String []args) throws IOException{
		Scanner in = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int n = in.nextInt();
		BigInteger b[] = new BigInteger[30];
		b[0] = BigInteger.ONE;
		for(int i=1; i<=n; i++)
			b[i] = b[i-1].multiply(BigInteger.valueOf(i));
		long a[] = { 1, 0, 3, 0, 15, 0, 133, 0, 2025, 0, 37851, 0, 1030367, 0, 36362925, 0}; 
        pw.print(b[n].multiply(BigInteger.valueOf(a[n-1])).mod(BigInteger.valueOf(1000000007)));		
		pw.close();
	}	
}