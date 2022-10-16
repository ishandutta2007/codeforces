import java.io.*;
import java.util.*;
/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
public class Main
{
	static class segtree
	{ 
		int n;
		int[] tr;
		void build()
		{
			for(int i=n-1;i>0;i--)
				tr[i]=tr[i<<1]+tr[(i<<1)|1];
		}
		void modify(int p,int value)
		{
			for(tr[p+=n]=value;p>1;p>>=1)
				tr[p>>1]=tr[p]+tr[p^1];
		}
		int query(int l,int r)
		{
			r++; // both are inclusive
			int res=0;
			for(l+=n,r+=n;l<r;l>>=1,r>>=1)
			{
				if(l%2!=0)	res=(res+tr[l++]);
				if(r%2!=0)	res=(res+tr[--r]);
			}
			return res;
		}
		int getkth(int k)
		{
			int i=1;
			while(i<n)
			{
				if(tr[i<<1]>=k)
					i<<=1;
				else
				{
					k-=tr[i<<1];
					i=(i<<1)|1;
				}
			}
			return i-n;
		}
	}
	public static void main(String[]args) throws Exception
	{
		int n=ni();
		int[]a=nia(n),b=nia(n);
		int[]perma=new int[n];
		int[]permb=new int[n];
		segtree sa=new segtree();
		segtree sb=new segtree();
		sa.n=n;
		sb.n=n;
		sa.tr=new int[2*n];
		sb.tr=new int[2*n];
		Arrays.fill(sa.tr,n,2*n,1);
		Arrays.fill(sb.tr,n,2*n,1);
		sa.build();
		sb.build();
		for(int i=0; i<n; i++)
		{
			perma[i]=sa.query(0,a[i])-1;
			sa.modify(a[i],0);
			permb[i]=sb.query(0,b[i])-1;
			sb.modify(b[i],0);
		}
		int[]finp=new int[n];
		for(int i=n-1; i>=0; i--)
		{
			finp[i]+=perma[i]+permb[i];
			if(finp[i]>=n-i)
			{
				if(i!=0)
					finp[i-1]++;
				finp[i]-=n-i;
			}
		}
		segtree sfin=new segtree();
		sfin.n=2*Integer.highestOneBit(n);
		sfin.tr=new int[4*Integer.highestOneBit(n)];
		Arrays.fill(sfin.tr,sfin.n,2*sfin.n,1);
		sfin.build();
		for(int i=0; i<n; i++)
		{
			int te=sfin.getkth(finp[i]+1);
			p(te+" ");
			sfin.modify(te,0);
		}
		System.out.println(output);
	}
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
//	static final int mod=998_244_353;
	static final int mod=1000_000_007;
	static final double eps=1e-7;
	static final long inf=1000_000_000_000_000_000L;
	static class pair
	{
		int a,b;
		pair(){}
		pair(int c,int d){a=c;b=d;}
		@Override
		public int hashCode()
		{
			return (a+" "+b).hashCode();
		}
		public boolean equals(Object c)
		{
			return (a==(((pair)c).a)&&b==(((pair)c).b));
		}
	}
	public static void sort(int[][]a)
	{
		Arrays.sort(a, new Comparator<int[]>()
				{
			public int compare(int[]a,int[]b)
			{
				if(a[0]>b[0])
					return 1;
				if(a[0]<b[0])
					return -1;
				return 0;
			}
				});
	}
	static interface combiner
	{
		public int combine(int a, int b);
	}
	static void pr(Object a){output.append(a+"\n");}
	static void pr(){output.append("\n");}
	static void p(Object a){output.append(a);}
	static void pra(int[]a){for(int i:a)output.append(i+" ");output.append("\n");}
	static void pra(long[]a){for(long i:a)output.append(i+" ");output.append("\n");}
	static void pra(String[]a){for(String i:a)output.append(i+" ");output.append("\n");}
	static void pra(double[]a){for(double i:a)output.append(i+" ");output.append("\n");}
	static void sop(Object a){System.out.println(a);}
	static void flush(){System.out.print(output);output=new StringBuilder();}
	static int ni(){return Integer.parseInt(in.next());}
	static long nl(){return Long.parseLong(in.next());}
	static String ns(){return in.next();}
	static double nd(){return Double.parseDouble(in.next());}
	static int[] nia(int n){int a[]=new int[n];for(int i=0; i<n; i++)a[i]=ni();return a;}
	static int[] pnia(int n){int a[]=new int[n+1];for(int i=1; i<=n; i++)a[i]=ni();return a;}
	static long[] nla(int n){long a[]=new long[n];for(int i=0; i<n; i++)a[i]=nl();return a;}
	static String[] nsa(int n){String a[]=new String[n];for(int i=0; i<n; i++)a[i]=ns();return a;}
	static double[] nda(int n){double a[]=new double[n];for(int i=0; i<n; i++)a[i]=nd();return a;}
	static Reader in=new Reader();
	static StringBuilder output=new StringBuilder();
	static Random rn=new Random();
	static void reverse(int[]a){for(int i=0; i<a.length/2; i++){a[i]^=a[a.length-i-1];a[a.length-i-1]^=a[i];a[i]^=a[a.length-i-1];}}
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
	static class vectorl implements Iterable<Long>
	{
		long a[];
		int size;
		vectorl(){a=new long[10];size=0;}
		vectorl(int n){a=new long[n];size=0;}
		public void add(long b){if(++size==a.length)a=Arrays.copyOf(a, 2*size);a[size-1]=b;}
		public void sort(){Arrays.sort(a, 0, size);}
		public void sort(int l, int r){Arrays.sort(a, l, r);}
		@Override
		public Iterator<Long> iterator() {
			Iterator<Long> hola=new Iterator<Long>()
					{
				int cur=0;
						@Override
						public boolean hasNext() {
							return cur<size;
						}
						@Override
						public Long next() {
							return a[cur++];
						}				
					};
			return hola;
		}
	}
	static class vector implements Iterable<Integer>
	{
		int a[],size;
		vector(){a=new int[10];}
		vector(int n){a=new int[n];}
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
	static class deque {
		int a[];
		int head,tail;
		deque(){a=new int[8];}
		void clear()
		{
			head=0;tail=0;
		}
		void add(int i)
		{	
			head=(head+1)&(a.length-1);
			if(tail==head)
			{
				int[]b=new int[2*a.length];
				System.arraycopy(a, tail, b, 0, a.length-tail);
				System.arraycopy(a, 0, b, a.length-tail, head);
				tail=0;
				a=b;
				head=(a.length>>>1);
			}
			a[(head-1)&(a.length-1)]=i;
		}
		int poll()
		{
			tail=(tail+1)&(a.length-1);
			return a[(tail-1)&(a.length-1)];
		}
		boolean notempty()
		{
			return head!=tail;
		}
	}
	static void exit(){System.out.print(output);System.exit(0);}
	static int min(int... a){int min=a[0];for(int i:a)min=Math.min(min, i);return min;}
	static int max(int... a){int max=a[0];for(int i:a)max=Math.max(max, i);return max;}	
	static int gcd(int... a){int gcd=a[0];for(int i:a)gcd=gcd(gcd, i);return gcd;}	
	static long min(long... a){long min=a[0];for(long i:a)min=Math.min(min, i);return min;}
	static long max(long... a){long max=a[0];for(long i:a)max=Math.max(max, i);return max;}	
	static long gcd(long... a){long gcd=a[0];for(long i:a)gcd=gcd(gcd, i);return gcd;}	
	static String pr(String a, long b){String c="";while(b>0){if(b%2==1)c=c.concat(a);a=a.concat(a);b>>=1;}return c;}
	static long powm(long a, long b, long mod2){long an=1;long c=a%mod2;while(b>0){if(b%2==1)an=(an*c)%mod2;c=(c*c)%mod2;b>>=1;}return an;}
	static long pow(long a, long b){long an=1;long c=a;while(b>0){if(b%2==1)an*=c;c*=c;b>>=1;}return an;}
	static int gcd(int a, int b){if(b==0)return a;return gcd(b, a%b);}
	static long gcd(long a, long b){if(b==0)return a;return gcd(b, a%b);}
	static class Reader{
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in));
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