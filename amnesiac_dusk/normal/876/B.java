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
    	int k=in.nextInt();
    	int m=in.nextInt();
    	int no[]=new int[n];
    	int di[]=new int[m];
    	for(int i=0; i<n; i++)
    	{
    		no[i]=in.nextInt();
    		di[no[i]%m]++;
    	}
    	int val=-1;
    	for(int i=0; i<m; i++)
    	{
    		if(di[i]>=k)
    			{val=i; break;}
    	}
    	if(val!=-1)
    	{	System.out.println("Yes");
    	for(int i=0; i<n&&k>0; i++)
    	{
    		if(no[i]%m==val)
    		{
    			System.out.println(no[i]);
    			k--;
    		}
    	}}
    	else
    		System.out.println("No");
    }
}