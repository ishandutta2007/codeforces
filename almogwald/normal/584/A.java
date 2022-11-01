import java.util.Scanner;
import java.util.Arrays;
public class e {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int t = in.nextInt();
		in.close();
        if(t!=10){
	        for(int i=1;i<=n;i++){
			    System.out.print(t);
		    }
        } else {
        	if(n>1){
        		System.out.print(1);
        		for(int i=1;i<n;i++){
    			    System.out.print(0);
    		    }
        	} else {
        		System.out.print(-1);
        	}
        }
		
		

		
	}
}