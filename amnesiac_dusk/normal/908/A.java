
import java.util.*;

public class Main {
    public static void main(String[] args) {
    	Scanner in=new Scanner(System.in);  
    	String a=in.next();
    	int ct=0;
    	for(int i=0; i<a.length(); i++)
    	{
    		if(a.charAt(i)=='a'||a.charAt(i)=='e'||a.charAt(i)=='i'||a.charAt(i)=='o'||a.charAt(i)=='u'||a.charAt(i)=='1'||a.charAt(i)=='3'||a.charAt(i)=='5'||a.charAt(i)=='7'||a.charAt(i)=='9')
    			ct++;
    	}
    	System.out.println(ct);
    }
}