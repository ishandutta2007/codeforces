import java.io.*;
import java.util.*;
/*
 * 	Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid to fall...
 */
public class Main
{
	static final long mod=1000000007;
	static final double eps=1e-8;
	static Reader in;
	static int max(int a, int b, int c,int d,int e,int f)
	{
		int ho=a;
		ho=Math.max(ho, b);
		ho=Math.max(ho, c);
		ho=Math.max(ho, d);
		ho=Math.max(ho, e);
		ho=Math.max(ho, f);
		return ho;
	}
	static int min(int a, int b, int c,int d,int e, int f)
	{
		int ho=a;
		ho=Math.min(ho, b);
		ho=Math.min(ho, c);
		ho=Math.min(ho, d);
		ho=Math.min(ho, e);
		ho=Math.min(ho, f);
		return ho;
	}
	public static void main(String[] args) throws IOException
	{
		in=new Reader();
		int n=ni();
		int a[]=new int[n];
		for(int i=0; i<n; i++)
			a[i]=ni();
		StringBuilder b=new StringBuilder(ns());
		int lmi=-1000000000,lma=1000000000,rma=1000000000,rmi=-1000000000;
		boolean bool=true;
		for(int i=4; i<n; i++)
		{
			for(int j=i-4; j<i; j++)
			{
				if(b.charAt(j)==b.charAt(i-1))
					bool=true;
				else
				{
					bool=false;
					break;
				}
			}
			if(bool)
			{
				if(b.charAt(i)=='1')
				{
					if(b.charAt(i)==b.charAt(i-1))
					{
						rmi=Math.max(rmi, min(a[i],a[i],a[i-1],a[i-2],a[i-3],a[i-4]));
					}
					else
					{
						lmi=Math.max(lmi, 1+max(a[i],a[i],a[i-1],a[i-2],a[i-3],a[i-4]));
					}
				}
				else
				{
					if(b.charAt(i)==b.charAt(i-1))
					{
						lma=Math.min(lma, max(a[i],a[i],a[i-1],a[i-2],a[i-3],a[i-4]));
					}
					else
					{
						rma=Math.min(rma, -1+min(a[i],a[i],a[i-1],a[i-2],a[i-3],a[i-4]));
					}	
				}
			}
		}
		pr(lmi+" "+rma);
		System.out.println(ans);
	}
	static StringBuilder ans=new StringBuilder();
	static long powm(long a, long b, long m)
	{
		long an=1;
		long c=a;
		while(b>0)
		{
			if(b%2==1)
				an=(an*c)%m;
			c=(c*c)%m;
			b>>=1;
		}
		return an;
	}
	static void pr(Object a)
	{
		ans.append(a+"\n");
	}
	static void p(Object a)
	{
		ans.append(a);
	}
	static int ni()
	{
		return in.nextInt();
	}
	static long nl()
	{
		return in.nextLong();
	}
	static String ns()
	{
		return in.next();
	}
	static double nd()
	{
		return in.nextDouble();
	}
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