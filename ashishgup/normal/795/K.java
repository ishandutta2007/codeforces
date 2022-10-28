// Working program with FastReader
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class TestClass {
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
    
    public static void main(String args[] ) throws Exception 
    {
        FastReader s=new FastReader();
        int n=s.nextInt();
        char[] str=new char[100001];
        int len=n;
        String str1=s.nextLine();
        for(int i=0;i<n;i++)
        {
            char temp=str1.charAt(i);
            str[i]=temp;
        }
        for (int i = 0; i < len; i++) 
        {
            char ch=str[i];
            if(ch!='a'&&ch!='e'&&ch!='i'&&ch!='o'&&ch!='u'&&ch!='y')
            {
                System.out.print(ch);
                continue;
            }
            if(i+2<len&&str[i+1]==ch&&str[i+2]==ch)
            {
                System.out.print(ch);
                while(i+1<n&&str[i+1]==ch)
                {
                    i++;
                }
            }
            else if(i+1<len&&str[i+1]==ch)
            {
                if(ch=='e'||ch=='o')
                {
                    System.out.print(ch);
                    System.out.print(ch);
                    i++;
                }
                else
                {
                    System.out.print(ch);
                    i++;
                }
            }
            else
            {
                System.out.print(ch);
            }
        }
    }
}