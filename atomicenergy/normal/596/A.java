import java.util.*;

/**
 *
 * @author Zach
 */
public class ACM {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int a;
        Scanner in = new Scanner(System.in);
        a=in.nextInt();
        int minx=0;
        int miny=0;
        int maxx=0;
        int maxy=0;
        int[] x = new int[4];
        int[] y = new int[4];
        for(int i=0; i<a; i++){
            x[i]=in.nextInt();
            y[i]=in.nextInt();
            if(i==0){
                minx=x[0];
                miny=y[0];
                maxx=x[0];
                maxy=y[0];
            }
            else{
                if(x[i]<minx){
                    minx=x[i];
                }
                if(x[i]>maxx){
                    maxx=x[i];
                }
                if(y[i]<miny){
                    miny=y[i];
                }
                if(y[i]>maxy){
                    maxy=y[i];
                }
            }
        }
        if(a==1){
            System.out.println(-1);
        }
        if(a>2){
            
            System.out.println((maxx-minx)*(maxy-miny));
        }
        if(a==2&(x[0]-x[1])*(y[0]-y[1])==0){
            System.out.println(-1);
            
        }
        if(a==2&(x[0]-x[1])*(y[0]-y[1])!=0){
            System.out.println((maxx-minx)*(maxy-miny));
            
        }
    }
    
}