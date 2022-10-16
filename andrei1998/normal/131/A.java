import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String y;
        
        Scanner in = new Scanner(System.in);
        y = in.nextLine();
        
        char[] x = y.toCharArray();
        
        boolean ok = true;
        for (int i = 1; i < x.length; i++)
            if ('a' <= x[i] && x[i] <= 'z') {
                ok = false;
                break;
            }
            
                
        if (ok) {
            for (int i = 0; i < x.length; i++)
                if ('A' <= x[i] && x[i] <= 'Z')
                    x[i] = Character.toLowerCase(x[i]);
                else
                    x[i] = Character.toUpperCase(x[i]);
        }
        
        System.out.println(x);
        in.close();
    }
}