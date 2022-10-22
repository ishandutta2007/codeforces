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
        int c=0;
        String s = in.next();
        int r=0;
        int g=0;
        int b=0;
        for(int i=0; i<a; i++){
            if(s.charAt(i)=='R'){
                r++;
            }
            if(s.charAt(i)=='G'){
                g++;
            }
            if(s.charAt(i)=='B'){
                b++;
            }
        }
        if(r*g*b>0||(r>1&&g>1)||(r>1&&b>1)||(b>1&&g>1)){
            System.out.println("BGR");
            return;
        }
       
            if(b==g){
                System.out.println("R");
                return;
            }
            if(b==r){
                System.out.println("G");
                return;
            }
            if(r==g){
                System.out.println("B");
                return;
            }
        if(r>1){
            System.out.println("BG");
                return;
        }
        if(g>1){
            System.out.println("BR");
                return;
        }
        if(b>1){
            System.out.println("GR");
                return;
        }
    }
    
}