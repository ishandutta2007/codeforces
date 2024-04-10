
import java.util.*;

public class Main {
    public static void main(String[] args) {
    	Scanner in=new Scanner(System.in);  
    	String a=in.next(),b=in.next();
    	String ans="";
    	for(int i=1; i<a.length(); i++)
    	{
    		if(a.charAt(i)>=b.charAt(0))
    		{
    			ans=a.substring(0, i)+b.charAt(0);
    			break;
    		}
    	}
    	if(ans.equals(""))
    		ans=a+b.charAt(0);
    	System.out.println(ans);
    }
}