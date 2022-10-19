import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;
public class JavaApplication43 {

    






    

    
    public static  void  main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int s = in.nextInt();
        
        ArrayList<Integer> x = new ArrayList<>();
        int total = 0;
        for(int i=0; i<n; i++){
            int y = in.nextInt();
            
            if(i==s-1){
                if(y!=0){
                    total++;
                }
            }else{
                if(y==0){
                    y=100000000;
                }
                x.add(y);
            }
        }
        if(n==1){
            System.out.println(total);
            return;
        }
        Collections.sort(x);
        int gaps = 0;
        int seen = n-1;
        int curr = 0;
        int currseen;
        int min = 100000000;
        for(int i=1; i<n; i++){
            currseen = 0;
            while(curr<n-1&&x.get(curr)==i){
                curr++;
                currseen++;
            }
            if(currseen==0){
                gaps++;
            }
            seen-=currseen;
            if(seen<min&&gaps<min){
                min = gaps;
                if(seen>gaps){
                    min = seen;
                }
                
            }
            //System.out.println(i + " " + gaps + " " + seen);
        }
        System.out.println(min+total);
    }
       
        
}