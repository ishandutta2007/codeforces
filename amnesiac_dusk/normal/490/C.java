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
	static int num(char a)
	{
		return a-48;
	}
	static final long mod=1000000007;
	static final double eps=1e-8;
	static final boolean debug=true;
	static Reader in=new Reader();
	public static void main(String[] args) throws IOException
	{
		StringBuilder s=new StringBuilder(ns());
		int n=s.length();
		int a=ni(),b=ni();
		long[] bo=new long[n],boo=new long[n];
		bo[0]=num(s.charAt(0))%a;
		for(int i=1; i<n; i++)
			bo[i]=(bo[i-1]*10+num(s.charAt(i)))%a;
		long boolor=10;
		boo[n-1]=num(s.charAt(n-1))%b;
		for(int i=n-2; i>=0; i--)
		{
			boo[i]=(num(s.charAt(i))*boolor+boo[i+1])%b;
			boolor=(boolor*10)%b;
		}
		boolean poss=false;
		int an=0;
		for(int i=0; i<n-1; i++)
		{
			if((boo[i+1]==0)&&(bo[i]==0)&&(num(s.charAt(i+1))!=0))
			{
				an=i+1;
				poss=true;
				break;
			}
		}
		if(poss)
		{
			pr("YES");
			pr(s.substring(0, an));
			pr(s.substring(an));
		}
		else
			pr("NO");
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