
import java.util.*;

public class Main {
    public static void main(String[] args) {
    	Scanner in=new Scanner(System.in);  
    	int n=in.nextInt()+1;
    	int a[]=new int[n];
    	for(int i=0; i<n; i++)
    	{
    		for(int j=1; i+j<n; j++)
    		{
    			a[i]++;
    			a[i+j]--;
    		}
    	}
    	for(int i=1; i<n; i++)
    		a[i]+=a[i-1];
    	int ans=0;
    	for(int i=0; i<n; i++)
    		ans=Math.max(a[i], ans);
    	System.out.println(ans);
    }
}