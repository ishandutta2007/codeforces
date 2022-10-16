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
		long n=in.nextLong();
		int k=in.nextInt();
		long a[]=new long[k];
		long tr=0,an1=1,an2=0;
		for(int i=0; i<k; i++)
		{
			a[i]=in.nextLong();
			if((n/a[i])*a[i]>tr)
			{
				tr=Math.max(tr, (n/a[i])*a[i]);
				an1=i+1;
				an2=n/a[i];
			}
		}
		System.out.println(an1+" "+an2);
		
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