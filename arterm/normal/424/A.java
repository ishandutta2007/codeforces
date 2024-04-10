
import java.util.Scanner;

/**
 * Created by Samsung900 on 30.04.2014.
 */
public class Main {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        int x = 0;
        for (char ch:s)
            if (ch == 'x')
                ++x;

        x -= n/2;

        System.out.println(Math.abs(x));

        for (int i = 0; i < n; ++i) {
            if (x < 0 && s[i] == 'X') {
                s[i] = 'x';
                ++x;
            }
            if (x > 0 && s[i] == 'x') {
                s[i] = 'X';
                --x;
            }
        }
        System.out.println(s);
    }
}