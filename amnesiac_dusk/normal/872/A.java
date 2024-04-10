import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Main
{
	static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
    public static void main(String[] args) throws IOException
    {
    	FastReader in=new FastReader();
    	int n=in.nextInt();
    	int m=in.nextInt();
    	int temp=10, temp2 = 0, temp3 = 0;
    	boolean[] l1= new boolean[10];
    	boolean[] l2= new boolean[10];
    	for(int i=0; i<n; i++)
    		l1[in.nextInt()]=true;
    	for(int j=0; j<m; j++)
    		l2[in.nextInt()]=true;
    	ou: for(int i=0; i<10; i++)
    	{
    		if(l1[i]&&l2[i])
    			{temp=i; break ou;}
    	}
    	if(temp==10)
    	{
    		for(int i=9; i>=0; i--)
    		{
    			if(l1[i])
    				temp2=i;
    			if(l2[i])
    				temp3=i;
    		}
    		if(temp2>temp3)
    			System.out.println(temp3+""+temp2);
    		else
    			System.out.println(temp2+""+temp3);
    	}
    	else
    		System.out.println(temp);
    }	
}