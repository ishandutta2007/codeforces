import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        BigInteger l = in.nextBigInteger();
        BigInteger r = in.nextBigInteger();
        BigInteger k = in.nextBigInteger();
        boolean any = false;
        for (BigInteger i = BigInteger.ONE; i.compareTo(r) <= 0; i = i.multiply(k)) {
            if (i.compareTo(l) >= 0) {
                out.print(i);
                out.print(" ");
                any = true;
            }
        }
        if (!any) {
            out.print(-1);
        }
        out.close();
    }
}