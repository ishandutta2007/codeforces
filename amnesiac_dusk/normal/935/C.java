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
	static final double eps=1e-6;
	static Reader in;
	static double dist(double x1,double x2,double y1,double y2)
	{
		return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	}
	public static void main(String[] args) throws IOException
	{
		in=new Reader();
		double r=ni(),x1=ni(),y1=ni(),x2=ni(),y2=ni();
		if(dist(x1,x2,y1,y2)>r)
		{
			pr(x1+" "+y1+" "+r);
		}
		else if(dist(x1,x2,y1,y2)<eps)
		{
			pr((x1+r/2)+" "+y1+" "+r/2);
		}
		else
		{
			double R=dist(x1,x2,y1,y2);
			double anx=x2+((x1-x2)/(2*R))*(R+r);
			double any=y2+((y1-y2)/(2*R))*(R+r);
			pr(anx+" "+any+" "+(R+r)/2);
		}
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