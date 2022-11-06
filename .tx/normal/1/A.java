import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long m = sc.nextLong();
        long a = sc.nextLong();
        System.out.println((n + a - 1) / a * ((m + a - 1) / a));
    }

}