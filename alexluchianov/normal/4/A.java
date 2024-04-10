import java.util.*;
 
 
public class test {
 
    public static void main(String[] args)  {
        Scanner in = new Scanner(System.in) ;
        int n = in.nextInt() ;
        if(2 < n && n % 2 == 0)
          System.out.println("YES");
		else
		  System.out.println("NO");
        in.close();
	}
}