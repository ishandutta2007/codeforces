
import java.util.*;

public class Main {
    public static void main(String[] args) {
    	Scanner in=new Scanner(System.in);  
    	int n=in.nextInt();
    	int a[]=new int[n];
    	for(int i=0; i<n; i++)
    		a[i]=in.nextInt();
    	long no=0;
    	for(int i=0; i<n-1; i++)
    	{
    		for(int j=i+1; j<n; j++)
    		{
    			if(a[i]>a[j])
    				no++;
    		}
    	}
   // 	System.out.println(no);
    	no%=2;
    	int m=in.nextInt();
    	int te;
    	String te2="odd",te1="even";
    	for(int i=0; i<m; i++)
    	{
    		te=in.nextInt()-in.nextInt();
    		te=-te+1;
    //		System.out.println(te);
    		if((te*(te-1)/2)%2==0)
    		{
    //			System.out.println("HOLA"+no);
    			if(no==0)
    				System.out.println("even");
    			else
    				System.out.println("odd");
    		}
    		else
    		{
    			no=(no+1)%2;
    			if(no==0)
    				System.out.println("even");
    			else
    				System.out.println("odd");
    		}
    	}
    	
    }
}