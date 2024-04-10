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
		int n=ni(),k=ni();
		int[]a=nia(n);
		NavigableMap<Integer,Integer> ral=new TreeMap<Integer,Integer>();
		NavigableMap<Integer,Integer> b=new TreeMap<Integer,Integer>();
		int[]fin=new int[n];
		ral.put(256, 256);
		b.put(-256, -256);
		for(int i=0; i<n; i++)
		{
			Integer te=ral.ceilingKey(a[i]);
			int te1=ral.get(te);
			if(te1<=a[i])
			{
				fin[i]=te1;
				b.put(te, Math.max(b.get(te), a[i]));
			}
			else
			{
				int te2=b.floorKey(a[i]);
				if(te2+k>a[i])
				{
					int te3=b.get(te2);
					int te4=ral.get(te2);
					b.remove(te2);
					ral.remove(te2);
					fin[i]=Math.max(te3, a[i]-k)+1;
					b.put(fin[i]-1, te3);
					b.put(Math.min(te1-1,fin[i]-1+k), a[i]);
					ral.put(fin[i]-1, te4);
					ral.put(Math.min(te1-1,fin[i]-1+k),fin[i]);
				}
				else
				{
					fin[i]=Math.max(0, a[i]-k+1);
					if(a[i]-k+1<0)
					{
						b.put(Math.min(te1-1,k-1), a[i]);
						ral.put(Math.min(te1-1, k-1), 0);
					}
					else
					{
						b.put(a[i], a[i]);
						ral.put(a[i], a[i]-k+1);
					}
				}
			}
		}
		for(int i=0; i<n; i++)
			p(fin[i]+" ");
		System.out.println(output);
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