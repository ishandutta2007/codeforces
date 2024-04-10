import java.io.*;
import java.util.*;
/*
 * 	Author: rahuldugar
 * 	Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid to fall...
 */
public class Main
{
	static final int mod=1000000007;
	public static void main(String[] args) throws IOException
	{
		Reader in=new Reader();
		int n=in.nextInt();
		int a=in.nextInt(), b=in.nextInt();
		int ho[]=new int[n];
		int i=0;
		while(n>0)
		{
			try {
			if(n%b==0)
			{
				ho[i]=b+i;
				i++;
				for(int j=1;j<b; j++)
				{
					ho[i]=i;
					i++;
				}
				n-=b;
			}
			else
			{
				n-=a;
				ho[i]=a+i;
				i++;
				for(int j=1; j<a; j++)
				{
					ho[i]=i;
					i++;
				}
			}
			}
			catch(Exception e)
			{
				n=-1;
			}
	//		System.out.println(n);
		}
		if(n==0)
		{
			for(int k=0; k<ho.length; k++)
				ans.append(ho[k]+" ");
			System.out.println(ans);
		}
		else
			System.out.println(-1);
	}
	static StringBuilder ans=new StringBuilder();
	static String pr(String a, long b)
	{
		String c="";
		while(b>0)
		{
			if(b%2==1)
				c=c.concat(a);
			a=a.concat(a);
			b>>=1;
		}
		return c;
	}
	static class Reader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
        	return Long.parseLong(next());
        }
    }
}