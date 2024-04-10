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
		int n=ni(),m=ni();
		String[]s=nsa(n);
		Set<String> a=new HashSet<String>();
		Set<String> b=new HashSet<String>();
		Set<String> c=new HashSet<String>();
		long seed1=458219,seed2=134187077;
		long seed3=432359,seed4=1000000007;
		long te1=powm(seed1,seed2-2,seed2);
		long te2=powm(seed3,seed4-2,seed4);
		for(int i=0; i<n; i++)
		{
			long sum=0;
			long sum2=0;
			long tempola=powm(seed1,s[i].length()-1,seed2);
			long tempola2=powm(seed3,s[i].length()-1,seed4);
			for(int j=0; j<s[i].length(); j++)
			{
				sum=(sum*seed1+(s[i].charAt(j)-'a'+1))%seed2;
				sum2=(sum2*seed3+(s[i].charAt(j)-'a'+1))%seed4;
			}
			for(int j=0; j<s[i].length(); j++)
			{
				if(s[i].charAt(j)=='a')
				{
					a.add(((sum-tempola)%seed2+seed2)%seed2+""+((sum2-tempola2)%seed4+seed4)%seed4);
				}
				if(s[i].charAt(j)=='b')
				{
					b.add(((sum-2*tempola)%seed2+seed2)%seed2+""+((sum2-2*tempola2)%seed4+seed4)%seed4);
				}
				if(s[i].charAt(j)=='c')
				{
					c.add(((sum-3*tempola)%seed2+seed2)%seed2+""+((sum2-3*tempola2)%seed4+seed4)%seed4);
				}
				tempola=(te1*tempola)%seed2;
				tempola2=(te2*tempola2)%seed4;
			}
		}
		for(int i=0; i<m; i++)
		{
			String te=ns();
			long sum=0;
			long sum2=0;
			for(int j=0; j<te.length(); j++)
			{
				sum=(sum*seed1+te.charAt(j)-'a'+1)%seed2;
				sum2=(sum2*seed3+te.charAt(j)-'a'+1)%seed4;
			}
			long tempola=powm(seed1,te.length()-1,seed2);
			long tempola2=powm(seed3,te.length()-1,seed4);
			boolean boolor=false;
			for(int j=0; j<te.length(); j++)
			{
				String tem=(((sum-(te.charAt(j)-'a'+1)*tempola))%seed2+seed2)%seed2+""+(((sum2-(te.charAt(j)-'a'+1)*tempola2))%seed4+seed4)%seed4;
				if(te.charAt(j)=='a')
				{
					if(b.contains(tem)||c.contains(tem))
					{
						pr("YES");
						boolor=true;
						break;
					}
				}
				if(te.charAt(j)=='b')
				{
					if(a.contains(tem)||c.contains(tem))
					{
						pr("YES");
						boolor=true;
						break;
					}
				}
				if(te.charAt(j)=='c')
				{
					if(b.contains(tem)||a.contains(tem))
					{
						pr("YES");
						boolor=true;
						break;
					}
				}
				tempola=(tempola*te1)%seed2;
				tempola2=(tempola2*te2)%seed4;
			}
			if(!boolor)
				pr("NO");
		}
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