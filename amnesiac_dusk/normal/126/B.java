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
		String s=ns();
		int n=s.length();
		int pref[]=new int[n];
		for(int i=1,j=0; i<s.length();)
		{
			if(s.charAt(i)==s.charAt(j))
			{
				j++;
				pref[i]=j;
				i++;
			}
			else if(j!=0)
				j=pref[j-1];
			else
				i++;
		}
		int maxsublength=0;
		for(int i=1,j=0; i<n-1;)
		{
			if(s.charAt(i)==s.charAt(j))
			{
				j++;
				i++;
			}
			else if(j!=0)
				j=pref[j-1];
			else
				i++;
			maxsublength=Math.max(maxsublength, j);
		}
		int an=0;
		long hashes[][]=new long[2][2];
		long seeds[]= {231234229,349576911};
		for(int i=0; i<maxsublength; i++)
		{
			for(int j=0; j<1; j++)
			{
				hashes[j][0]=((hashes[j][0]+s.charAt(i))*seeds[j])%modu;
				hashes[j][1]=((hashes[j][1]+s.charAt(n-i-1)*powm(seeds[j],i+1,modu)))%modu;
			}
			boolean pos=true;
			for(int j=0; j<1; j++)
			{
				if(hashes[j][0]!=hashes[j][1])
					pos=false;
			}
			if(pos)
				an=i+1;
		}
		if(an!=0)
			pr(s.substring(n-an));
		else
			pr("Just a legend");
		System.out.println(ans);
	}
	static final int mod=1000000007;
	static long modu=mod;
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
	static int[] ria(int n){int a[]=new int[n];for(int i=0; i<n; i++){a[i]=rn.nextInt(100);p(a[i]+" ");}pr();return a;}
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
	Set<Integer> adj=new HashSet<Integer>();
}