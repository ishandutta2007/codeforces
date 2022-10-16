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
	static final int mod=1000000007;
	static final double eps=1e-8;
	static final long inf=100000000000000000L;
	static final boolean debug=true;
	static Reader in=new Reader();
	public static void main(String[] args) throws IOException
	{
		int a=ni(),b=ni(),k=ni(),t=ni();
		int dp[][]=new int[2][4*k*t+1];
		dp[0][2*t*k]=1;
		for(int i=1; i<=2*t; i++)
		{
			for(int j=0; j<k; j++)
			{
				dp[1][0]=(dp[1][0]+dp[0][j])%mod;
				dp[1][j+k+1]=(dp[1][j+k+1]-dp[0][j])%mod;
			}
			for(int j=k; j<4*k*t-k; j++)
			{
				dp[1][j-k]=(dp[1][j-k]+dp[0][j])%mod;
				dp[1][j+k+1]=(dp[1][j+k+1]-dp[0][j])%mod;
			}
			for(int j=4*k*t-k; j<=4*k*t; j++)
				dp[1][j-k]=(dp[1][j-k]+dp[0][j])%mod;
			for(int j=1; j<=4*k*t; j++)
				dp[1][j]=(dp[1][j-1]+dp[1][j])%mod;
			dp[0]=dp[1];
			dp[1]=new int[4*k*t+1];
		}
		long an=0;
		for(int i=b-a+1+2*t*k; i<=4*k*t; i++)
			an=(an+dp[0][i])%mod;
		pr((an+mod)%mod);
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