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
	public static void main(String[] args)
	{
		int n=ni();
		int a[][]=new int[n][3];
		for(int i=0; i<n; i++)
		{
			a[i][0]=ni();
			a[i][1]=ni();
			a[i][2]=i;
		}
		Arrays.sort(a, new Comparator<int[]>()
				{
			@Override
			public int compare(int[]a,int[]b)
			{
				if(a[1]>b[1])
					return 1;
				else if(a[1]<b[1])
					return -1;
				else if(a[0]>b[0])
					return -1;
				else if(a[0]<b[0])
					return 1;
				return 0;
			}
				});
		int te=a[n-1][0];
		int ind=n-1;
		boolean done=false;
		for(int i=n-2; i>=0; i--)
		{
			if(te<=a[i][0])
			{
				pr((a[i][2]+1)+" "+(a[ind][2]+1));
				done=true;
				break;
			}
			else
			{
				te=a[i][0];
				ind=i;
			}
		}
		if(!done)
			pr("-1 -1");
		System.out.print(output);
	}
	
	
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
	static final long mod=1000000007;
	static final double eps=1e-8;
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
	static void psort(Integer[][] a)
	{
		Arrays.sort(a, new Comparator<Integer[]>()
		{
			@Override
			public int compare(Integer[]a,Integer[]b)
			{
				if(a[0]>b[0])
					return 1;
				else if(b[0]>a[1])
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