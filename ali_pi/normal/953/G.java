import java.util.*;
import static java.lang.Math.*;

public class Main{
	public static void main(String[] argc){
		   Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b,o=0,e=0;
		while(a-- > 0){
		    b = in.nextInt();
		    if(b%2 == 1)o++;
		    else e++;
		}
		int bal = o - min(o,e);
		a = min(o,e) + max(0,bal)/3;
		System.out.println(a);
	}
	
}