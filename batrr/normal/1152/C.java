import java.util.Scanner;
import java.util.Vector;

public class Main {
    private static Scanner sc = new Scanner(System.in);
    public static int a, b, k;
    public static void main(String[] args) {
        a = sc.nextInt();
        b = sc.nextInt();
        k = 0;
        int c = Math.abs(a - b);
        for(int i = 1; i * i <= c; i++)
            if(c % i == 0){
                check(i);
                check(c / i);
            }
        System.out.print(k);
    }
    public static void check(int g){
        int cur_k = g - a % g;
        if(get(a, b, cur_k) < get(a, b, k))
                k = cur_k;
    }
    public static long get(long a, long b, long k){
        return (a + k) * (b + k) / gcd(a + k, b + k);
    }
    public static  long gcd(long a, long b){
        if(a == 0)
            return b;
        return gcd(b % a, a);
    }

}