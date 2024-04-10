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
	public static void main(String[] args) throws IOException
	{
		int n=ni();
		int a[]=nia(n);
		int b[]=new int[n];
		boolean sieve[]=new boolean[10000001];
		int k=0;
		sieve[1]=true;
		int temp=a[0];
		for(int j=2; j*j<=temp; j++)
		{
			if(!sieve[j]&&temp%j==0)
				for(int i=j; i<=10000000; i+=j)
					sieve[i]=true;
			while(temp%j==0)
				temp/=j;
		}
		if(!sieve[temp])
			for(int i=temp; i<10000000; i+=temp)
				sieve[i]=true;
		k=2;
		b[0]=a[0];
		boolean fallen=false;
		int simplecheck=2;
		for(int i=1; i<n; i++)
		{
			if(!fallen)
				k=Math.max(simplecheck, a[i]);
			while(true)
			{
				if(!sieve[k])
				{	
					b[i]=k;
					if(!fallen&&b[i]>a[i])
					{
						fallen=true;
						k=2;
					}
					break;
				}
				k++;
			}
			int te=b[i];
			for(int l=2; l*l<=te; l++)
			{
				if(te%l==0)
				{	
					if(!sieve[l])
					{
						for(int j=l; j<=10000000; j+=l)
						{
							sieve[j]=true;
						}
					}
				}
				while(te%l==0)
					te/=l;
			}
			if(!sieve[te])
				for(int j=te; j<=10000000; j+=te)
				{
					sieve[j]=true;
				}
			while(true)
			{
				if(!sieve[simplecheck])
					break;
				simplecheck++;
			}
		}
		for(int i=0; i<n; i++)
			p(b[i]+" ");
		System.out.println(ans);
	}
	static final int mod=1000000007;
	static final double eps=1e-8;
	static final long inf=100000000000000000L;
	static final boolean debug=false;
	static Reader in=new Reader();
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
	static Random rn=new Random();
	static void pd(){if(debug)ans.append("hola");}
	static void pd(Object a){if(debug)ans.append(a+"\n");}
	static void pr(Object a){ans.append(a+"\n");}
	static void pr(){ans.append("\n");}
	static void p(Object a){ans.append(a);}
	static void sop(Object a){System.out.println(a);}
	static int ni(){return in.nextInt();}
	static int[] nia(int n){int a[]=new int[n];for(int i=0; i<n; i++)a[i]=ni();return a;}
	static long[] nla(int n){long a[]=new long[n];for(int i=0; i<n; i++)a[i]=nl();return a;}
	static node[] graph(int n) {
		node[] ho=new node[n];
		for(int i=0; i<n; i++)
			ho[i]=new node();
		return ho;
	}
	static String[] nsa(int n){String a[]=new String[n];for(int i=0; i<n; i++)a[i]=ns();return a;}
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
class node
{
	List<Integer> adj=new ArrayList<Integer>();
}