import java.lang.*;
import java.io.*;
import java.util.*;

public class A {
    static Scanner in;
    static PrintWriter out;
    public static void main(String[] args) throws IOException {
        in = new Scanner(System.in);
        //out = new PrintWriter("out");
        int n, ans = 0;
        n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int sum = 0, x;
            for (int j = 0; j < 3; j++) {
                x = in.nextInt();
                sum += x;
            }
            if (sum >= 2)
                ans++;
        }
        System.out.print(ans);
        //out.close();
    }
}