import java.io.*;
import java.math.*;
import java.util.*;
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
 
    public static void main(String[] args)
    {
        FastReader in=new FastReader();
        int n=in.nextInt(),max=1;
        for(int i=1; i<=n; i++)
        	if(n%i==0)
        		if(beache(i))
          			max=i;
        System.out.println(max);
    }
    static boolean beache(int n)
    {
    	int k=1;
        while(n%2==0)
        {
        	k++;
        	n/=2;
        }
        if((Math.pow(2, k)-1)==n)
        	return true;
        else
        	return false;
    }
}