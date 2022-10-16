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
    	int n=in.nextInt();
    	int a=in.nextInt();
    	int b=in.nextInt();
    	int c=in.nextInt();
    	int min=Math.min(Math.min(a,b), c);
    	int ans=0;
    	ans=(a<b)?a:b;
    	if(n>2)
    		{n-=2;
    	
    	
   		ans+=n*min;
   	   	System.out.println(ans);}
    	else if(n==2)
    	{
    		System.out.println(ans);
    	}
    	else if(n==1)
    		System.out.println(0);
   	}
    
}