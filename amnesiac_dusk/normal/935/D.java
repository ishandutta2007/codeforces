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
	static long an;
	static final long mod=1000000007;
	static final double eps=1e-8;
	static Reader in;
	static int n;
	static long m;
	static int[] s1,s2;
	static long boolor(int i)
	{
		if(i!=n)
		{
			if(s1[i]==0&&s2[i]==0)
				return (((m-1)*powm(2*m, mod-2, mod))%mod+(boolor(i+1)*powm(m,mod-2,mod))%mod)%mod;
			else if(s1[i]==0)
				return (((m-s2[i])*powm(m, mod-2,mod))%mod+(boolor(i+1)*powm(m,mod-2,mod))%mod)%mod;
			else if(s2[i]==0)
				return (((s1[i]-1)*powm(m,mod-2,mod))%mod+(boolor(i+1)*powm(m,mod-2,mod))%mod)%mod;
			else if(s1[i]>s2[i])
				return 1;
			else if(s1[i]==s2[i])
				return (boolor(i+1))%mod;
		}
		return 0;
	}
	public static void main(String[] args) throws IOException
	{
		in=new Reader();
		n=ni();
		m=ni();
		s1=new int[n];
		s2=new int[n];
		for(int i=0; i<n; i++)
			s1[i]=ni();
		for(int i=0; i<n; i++)
			s2[i]=ni();
		pr(boolor(0));
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