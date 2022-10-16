import java.io.*;
import java.util.*;
//I am fading.......
//read the question correctly (is y a vowel? what are the exact constraints?)
//look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
public class Main
{
	static int temp;
	static class segtree
	{
		int n;
		int[][]tr;
		boolean lazy[];
		segtree()
		{
			
		}
		void apply(int ind)
		{
			temp=tr[1][ind];
			tr[1][ind]=tr[0][ind];
			tr[0][ind]=temp;
			if(ind<n)
				lazy[ind]=!lazy[ind];
		}
		void push(int p) {
			  for (int s = hei; s > 0; --s) {
			    int i = p >> s;
			    if (lazy[i]) {
			      apply(i<<1);
			      apply((i<<1)|1);
			      lazy[i] = false;
			    }
			  }
		}
			  void update(int l, int r) {
				  l += n;
				  r += n;
				  int l0 = l, r0 = r-1;
				  for (; l < r; l >>= 1, r >>= 1) {
				    if ((l&1)!=0) apply(l++);
				    if ((r&1)!=0) apply(--r);
				  }
				  push(l0);
				  push(r0);
				  build(l0);
				  build(r0);
				}
			  void build(int p) {
				  while (p > 1) {
					  p>>=1;
					  tr[0][p] = tr[0][p<<1]+tr[0][p<<1|1];
					  tr[1][p] = tr[1][p<<1]+tr[1][p<<1|1];
				  }
			}
			  int query(int l, int r) {
				  l += n;
				  r += n;
				  push(l);
				  push(r-1);
				  int res = 0;
				  for ( ;l<r; l >>= 1, r >>= 1) {
				    if ((l&1)!=0) 
				    	res +=tr[0][l++];
				    if ((r&1)!=0) 
				    			res +=tr[0][--r];
				  }
				  return res;
				}
	}
	static int log2(int hol)
	{
		return 32-Integer.numberOfLeadingZeros(hol);
	}
	static int hei;
	public static void main(String[] args) throws Exception
	{
		int n=ni();
		hei=log2(n)-1;
		int[]a=nia(n);
		segtree bits[]=new segtree[20];
		for(int i=0; i<20; i++)
		{
			bits[i]=new segtree();
			bits[i].n=n;
			bits[i].tr=new int[2][n<<1];
			bits[i].lazy=new boolean[n];
			for(int j=0; j<n; j++)
				if(((a[j]>>i)&1)!=0)
					bits[i].tr[0][j+n]=1;
				else
					bits[i].tr[1][j+n]=1;
			for(int j=n-1; j>0; j--)
			{
				bits[i].tr[0][j]=bits[i].tr[0][j<<1]+bits[i].tr[0][(j<<1)|1];
				bits[i].tr[1][j]=bits[i].tr[1][j<<1]+bits[i].tr[1][(j<<1)|1];
			}
		}
		int m=ni();
		while(m-->0)
		{
			if(ni()==1)
			{
				int l=ni()-1,r=ni();
				long ans=0;
				for(int i=0; i<20; i++)
					ans+=(1L<<i)*bits[i].query(l, r);
				pr(ans);
			}
			else
			{
				int l=ni()-1,r=ni(),x=ni();
				for(int i=0; i<20; i++)
					if((x>>i)%2!=0)
						bits[i].update(l, r);
			}
		}
		System.out.print(output);
	}
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
	static class node
	{
		vector adj=new vector();
	}
	static class pair
	{
		int a, b;
		pair(){}
		pair(int c,int d){a=c;b=d;}
	}
	static interface combiner
	{
		public int combine(int a, int b);
	}
	static final int mod=1000000007;
	static final double eps=1e-9;
	static final long inf=100000000000000000L;
	static Reader in=new Reader();
	static StringBuilder output=new StringBuilder();
	static Random rn=new Random();
	static void reverse(int[]a){for(int i=0; i<a.length/2; i++){a[i]^=a[a.length-i-1];a[a.length-i-1]^=a[i];a[i]^=a[a.length-i-1];}}
	static void sort(int[]a)
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
	static void sort(long[]a)
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
	static void sort(double[]a)
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
	static void sort(int[][]a)
	{
		Arrays.sort(a, new Comparator<int[]>()
		{
			public int compare(int[]a,int[]b)
			{
				if(a[0]>b[0])
					return -1;
				if(b[0]>a[0])
					return 1;
				return 0;
			}
		});
	}
	static void sort(pair[]a)
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
	static class vector implements Iterable<Integer>
	{
		int a[],size;
		vector(){a=new int[10];size=0;}
		vector(int n){a=new int[n];size=0;}
		public void add(int b){if(++size==a.length)a=Arrays.copyOf(a, 2*size);a[size-1]=b;}
		public void sort(){Arrays.sort(a, 0, size);}
		public void sort(int l, int r){Arrays.sort(a, l, r);}
		@Override
		public Iterator<Integer> iterator() {
			Iterator<Integer> hola=new Iterator<Integer>()
					{
				int cur=0;
						@Override
						public boolean hasNext() {
							return cur<size;
						}
						@Override
						public Integer next() {
							return a[cur++];
						}				
					};
			return hola;
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
	static void exit(){System.out.print(output);System.exit(0);}
	static int min(int... a){int min=a[0];for(int i:a)min=Math.min(min, i);return min;}
	static int max(int... a){int max=a[0];for(int i:a)max=Math.max(max, i);return max;}	
	static int gcd(int... a){int gcd=a[0];for(int i:a)gcd=gcd(gcd, i);return gcd;}	
	static long min(long... a){long min=a[0];for(long i:a)min=Math.min(min, i);return min;}
	static long max(long... a){long max=a[0];for(long i:a)max=Math.max(max, i);return max;}	
	static long gcd(long... a){long gcd=a[0];for(long i:a)gcd=gcd(gcd, i);return gcd;}	
	static String pr(String a, long b){String c="";while(b>0){if(b%2==1)c=c.concat(a);a=a.concat(a);b>>=1;}return c;}
	static long powm(long a, long b, long m){long an=1;long c=a;while(b>0){if(b%2==1)an=(an*c)%m;c=(c*c)%m;b>>=1;}return an;}
	static int gcd(int a, int b){if(b==0)return a;return gcd(b, a%b);}
	static long gcd(long a, long b){if(b==0)return a;return gcd(b, a%b);}
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