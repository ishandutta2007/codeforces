import java.io.*;
import java.util.*;
/*
 * Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid...
 */
//read the question correctly (is y a vowel? what are the exact constraints?)
//look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
//always declare multidimensional arrays as [2][n] not [n][2]
//it can lead to upto 2-3x diff in runtime
//declare int/long tries with 16 array size due to object overhead :D
public class Main
{
	static class segtree
	{
	//segment tree
	
	//n is segment tree size
	//take input from i=n to 2*n-1
	int n;
	long[]tr;
	void modify(int l, int r, long value) {
		  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		    if (l%2!=0)
		    {
		    	tr[l]=(tr[l]+value)%mod;
		    	l++;
		    }
		    if (r%2!=0)
		    {
		    	r--;
		    	tr[r]=(tr[r]+value)%mod;
		    }
		  }
		}
	long query(int pos)
	{
		long res=0;
		for(pos+=n; pos>0; pos>>=1)
			res=(res+tr[pos])%mod;
		return res;
	}
	}
	static long fib[];
	public static void main(String[] args) throws Exception
	{
		fib=new long[300010];
		fib[1]=fib[0]=1;
		for(int i=2; i<300010; i++)
			fib[i]=(fib[i-1]+fib[i-2])%mod;
		segtree a[]=new segtree[3];
		int n=ni(),m=ni();
		for(int i=0; i<3; i++)
		{
			a[i]=new segtree();
			a[i].tr=new long[2*n];
			a[i].n=n;
		}
//		nia(n);
		for(int i=0; i<n; i++)
			a[0].modify(i, n, ni());
//		sop(a[0].query(3));
		while(m-->0)
		{
			if(ni()==1)
			{
				int l=ni()-1,r=ni()-1;
				int sgn=(l%2==0)?-1:1;
				a[0].modify(l, n, -1);
				a[1].modify(l, n, sgn*fib[l+1]);
				a[2].modify(l, n, fib[l+2]*(-sgn));
				a[0].modify(r, n, fib[r-l+2]);
				a[1].modify(r, n, (-sgn)*fib[l+1]);
				a[2].modify(r, n, fib[l+2]*sgn);
			}
			else
			{
				int l=ni()-2,r=ni()-1;
				long te=(a[1].query(r)*fib[r+5])%mod+(a[2].query(r)*fib[r+4])%mod+(a[0].query(r))%mod;
				if(l!=-1)
				te-=(a[1].query(l)*fib[l+5])%mod+(a[2].query(l)*fib[l+4])%mod+a[0].query(l);
				pr((te%mod+mod)%mod);
			}
		}
		System.out.print(output);
	}
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
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
	static final int mod=1000000009;
	static final double eps=1e-9;
	static final long inf=100000000000000000L;
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