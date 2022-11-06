import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        String s = in.nextLine();
        s = s.replaceAll(" {2,}", " ").replaceAll(" ,", ",").replaceAll(", ", ",").replaceAll(",", ", ").replaceAll(" \\.\\.\\.", "...").replaceAll("\\.\\.\\. ", "...").replaceAll("\\.\\.\\.", " ...").trim();
        out.println(s);
        out.close();
    }
}