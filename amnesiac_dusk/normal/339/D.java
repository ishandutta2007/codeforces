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
		int m=in.nextInt();
		int ct=1<<n;
		int a[]=new int[ct<<1];
		for(int i=0; i<ct; i++)
			a[ct+i]=in.nextInt();
		for(int j=n; j>0;) {	
			for(int i=(1<<j)-1; i>=(1<<(j-1)); i--)
				a[i]=a[2*i]|a[2*i+1];
			j--;
			if(j>0)
				for(int i=(1<<j)-1; i>=(1<<(j-1)); i--)
					a[i]=a[2*i]^a[2*i+1];
			j--;
		}
		int p;
		boolean odd;
		for(int i=0; i<m; i++)
		{
			p=ct+in.nextInt()-1;
			a[p]=in.nextInt();
			odd=true;
			while(p>0)
			{
				if(odd)
				{	
					a[p/2]=a[(p/2)*2]|a[(p/2)*2+1];
					odd=false;
				}
				else
				{
					a[p/2]=a[(p/2)*2]^a[(p/2)*2+1];
					odd=true;	
				}
				p>>=1;
			}
			System.out.println(a[1]);
		}
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
        public double nextDouble() {
        	return Double.parseDouble(next());
        }
        
    }
}