import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {

        for (int i = 0; i < 5 ; i++) {
            for (int j = 0; j < 5 ; j++)
            {
                int a=sc.nextInt();
                if(a==1)
                {
                    int x=Math.abs(2-i),y=Math.abs(2-j);
                    System.out.println(x+y);
                    return;
                }
            }
        }


    }

}