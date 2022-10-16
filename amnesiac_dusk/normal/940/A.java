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
	public static void main(String[] args) throws IOException
	{
		in=new Reader();
		int n=ni(),d=ni();
		int a[]=new int[n];
		for(int i=0; i<n; i++)
			a[i]=ni();
		Arrays.sort(a);
		int m=n;
		for(int i=0; i<n; i++)
		{
			for(int j=n-1; j>=0; j--)
			{
				if(a[j]-a[i]<=d)
				{
					m=Math.min(m,n-j-1+i);
				}
			}
		}
		pr(m);
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