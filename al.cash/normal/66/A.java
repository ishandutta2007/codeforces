import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		BigInteger a;
		a = in.nextBigInteger();
		if(a.compareTo(BigInteger.valueOf(9223372036854775807L))>0
				|| a.compareTo(BigInteger.valueOf(-9223372036854775808L))<0)
			out.println("BigInteger");
		else if(a.compareTo(BigInteger.valueOf(2147483647L))>0
				|| a.compareTo(BigInteger.valueOf(-2147483648L))<0)
			out.println("long");
		else if(a.compareTo(BigInteger.valueOf(32767L))>0
				|| a.compareTo(BigInteger.valueOf(-32768L))<0)
			out.println("int");
		else if(a.compareTo(BigInteger.valueOf(127L))>0
				|| a.compareTo(BigInteger.valueOf(-128L))<0)
			out.println("short");
		else out.println("byte");
		out.flush();
	}
}