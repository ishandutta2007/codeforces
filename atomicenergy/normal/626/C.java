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
        int n = in.nextInt();
        int m = in.nextInt();
        int j=Math.max(2*n, 3*m);
        while(true){
        
            int k = Math.max(j/2-n,0)+Math.max(j/3-m,0);
            int l = j/6;
            if(k>=l){
                System.out.println(j);
                return;
            }
            j+=(l-k);
        }
    }
    
}