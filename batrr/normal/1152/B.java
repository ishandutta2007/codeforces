import java.util.Scanner;
import java.util.Vector;

public class Main {
    private static Scanner sc = new Scanner(System.in);
    private static int LOG = 20;
    public static void main(String[] args) {
        int n = 0;
        Vector ans = new Vector();
        int x = sc.nextInt();
        for(int i = LOG ; i > 0; i--){
            if(((x >> (i - 1)) & 1) == 1)
                continue;
            n++;
            ans.add(i);
            x ^= (1 << i) - 1;
            boolean good = true;
            for(int j = 0; j < LOG; j++)
                if(((x >> j) & 1) == 0)
                    good = false;
            if(good)
                break;
            n++;
            x++;
        }
        System.out.println(n);
        for(int i = 0; i < ans.size(); i++)
            System.out.print(ans.get(i) + " ");
    }
}