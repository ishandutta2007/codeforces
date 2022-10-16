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
	static final long inf=100000000000000000L;
	static final boolean debug=true;
	static Reader in=new Reader();
	public static void main(String[] args) throws IOException
	{
		int n=ni();
		int a=ni(),b=ni();
		String hol=Integer.toBinaryString(n-1);
		String lol=Integer.toBinaryString(a-1);
		String lol1=Integer.toBinaryString(b-1);
		while(lol.length()!=hol.length())
		{
			lol="0"+lol;
		}
		while(lol1.length()!=hol.length())
		{
			lol1="0"+lol1;
		}
		int te=0;
		for(int i=0; i<lol.length(); i++)
		{
			if(lol.charAt(i)!=lol1.charAt(i))
			{
				te=i;
				break;
			}
		}
		te=lol.length()-te;
		if(te!=lol.length())
			pr(te);
		else
			pr("Final!");
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