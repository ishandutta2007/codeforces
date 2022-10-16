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
        String s=in.next();
        int l=s.length();
        String a="";
        for(int i=0; i<l; i++)
        {
        	if(s.charAt(i)=='Q')
        		a+='Q';
        	if(s.charAt(i)=='A')
        		a+='A';
        }
        l=a.length();
        long ct=0;
        long a2=0;
        int a1=0;
        int b[][]=new int[l][3];
        for(int i=0; i<l ;i++)
        {
        	if(a.charAt(i)=='Q')
        	{
        		a1++;
        		ct+=a2;
        	}
        	if(a.charAt(i)=='A')
        	{
        		b[i][1]+=a1;
        		a2+=b[i][1];
        	}
        	
        }
        System.out.println(ct);
    }
}