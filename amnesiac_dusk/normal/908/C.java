
import java.util.*;

public class Main {
    public static void main(String[] args) {
    	Scanner in=new Scanner(System.in);  
    	int n=in.nextInt(),r=in.nextInt();
    	double[] x=new double[n];
    	for(int i=0; i<n; i++)
    		x[i]=in.nextInt();
    	double[] y=new double[n];
    	for(int i=0; i<n; i++)
    	{
    		y[i]=r;
    		for(int j=0; j<i; j++)
    		{
    			
    			if(Math.abs(x[j]-x[i])<=2*r)
    			{
    				y[i]=Math.max(y[i], y[j]+Math.sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j])));
    			}
    		}
    	}
    	for(int i=0; i<n; i++)
    		System.out.print(y[i]+" ");
    }    
}