import java.util.*;

import static java.lang.Math.*;

public class codeforces3 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        int o[]=new int[3];
        for(int i=0;i<3;i++)
        {
            o[i]=sc.nextInt();
        }

        Arrays.sort(o);
        System.out.print(o[2]-o[0]);

    }

}