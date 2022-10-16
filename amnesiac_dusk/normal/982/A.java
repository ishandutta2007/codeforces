import java.io.*;
import java.util.*;
/*
 * 	Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid to fall...
 */
//read the question correctly (is y a vowel? what are the exact constraints?)
//look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
public class Main
{
	public static void main(String[] args)
	{
		int n=ni();
		String s=ns();
		if(n!=1)
		{
		boolean poss=true;
		for(int i=1; i<s.length(); i++)
		{
			if(s.charAt(i)=='1'&&s.charAt(i-1)=='1')
			{
				poss=false;
			}
		}
		if(s.charAt(0)=='0'&&s.charAt(1)=='0')
			poss=false;
		if(s.charAt(n-1)=='0'&&s.charAt(n-2)=='0')
			poss=false;
		for(int i=1; i<s.length()-1; i++)
		{
			if(s.charAt(i)=='0'&&s.charAt(i-1)=='0'&&s.charAt(i+1)=='0')
			{
				poss=false;
			}
		}
		if(poss)
			pr("Yes");
		else
			pr("No");
		}
		else
		{
			if(s.equals("1"))
				pr("Yes");
			else
				pr("No");
		}
		System.out.println(output);
	}

	
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
	static final int mod=1000000007;
	static final double eps=1e-3;
	static final long inf=100000000000000000L;
	static Reader in=new Reader();
	static StringBuilder output=new StringBuilder();
	static Random rn=new Random();
	//output functions////////////////
	static void pr(Object a){output.append(a+"\n");}
	static void pr(){output.append("\n");}
	static void p(Object a){output.append(a);}
	static void pra(int[]a){for(int i:a)output.append(i+" ");output.append("\n");}
	static void pra(long[]a){for(long i:a)output.append(i+" ");output.append("\n");}
	static void pra(String[]a){for(String i:a)output.append(i+" ");output.append("\n");}
	static void pra(double[]a){for(double i:a)output.append(i+" ");output.append("\n");}
	static void sop(Object a){System.out.println(a);}
	static void flush(){System.out.println(output);output=new StringBuilder();}
	//////////////////////////////////
	//input functions/////////////////
	static int ni(){return in.nextInt();}
	static long nl(){return Long.parseLong(in.next());}
	static String ns(){return in.next();}
	static double nd(){return Double.parseDouble(in.next());}
	static int[] nia(int n){int a[]=new int[n];for(int i=0; i<n; i++)a[i]=ni();return a;}
	static int[] pnia(int n){int a[]=new int[n+1];for(int i=1; i<=n; i++)a[i]=ni();return a;}
	static long[] nla(int n){long a[]=new long[n];for(int i=0; i<n; i++)a[i]=nl();return a;}
	static String[] nsa(int n){String a[]=new String[n];for(int i=0; i<n; i++)a[i]=ns();return a;}
	static double[] nda(int n){double a[]=new double[n];for(int i=0; i<n; i++)a[i]=nd();return a;}
	//////////////////////////////////
	//some utility functions
	static void exit(){System.exit(0);}
	static void psort(int[][] a)
	{
		Arrays.sort(a, new Comparator<int[]>()
		{
			@Override
			public int compare(int[]a,int[]b)
			{
				if(a[0]>b[0])
					return 1;
				else if(b[0]>a[0])
					return -1;
				return 0;
			}
		});
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
	static int gcd(int a, int b)
	{
		if(b==0)
			return a;
		else
			return gcd(b, a%b);
	}
	/////////////////////////
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