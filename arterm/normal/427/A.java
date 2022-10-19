import java.util.Scanner;

/**
 * Created by Samsung900 on 02.05.2014.
 */
public class Main {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int free = 0;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int event = sc.nextInt();
            if (event >= 0)
                free += event;
            else if (free > 0)
                --free;
            else
                ++ans;

        }

        System.out.println(ans);

    }
}