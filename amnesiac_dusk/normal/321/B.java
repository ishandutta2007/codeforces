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
		vecti jiat=new vecti();
		vecti jide=new vecti();
		vecti ciel=new vecti();
		for(int i=0; i<n; i++)
			if(ns().equals("ATK"))
				jiat.add(ni());
			else
				jide.add(ni());
		for(int i=0; i<m; i++)
			ciel.add(ni());
		jiat.sort();
		jide.sort();
		ciel.sort();
		long an=0;
		for(int i=0; i<ciel.size&&i<jiat.size; i++)
			if(ciel.a[ciel.size-i-1]>jiat.a[i])
				an+=ciel.a[ciel.size-i-1]-jiat.a[i];
			else
				break;
		long an2=0;
		NavigableMap<Integer,Integer> cie=new TreeMap<Integer,Integer>();
		for(int i=0; i<ciel.size; i++)
			cie.put(ciel.a[i], cie.getOrDefault(ciel.a[i], 0)+1);
		boolean pos=true;
		for(int i=0; i<jide.size; i++)
			if(cie.ceilingKey(jide.a[i]+1)!=null)
			{
				int te=cie.ceilingKey(jide.a[i]+1);
				if(!cie.remove(te,1))
					cie.put(te, cie.get(te)-1);
			}
			else
				pos=false;
		if(!pos)
			pr(an);
		else
		{
			for(int i=0; i<jiat.size; i++)
			{
				if(cie.ceilingKey(jiat.a[i])!=null)
				{
					int te=cie.ceilingKey(jiat.a[i]);
					an2+=te-jiat.a[i];
					if(!cie.remove(te, 1))
						cie.put(te, cie.get(te)-1);
				}
				else
					pos=false;
			}
			for(Map.Entry<Integer, Integer> te:cie.entrySet())
				an2+=te.getValue()*te.getKey();
			if(!pos)
				pr(an);
			else
				pr(Math.max(an, an2));
		}
		
		System.out.print(output);
	}
	
	
	
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
	static interface combiner
	{
		public int combine(int a, int b);
	}
	static final int mod=1000000007;
	static final double eps=1e-8;
	static final long inf=100000000000000000L;
	static Reader in=new Reader();
	static StringBuilder output=new StringBuilder();
	static Random rn=new Random();
	public static void sort(int[]a)
	{
		int te;
		for(int i=0; i<a.length; i++)
		{
			te=rn.nextInt(a.length);
			if(i!=te)
			{
				a[i]^=a[te];
				a[te]^=a[i];
				a[i]^=a[te];
			}
		}
		Arrays.sort(a);
	}
	public static void sort(long[]a)
	{
		int te;
		for(int i=0; i<a.length; i++)
		{
			te=rn.nextInt(a.length);
			if(i!=te)
			{
			a[i]^=a[te];
			a[te]^=a[i];
			a[i]^=a[te];
			}
		}
		Arrays.sort(a);
	}public static void sort(double[]a)
	{
		int te;
		double te1;
		for(int i=0; i<a.length; i++)
		{
			te=rn.nextInt(a.length);
			if(i!=te)
			{
			te1=a[te];
			a[te]=a[i];
			a[i]=te1;
			}
		}
		Arrays.sort(a);
	}
	public static void sort(int[][]a)
	{
		Arrays.sort(a, new Comparator<int[]>()
		{
			public int compare(int[]a,int[]b)
			{
				if(a[0]>b[0])
					return 1;
				if(b[0]>a[0])
					return -1;
				return 0;
			}
		});
	}
	static int lowerbound(int[]a, int key)
	{
		/*
		 * returns index of smallest element larger than equal to given element between indices l and r inclusive
		 */
		int low=0,high=a.length-1,mid=(low+high)/2;
		while(low<high)
		{
			if(a[mid] >= key)
				high=mid;
			else
				low=mid+1;
			mid=(low+high)/2;
		}
		return mid;
	}
	static int upperbound(int[]a, int key)
	{
		/*
		 * returns index of largest element smaller than equal to given element
		 */
		int low=0,high=a.length-1,mid=(low+high+1)/2;
		while(low<high)
		{
			if(a[mid] <= key)
				low=mid;
			else
				high=mid-1;
			mid=(low+high+1)/2;
		}
		return mid;
	}
	static int lowerbound(int[]a, int l, int r, int key)
	{
		/*
		 * returns index of smallest element larger than equal to given element between indices l and r inclusive
		 */
		int low=l,high=r,mid=(low+high)/2;
		while(low<high)
		{
			if(a[mid] >= key)
				high=mid;
			else
				low=mid+1;
			mid=(low+high)/2;
		}
		return mid;
	}
	static int upperbound(int[]a, int l, int r, int key)
	{
		/*
		 * returns index of largest element smaller than equal to given element
		 */
		int low=l,high=r,mid=(low+high+1)/2;
		while(low<high)
		{
			if(a[mid] <= key)
				low=mid;
			else
				high=mid-1;
			mid=(low+high+1)/2;
		}
		return mid;
	}
	static class pair
	{
		int a,b;
		pair()
		{
			
		}
		pair(int c,int d)
		{
			a=c;
			b=d;
		}	
	}
	void sort(pair[]a)
	{
		Arrays.sort(a,new Comparator<pair>()
				{
			@Override
			public int compare(pair a,pair b)
			{
				if(a.a>b.a)
					return 1;
				if(b.a>a.a)
				return -1;
				return 0;
			}
				});
	}
	static int log2n(long a)
	{
		int te=0;
		while(a>0)
		{
			a>>=1;
			++te;
		}
		return te;
	}
	static class iter
	{
		vecti a;
		int zin=0;
		iter(vecti b)
		{
			a=b;
		}
		public boolean hasNext()
		{
			if(a.size>zin)
				return true;
			return false;
		}
		public int next()
		{
			return a.a[zin++];
		}
		public void previous()
		{
			zin--;
		}
	}
	static class vecti
	{
		int a[],size;
		vecti()
		{
			a=new int[10];
			size=0;
		}
		vecti(int n)
		{
			a=new int[n];
			size=0;
		}
		public void add(int b)
		{
			if(++size==a.length)
				a=Arrays.copyOf(a, 2*size);
			a[size-1]=b;
		}
		public void sort()
		{
			Arrays.sort(a, 0, size);
		}
		public void sort(int l, int r)
		{
			Arrays.sort(a, l, r);
		}
		public iter iterator()
		{
			return new iter(this);
		}
	}
	static class lter
	{
		vectl a;
		int curi=0;
		lter(vectl b)
		{
			a=b;
		}
		public boolean hasNext()
		{
			if(a.size>curi)
				return true;
			return false;
		}
		public long next()
		{
			return a.a[curi++];
		}
		public long prev()
		{
			return a.a[--curi];
		}
	}
	static class vectl
	{
		long a[];
		int size;
		vectl()
		{
			a=new long[10];
			size=0;
		}
		vectl(int n)
		{
			a=new long[n];
			size=0;
		}
		public void add(long b)
		{
			if(++size==a.length)
				a=Arrays.copyOf(a, 2*size);
			a[size-1]=b;
		}
		public void sort()
		{
			Arrays.sort(a, 0, size);
		}
		public void sort(int l, int r)
		{
			Arrays.sort(a, l, r);
		}
		public lter iterator()
		{
			return new lter(this);
		}
	}
	static class dter
	{
		vectd a;
		int curi=0;
		dter(vectd b)
		{
			a=b;
		}
		public boolean hasNext()
		{
			if(a.size>curi)
				return true;
			return false;
		}
		public double next()
		{
			return a.a[curi++];
		}
		public double prev()
		{
			return a.a[--curi];
		}
	}
	static class vectd
	{
		double a[];
		int size;
		vectd()
		{
			a=new double[10];
			size=0;
		}
		vectd(int n)
		{
			a=new double[n];
			size=0;
		}
		public void add(double b)
		{
			if(++size==a.length)
				a=Arrays.copyOf(a, 2*size);
			a[size-1]=b;
		}
		public void sort()
		{
			Arrays.sort(a, 0, size);
		}
		public void sort(int l, int r)
		{
			Arrays.sort(a, l, r);
		}
		public dter iterator()
		{
			return new dter(this);
		}
	}
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
	static vecti niv(int n) {vecti a=new vecti(n);a.size=n;for(int i=0; i<n; i++)a.a[i]=ni();return a;}
	static vectl nlv(int n) {vectl a=new vectl(n);a.size=n;for(int i=0; i<n; i++)a.a[i]=nl();return a;}
	static vectd ndv(int n) {vectd a=new vectd(n);a.size=n;for(int i=0; i<n; i++)a.a[i]=nd();return a;}
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