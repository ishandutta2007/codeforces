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
	static Reader in;
	public static void main(String[] args) throws IOException
	{
		in=new Reader();
		int n=ni();
		String s=ns();
		int x1,y1,x=0,y=0;
		int ct=0;
		for(int i=0; i<n-1; i++)
		{
			x1=x;
			y1=y;
			if(s.charAt(i)=='U')
				y++;
			else
				x++;
			if(x==y)
				if(((x1==x-1)&&s.charAt(i+1)=='R')||((y1==y-1)&&s.charAt(i+1)=='U'))
					ct++;
		}
		pr(ct);
		System.out.println(ans);
	}
	static StringBuilder ans=new StringBuilder();
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