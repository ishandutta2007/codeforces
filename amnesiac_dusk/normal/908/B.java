
import java.util.*;

public class Main {
    public static void main(String[] args) {
    	Scanner in=new Scanner(System.in);  
    	int n=in.nextInt(),m=in.nextInt();
    	char[][] a=new char[n][m];
    	String te;
    	int sx=0,sy=0,ex=0,ey=0;
    	for(int i=0; i<n; i++)
    	{
    		te=in.next();
    		for(int j=0; j<m; j++)
    		{
    			a[i][j]=te.charAt(j);
    			if(a[i][j]=='S')
    			{
    				sx=j;
    				sy=i;
    			}
    			else if(a[i][j]=='E')
    			{
    				ex=j;
    				ey=i;
    			}
    		}
    	}
    	te=in.next();
    	/*
    	 * 0123
    	 UDRL
    	 */
    	int cx=sx,cy=sy;
    //	System.out.println(sx+" "+sy);
    	int ct=0;
    	int te1;
    	for(int j=0; j<256; j++)
    	{
    		sx=cx;
    		sy=cy;
    		if((j%4==(j>>2)%4)||(j%4==(j>>4)%4)||(j%4==(j>>6)%4)||((j>>2)%4==(j>>4)%4)||((j>>2)%4==(j>>6)%4)||((j>>4)%4==(j>>6)%4))
    		{
    			continue;
    		}
    		for(int i=0; i<te.length(); i++)
    		{
    			te1=Integer.parseInt(te.charAt(i)+"");
    			if((j>>(te1*2))%4==0)
    			{
     				sy++;
    			}
    			if((j>>(te1*2))%4==1)
    			{
    				sy--;
    			}
    			if((j>>(te1*2))%4==2)
    			{
    				sx++;
    			}
    			if((j>>(te1*2))%4==3)
    			{
    				sx--;    				
    			}
    			if(sy<0||sy>=n||sx<0||sx>=m)
    				break;
    			if(a[sy][sx]=='#')
    				break;
    			if(a[sy][sx]=='E')
    			{
    				ct++;
    				break;
    			}
    		}
    	}
    	System.out.println(ct);
    }    
}