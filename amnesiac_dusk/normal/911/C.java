
import java.util.*;

public class Main {
    public static void main(String[] args) {
    	Scanner in=new Scanner(System.in);  
    	int a[]=new int[3];
    	a[0]=in.nextInt();
    	a[1]=in.nextInt();
    	a[2]=in.nextInt();
    	Arrays.sort(a);
    	if(a[0]==1)
    		System.out.println("YES");
    	else if(a[0]==2&&a[1]==2)
    		System.out.println("YES");
    	else if(a[0]==2&&a[1]==4&&a[2]==4)
    		System.out.println("YES");
    	else if(a[0]==3&&a[1]==3&&a[2]==3)
    		System.out.println("YES");
    	else
    		System.out.println("NO");
    }
}