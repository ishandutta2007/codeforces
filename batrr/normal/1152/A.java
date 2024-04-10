import java.util.Scanner;

public class Main {
    private  static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int n = sc.nextInt(), m = sc.nextInt();
        int []a = new int[n];
        int []b = new int[m];
        for(int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        for(int i = 0; i < m; i++)
            b[i] = sc.nextInt();
        int []aa = new int[]{0 ,0};
        int []bb = new int[]{0 ,0};
        for(int i = 0; i < n; i++)
            aa[a[i] & 1]++;
        for(int i = 0; i < m; i++)
            bb[b[i] & 1]++;
        System.out.print(Math.min(aa[0], bb[1]) + Math.min(aa[1], bb[0]));
    }

}