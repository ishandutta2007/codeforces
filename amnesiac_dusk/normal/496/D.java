import java.io.*;
import java.util.*;
//I am fading.......
//read the question correctly (is y a vowel? what are the exact constraints?)
//look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
public class Main
{
	public static void main(String[] args) throws Exception
	{
		int n=ni();
		int[]a=nia(n);
		int ct1=0,ct2=0;
		for(int i=0; i<n; i++)
			if(a[i]==1)
				ct1++;
			else
				ct2++;
		int co1[]=new int[2*n];
		int co2[]=new int[2*n];
		for(int i=0,j=0,k=0; i<n; i++)
			if(a[i]==1) co1[j++]=i;
			else if(a[i]==2) co2[k++]=i;
		for(int i=ct1; i<2*n; i++)
			co1[i]=1000000;
		for(int i=ct2; i<2*n; i++)
			co2[i]=1000000;
		int con1[]=new int[n];
		int con2[]=new int[n];
		for(int i=0; i<n; i++)
		{
			if(i!=0)
			{
			con1[i]+=con1[i-1];
			con2[i]+=con2[i-1];
			}
			if(a[i]==1)
				con1[i]++;
			else
				con2[i]++;
		}
		int ans=0;
		List<pair> hola=new ArrayList<pair>();
		for(int i=Math.max(ct1, ct2); i>0; i--)
		{
			int te1=0,te2=0;
			for(int k=0,l=0; ;)
			{
				pair mac1=new pair(),mac2=new pair();
				if(co1[k+i-1]<co2[l+i-1])
				{
					k+=i;
					l=con2[co1[k-1]];
					te1++;
					mac1.a=te1;
					mac1.b=te2;
					
				}
				else if(co1[k+i-1]>co2[l+i-1])
				{
					l+=i;
					k=con1[co2[l-1]];
					te2++;
					mac2.a=te1;
					mac2.b=te2;
					
				}
				else
					break;
				if(k==ct1&&l==ct2)
				{
					if(te1>te2&&mac1.a==te1&&mac1.b==te2)
					{
						hola.add(new pair(Math.max(te1, te2),i));
						ans++;
					}
					if(te1<te2&&mac2.a==te1&&mac2.b==te2)
					{
						hola.add(new pair(Math.max(te1, te2),i));
						ans++;
					}
					
					break;
				}
			}
		}
		sop(ans);
		Collections.sort(hola, new Comparator<pair>()
				{
			public int compare(pair a,pair b)
			{
				if(a.a>b.a)
					return 1;
				if(b.a>a.a)
					return -1;
				if(a.b>b.b)
					return 1;
				if(b.b>a.b)
					return -1;
				return 0;
			}
				});
		for(pair te:hola)
			pr(te.a+" "+te.b);
		System.out.print(output);
	}
	
	
	
	
	
	
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
	static class pair
	{
		int a,b;
		pair(){}
		pair(int c,int d){a=c;b=d;}
		@Override
		public int hashCode(){return (a+" "+b).hashCode();}
		@Override public boolean equals(Object c){if(a==((pair)c).a&&b==((pair)c).b)return true;return false;}
	}
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
		for(int i=0; i<a.length; i+=2)
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
		for(int i=0; i<a.length; i+=2)
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
	public static void sort(double[]a)
	{
		int te;
		double te1;
		for(int i=0; i<a.length; i+=2)
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
	static class vecti
	{
		int a[],size;
		vecti(){a=new int[10];size=0;}
		vecti(int n){a=new int[n];size=0;}
		public void add(int b){if(++size==a.length)a=Arrays.copyOf(a, 2*size);a[size-1]=b;}
		public void sort(){Arrays.sort(a, 0, size);}
		public void sort(int l, int r){Arrays.sort(a, l, r);}
	}
	static class vectl
	{
		long a[];
		int size;
		vectl(){a=new long[10];size=0;}
		vectl(int n){a=new long[n];size=0;}
		public void add(long b){if(++size==a.length)a=Arrays.copyOf(a, 2*size);a[size-1]=b;}
		public void sort(){Arrays.sort(a, 0, size);}
		public void sort(int l, int r){Arrays.sort(a, l, r);}
	}
	static class vectd
	{
		double a[];
		int size;
		vectd(){a=new double[10];size=0;}
		vectd(int n){a=new double[n];size=0;}
		public void add(double b){if(++size==a.length)a=Arrays.copyOf(a, 2*size);a[size-1]=b;}
		public void sort(){Arrays.sort(a, 0, size);}
		public void sort(int l, int r){Arrays.sort(a, l, r);}
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
	static int ni(){return Integer.parseInt(in.next());}
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
	static int min(int... a){int min=a[0];for(int i:a)min=Math.min(min, i);return min;}
	static int max(int... a){int max=a[0];for(int i:a)max=Math.max(max, i);return max;}	
	static int gcd(int... a){int gcd=a[0];for(int i:a)gcd=gcd(gcd, i);return gcd;}	
	static String pr(String a, long b){String c="";while(b>0){if(b%2==1)c=c.concat(a);a=a.concat(a);b>>=1;}return c;}
	static long powm(long a, long b, long m){long an=1;long c=a;while(b>0){if(b%2==1)an=(an*c)%m;c=(c*c)%m;b>>=1;}return an;}
	static int gcd(int a, int b){if(b==0)return a;return gcd(b, a%b);}
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
    }
}