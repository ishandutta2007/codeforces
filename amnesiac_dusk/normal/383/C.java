import java.io.*;
import java.util.*;
//I am fading.......
//read the question correctly (is y a vowel? what are the exact constraints?)
//look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
public class Main
{
	static node[]gra;
	static vector pos,neg;
	static boolean[]posit;
	static pair[][]segs;
	public static void main(String[] args) throws Exception
	{
		int n=ni(),m=ni();
		int[]a=nia(n);
		graphcons(n,n-1);
		pos=new vector();
		neg=new vector();
		posit=new boolean[n];
		segs=new pair[n][2];
		dfs(-1,0,true);
		int[]posval=new int[pos.size];
		int[]negval=new int[neg.size];
		int[]map=new int[n];
		for(int i=0; i<pos.size; i++)
		{
			map[pos.a[i]]=i;
			posval[i]=a[pos.a[i]];
		}
		for(int i=0; i<neg.size; i++)
		{
			map[neg.a[i]]=i;
			negval[i]=a[neg.a[i]];
		}
		segtree pos=new segtree(posval,new combiner()
		{
			public int combine(int a,int b)
			{
				return a+b;
			}
		});
		segtree neg=new segtree(negval,new combiner()
		{
			public int combine(int a,int b)
			{
				return a+b;
			}
		});
		for(int i=0; i<m; i++)
		{
			if(ni()==1)
			{
				int x=ni()-1,val=ni();
				if(posit[x])
				{
					pos.add(val, segs[x][0].a, segs[x][0].b);
					neg.add(-val, segs[x][1].a, segs[x][1].b);
				}
				else
				{
					pos.add(-val, segs[x][0].a, segs[x][0].b);
					neg.add(val, segs[x][1].a, segs[x][1].b);
				}
			}
			else
			{
				int x=ni()-1;
				if(posit[x])
					pr(pos.query(map[x]));
				else
					pr(neg.query(map[x]));
			}
		}
		System.out.print(output);
	}
	//why code lazily :D
	static class segtree
	{
	//segment tree
	
	//n is segment tree size
	//take input from i=n to 2*n-1
	int n;
	int[]tr;
	combiner co;
	segtree(combiner cool)
	{
		co=cool;
	}
	segtree(int n, combiner cool)
	{
		this.n=n;
		co=cool;
		tr=new int[2*n];
	}
	segtree(int[]a, combiner cool)
	{
		co=cool;
		build(a);
	}
	void build()
	{
		for(int i=n-1; i>0; i--)
			tr[i]=co.combine(tr[i<<1],tr[(i<<1)|1]);
	}
	void build(int[]a)
	{
		n=a.length;
		tr=new int[2*n];
		System.arraycopy(a, 0, tr, n, n);
	}
	int query(int index)
	{
		int res=0;
		for(index+=n; index>0; index>>=1)
			res=co.combine(tr[index],res);
		return res;
	}
	void add(int val,int l, int r)
	{
		//both are inclusive
		for(l+=n, r+=n; l<r; l>>=1,r>>=1)
		{
			if(l%2!=0) tr[l++]+=val;
			if(r%2!=0) tr[--r]+=val;
		}
	}
	}
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
	static void dfs(int fr, int at,boolean par)
	{
		posit[at]=par;
		segs[at][0]=new pair(pos.size,0);
		segs[at][1]=new pair(neg.size,0);
		if(par)
			pos.add(at);
		else
			neg.add(at);
		for(int i:gra[at].adj)
			if(i!=fr)
				dfs(at,i,!par);
		segs[at][0].b=pos.size;
		segs[at][1].b=neg.size;
	}
	static class node
	{
		vector adj=new vector();
	}
	static void graphcons(int nodes, int edges)
	{
		gra=new node[nodes];
		for(int i=0; i<nodes; i++)
			gra[i]=new node();
		for(int i=0; i<edges; i++)
		{
			int te=ni()-1,te1=ni()-1;
			gra[te].adj.add(te1);
			gra[te1].adj.add(te);
		}
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