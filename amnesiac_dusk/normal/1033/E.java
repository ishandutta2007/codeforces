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
	static vector[]gra;
	static int col[];
	static void dfs(int fr, int at, int co)
	{
		col[at]=co;
		for(int i:gra[at])
			if(i!=fr)
				dfs(at,i,-co);
	}
	static void dfs(int at, int co)
	{
		if(col[at]==co)
			return;
		else if(col[at]==0)
		{
			col[at]=co;
			ans.push(at);
			for(int j:gra[at])
				dfs(j,-co);
			ans.pop();
		}
		else
		{
			ArrayList<Integer> an=new ArrayList<Integer>();
			an.add(at);
			while(ans.peek()!=at)
				an.add(ans.pop());
			ou.println("N "+an.size());
			for(int i:an)
				ou.print(i+" ");
			ou.flush();
			System.exit(0);
		}
	}
	static int query(vector te)
	{
		if(te.size==1||te.size==0)
			return 0;
		ou.println("? "+te.size);
		for(int i:te)
			ou.print(i+" ");
		ou.println();
		ou.flush();
		return ni();
	}
	static Stack<Integer> ans=new Stack<Integer>();
	static PrintWriter ou=new PrintWriter(System.out);
	public static void main(String[]args) throws Exception
	{
		int n=ni();
		gra=new vector[n+1];
		col=new int[n+1];
		for(int i=1; i<=n; i++) {
			gra[i]=new vector();
		}
		boolean[]conn=new boolean[n+1];
		conn[1]=true;
		vector que=new vector();
		for(int i=1; i<n; i++) {
			vector hola=new vector();
			vector rem=new vector();
			for(int j=1; j<=n; j++)
				if(conn[j])
					hola.add(j);
				else
					rem.add(j);
			int tempola=query(rem);
			while(hola.size>1) {
				vector te=new vector();
				for(int j=0; j<hola.size/2; j++)
					te.add(hola.a[j]);
				que.size=0;
				for(int j:te)
					que.add(j);
				for(int j:rem)
					que.add(j);
				int temp=query(que)-tempola-query(te);
				if(temp==0) {
					te.size=0;
					for(int j=hola.size/2; j<hola.size; j++)
						te.add(hola.a[j]);
				}
				hola=te;
			}
			int lol=hola.a[0];
			while(rem.size>1)
			{
				vector te=new vector();
				for(int j=0; j<rem.size/2; j++)
					te.add(rem.a[j]);
				que.size=0;
				for(int j:te)
					que.add(j);
				int temp=-query(que);
				que.add(lol);
				temp+=query(que);
				if(temp==0) {
					te.size=0;
					for(int j=rem.size/2; j<rem.size; j++)
						te.add(rem.a[j]);
				}
				rem=te;
			}
			gra[lol].add(rem.a[0]);
			gra[rem.a[0]].add(lol);
			conn[rem.a[0]]=true;
		}
		dfs(1,1,1);
		vector one=new vector();
		vector two=new vector();
		vector temp=null;
		for(int i=1; i<=n; i++)
			if(col[i]==1)
				one.add(i);
			else
				two.add(i);
		if(query(one)!=0)
			temp=one;
		else if(query(two)!=0)
			temp=two;
		if(temp==null)
		{
			ou.println("Y "+one.size);
			for(int i:one)
				ou.print(i+" ");
			ou.println();
			ou.flush();
		}
		else
		{
			int ind=0,on=0;
			ou:for(int i=ind; i<temp.size; i++)
			{
				ou.println("? "+(temp.size-i));
				for(int j=i; j<temp.size; j++)
					ou.print(temp.a[j]+" ");
				ou.println();
				ou.flush();
				int te=ni();
				if(te==0)
				{
					int o=i-1;
					on=temp.a[o];
					for(int j=o+1; j<temp.size; j++)
					{
						ou.println("? 2");
						ou.println(temp.a[o]+" "+temp.a[j]);
						ou.flush();
						if(ni()==1)
						{
							gra[temp.a[o]].add(temp.a[j]);
							gra[temp.a[j]].add(temp.a[o]);
							break ou;
						}
					}
				}
			}
			Arrays.fill(col,0);
			dfs(on,1);
		}
		System.out.println(output);
	}
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
	static final int mod2=998_244_353;
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