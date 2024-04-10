
import java.util.*;

public class Main {
    public static void main(String[] args) {
    	Scanner in=new Scanner(System.in);  
    	int n=in.nextInt();
    	int a[]=new int[n];
    	int min=Integer.MAX_VALUE;
    	for(int i=0; i<n; i++)
    	{
    		a[i]=in.nextInt();
    		min=Math.min(min, a[i]);
    	}
    	int li=-1,len=n;
    	for(int i=0; i<n; i++)
    	{
    		if(a[i]==min&&li!=-1)
    		{
    			len=Math.min(len, i-li);
    			li=i;
    		}
    		else if(a[i]==min)
    		{
    			li=i;
    		}
    	}
    	System.out.println(len);
    }
}