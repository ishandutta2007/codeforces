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
		int a[]=new int[n];
		long prea[]=new long[n];
		a[0]=in.nextInt();
		prea[0]=a[0];
		for(int i=1; i<n; i++)
		{
			a[i]=in.nextInt();
			prea[i]=prea[i-1]+a[i];
		}
		int s=in.nextInt();
		int f=in.nextInt();
		int dif=f-s;
		long maxp=0;
		maxp=prea[dif-1];
		int ti=s;
		int ti1;
		for(int i=0; i<n-dif; i++)
		{
			if(maxp<prea[i+dif]-prea[i])
			{
				maxp=prea[i+dif]-prea[i];
				ti=((s-i-1)%n+n-1)%n+1;
			//	System.out.println(maxp+" "+i+" "+prea[i+dif]+" "+prea[i]);
			}
			else if(maxp==prea[i+dif]-prea[i])
			{
				ti1=((s-i-1)%n+n-1)%n+1;
				ti=Math.min(ti, ti1);
			}
		}
		for(int i=n-dif; i<n; i++)
		{
			if(maxp<prea[n-1]+prea[(i+dif)%n]-prea[i])
			{
				maxp=prea[n-1]+prea[(i+dif)%n]-prea[i];
				ti=((s-i-1)%n+n-1)%n+1;
			//	System.out.println(maxp+" "+i+" "+prea[i+dif]+" "+prea[i]);
				
			}
			else if(maxp==prea[n-1]+prea[(i+dif)%n]-prea[i])
			{
				ti1=((s-i-1)%n+n-1)%n+1;
				ti=Math.min(ti, ti1);
			}
		}
		System.out.println(ti);
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