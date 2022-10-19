import java.util.Scanner;

/**
 *
 * @author Zach
 */
public class Asdf {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int x, y;
        int c=0;
        String s = in.next();
        for(int i=0; i<a; i++){
            for(int j=i+1; j<=a; j++){
                x=0;
                y=0;
                for(int z=i; z<j; z++){
                    if(s.charAt(z)=='U'){
                        x++;
                    }
                    if(s.charAt(z)=='D'){
                        x--;
                    }
                    if(s.charAt(z)=='L'){
                        y++;
                    }
                    if(s.charAt(z)=='R'){
                        y--;
                    }
                }
                if(x==0&&y==0){
                    c++;
                }
            }
        }
        System.out.println(c);
    }
    
}