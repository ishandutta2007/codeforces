import java.util.*;
import java.util.Map.Entry;
import java.io.*;
/*
 * Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid...
 */
public class Main
{
	public static void main(String[]args) throws Exception
	{
		int n=ni(),m=ni(),k=ni();
		long[]keys=nla(n);
		Map<Long,vector>[]adj=new HashMap[n];
		for(int i=0; i<n; i++)
			adj[i]=new HashMap<Long,vector>();
		long[]edges=new long[m];
		int[][]corn=new int[2][m];
		par=new int[m];
		size=new int[m];
		Arrays.fill(size, 1);
		for(int i=0; i<m; i++)
		{
			corn[0][i]=ni()-1;
			corn[1][i]=ni()-1;
			edges[i]=keys[corn[0][i]]^keys[corn[1][i]];
			if(!adj[corn[0][i]].containsKey(edges[i]))
				adj[corn[0][i]].put(edges[i],new vector(i));
			else
				adj[corn[0][i]].get(edges[i]).add(i);
			if(!adj[corn[1][i]].containsKey(edges[i]))
				adj[corn[1][i]].put(edges[i],new vector(i));
			else
				adj[corn[1][i]].get(edges[i]).add(i);
		}
		keys=null;
		for(int i=0; i<m; i++)
			par[i]=i;
		vector temp;
		int te,te1;
		for(int i=0; i<n; i++)
			for(Map.Entry<Long,vector> ho:adj[i].entrySet())
			{
				temp=ho.getValue();
				te=fpar(temp.a[0]);
				for(int j=1; j<temp.size; j++)
				{
					te1=fpar(temp.a[j]);
					if(te!=te1)
						if(size[te]>size[te1])
						{
							par[te1]=te;
							size[te]+=size[te1];
						}
						else
						{
							par[te]=te1;
							size[te1]+=size[te];
							te=te1;
						}
				}
			}
		adj=null;
		size=null;
		long minans=0;
		Set<Integer>[]lol=new HashSet[m];
		for(int i=0; i<m; i++)
			if(par[i]==i)
				lol[i]=new HashSet<Integer>();
		for(int i=0; i<m; i++)
		{	
			lol[fpar(i)].add(corn[0][i]);
			lol[par[i]].add(corn[1][i]);
		}
		Map<Long,Integer>holas=new HashMap<Long,Integer>();
		for(int i=0; i<m; i++)
			if(par[i]==i)
				holas.put(edges[i],holas.getOrDefault(edges[i],0)+1-lol[i].size());
		int vals=holas.size();
		int[]pows=new int[n+1];
		pows[0]=1;
		for(int i=1; i<=n; i++)
			pows[i]=(pows[i-1]<<1)%mod;
		for(Entry<Long,Integer> tola:holas.entrySet())
			minans=(minans+pows[n+tola.getValue()]);
		minans=(minans+(pows[n]*(((1L<<k)-vals)%mod)))%mod;
		System.out.println(minans);
	}
	static int fpar(int i)
	{
		if(par[i]==i)
			return i;
		return par[i]=fpar(par[i]);
	}
	static int[]par,size;
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
		vector(int n){a=new int[10];a[0]=n;size=1;}
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