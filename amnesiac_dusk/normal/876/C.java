import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Main
{	static class FastReader
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
    	FastReader in= new FastReader();
    	int n=in.nextInt(),temp,te, ct=0;
       	for(int i=1; i<=200; i++)
    	{
    		te=0;
    		temp=n-i;
    		while(temp!=0)
    		{
    			te+=temp%10;
    			temp/=10;
    		}
    		if(te==i)
    		{
    			ct++;
    		}
    	}
    	System.out.println(ct);
    	for(int i=200; i>=0; i--)
    	{
    		te=0;
    		temp=n-i;
    		while(temp!=0)
    		{
    			te+=temp%10;
    			temp/=10;
    		}
    		if(te==i)
    		{
    			System.out.println(n-i);    	
    		}
    	}
    }
    
}