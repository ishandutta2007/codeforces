import java.util.*;

public class C {
        public static void main(String[] args) {
                Scanner s = new Scanner(System.in);
                int a = s.nextInt();
                String b = s.next();
                long c = s.nextLong(a);
                if (b.matches("\\d+")) {
                        System.out.println(Long.toString(c, new Integer(b)).toUpperCase());
                } else {
                        String r = "";
                        int[] num = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
                        String[] val = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X",
                                        "IX", "V", "IV", "I" };
                        for (; c > 0;) {
                                for (int i = 0; i < num.length; ++i) {
                                        if (c >= num[i]) {
                                                c -= num[i];
                                                r += val[i];
                                                break;
                                        }
                                }
                        }
                        System.out.println(r);
                }
        }//safaf
}