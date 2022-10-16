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
    	for(int i=0; i<n; i++)
    	{
    		int a=in.nextInt();
    		if(a%4==0)
    		{
    			System.out.println(a/4);
    		}
    		else if(a%2==0&&a>=4)
    		{
    			System.out.println((a-2)/4);
    		}
    		else if(a%2==1&&a>=13)
    		{
    			if((a-9)%4==0)
    			{
    				System.out.println((a-9)/4+1);
    			}
    			else if((a-9)%2==0)
    			{
    				System.out.println((a-15)/4+2);
    			}
    		}
    		else if(a==9||a==6)
    			System.out.println("1");
    		else
    			System.out.println("-1");
    			
    	}
    	
    }	
}