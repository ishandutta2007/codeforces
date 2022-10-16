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
	static final boolean debug=false;
	static Reader in=new Reader();
	public static void main(String[] args) throws IOException
	{
		int r=ni(),c=ni();
		String a[]=new String[r+2];
		a[0]=pr(".", c+2);
		for(int i=1; i<=r; i++)
			a[i]='.'+ns()+'.';
		a[r+1]=pr(".", c+2);
		boolean boolor=false;
		for(int i=1; i<=r; i++)
		{
			for(int j=1; j<=c; j++)
			{
				if(a[i].charAt(j)=='W'&&a[i-1].charAt(j)=='S')
				{
					boolor=true;
				}
				if(a[i].charAt(j)=='W'&&a[i].charAt(j-1)=='S')
				{

					boolor=true;
				}
				if(a[i].charAt(j)=='W'&&a[i+1].charAt(j)=='S')
				{

					boolor=true;
				}
				if(a[i].charAt(j)=='W'&&a[i].charAt(j+1)=='S')
				{

					boolor=true;
				}
			}
		}
		if(boolor)
		{
			pr("No");
		}
		else
		{
			pr("Yes");
			for(int i=1; i<=r; i++)
			{
				for(int j=1; j<=c; j++)
				{
					if(a[i].charAt(j)=='.')
						p('D');
					else
						p(a[i].charAt(j));
				}
				pr();
			}
		}
	
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
	static void pd(){if(debug)ans.append("hola");}
	static void pd(Object a){if(debug)ans.append(a+"\n");}
	static void pr(Object a){ans.append(a+"\n");}
	static void pr(){ans.append("\n");}
	static void p(Object a){ans.append(a);}
	static int ni(){return in.nextInt();}
	static long nl(){return in.nextLong();}
	static String ns(){return in.next();}
	static double nd(){return in.nextDouble();}
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