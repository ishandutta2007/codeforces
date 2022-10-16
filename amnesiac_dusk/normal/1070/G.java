import java.io.*;
import java.util.*;
/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
public class Main
{
	public static void main(String[]args) throws Exception
	{
		int n=ni(),m=ni();
		int[][]heroes=new int[m+2][3];
		for(int i=1; i<=m; i++) {
			heroes[i][0]=ni();
			heroes[i][1]=ni();
			heroes[i][2]=i;
		}
		heroes[m+1][0]=n+1;
		sort(heroes);
		int board[]=new int[n+2];
		for(int i=1; i<=n; i++)
			board[i]=ni();
		int[][]dist=new int[n+2][n+2];
		for(int i=0; i<=n+1; i++)
		{
			int lol=0,maxi=0;
			for(int j=i; j>=0; j--)
			{
				lol=0;maxi=0;
				for(int k=j; k<=i; k++)
				{
					lol-=board[k];
					maxi=max(maxi,lol);
				}
				dist[j][i]=maxi;
			}
			for(int j=i; j<=n+1; j++)
			{
				lol=0;maxi=0;
				for(int k=j; k>=i; k--)
				{
					lol-=board[k];
					maxi=max(maxi,lol);
				}
				dist[j][i]=maxi;
			}
		}
		for(int i=1; i<=n; i++)
		{
			int lo=0,hi=m+1,mi=(lo+hi+1)/2;
			while(lo<hi) {
				if(heroes[mi][0]>i)
					hi=mi-1;
				else
					lo=mi;
				mi=(lo+hi+1)/2;
			}
			int jlower=mi,jhigher=mi+1;
			if(jlower==0)
				continue;
			int lefttoposition=i;
			for(int k=jlower; k>0; k--)
				if(dist[heroes[k][0]][lefttoposition]<=heroes[k][1])
					lefttoposition=heroes[k][0];
			int righttoposition=i+1;
			for(int k=jhigher; k<=m; k++)
				if(dist[heroes[k][0]][righttoposition]<=heroes[k][1])
					righttoposition=heroes[k][0];
			if(lefttoposition<=heroes[1][0]&&righttoposition>=heroes[m][0])
			{
				pr(i);
				lefttoposition=i;
				righttoposition=i+1;
				vector dif=new vector();
				for(int k=jlower; k>0; k--)
					if(dist[heroes[k][0]][lefttoposition]<=heroes[k][1])
					{
						p(heroes[k][2]+" ");
						lefttoposition=heroes[k][0];
					}
					else
						dif.add(heroes[k][2]);
				for(int k=jhigher; k<=m; k++)
					if(dist[heroes[k][0]][righttoposition]<=heroes[k][1])
					{
						p(heroes[k][2]+" ");
						righttoposition=heroes[k][0];
					}
					else
						dif.add(heroes[k][2]);
				for(int k:dif)
					p(k+" ");
				exit();
			}
		}
		for(int i=1; i<=n; i++)
		{
			int lo=0,hi=m+1,mi=(lo+hi)/2;
			while(lo<hi) {
				if(heroes[mi][0]<i)
					lo=mi+1;
				else
					hi=mi;
				mi=(lo+hi)/2;
			}
			int lefttoposition=i-1,righttoposition=i;
			int jlower=mi-1,jhigher=mi;
			if(jhigher==m+1)
				continue;
			for(int k=jlower; k>0; k--)
				if(dist[heroes[k][0]][lefttoposition]<=heroes[k][1])
					lefttoposition=heroes[k][0];
			for(int k=jhigher; k<=m; k++)
				if(dist[heroes[k][0]][righttoposition]<=heroes[k][1])
					righttoposition=heroes[k][0];
			if(lefttoposition<=heroes[1][0]&&righttoposition>=heroes[m][0])
			{
				pr(i);
				lefttoposition=i-1;
				righttoposition=i;
				vector dif=new vector();
				for(int k=jhigher; k<=m; k++)
					if(dist[heroes[k][0]][righttoposition]<=heroes[k][1])
					{
						p(heroes[k][2]+" ");
						righttoposition=heroes[k][0];
					}
					else
						dif.add(heroes[k][2]);
				for(int k=jlower; k>0; k--)
					if(dist[heroes[k][0]][lefttoposition]<=heroes[k][1])
					{
						p(heroes[k][2]+" ");
						lefttoposition=heroes[k][0];
					}
					else
						dif.add(heroes[k][2]);
				
				for(int k:dif)
					p(k+" ");
				exit();
			}
		}
		pr(-1);
		System.out.println(output);
	}
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
//	static final long mod=998_244_353;
	static final long mod=1000_000_007;
	static final double eps=1e-7;
	static final long inf=1000_000_000_000_000_000L;
	static class pair
	{
		long a;
		int b;
		pair(){}
		pair(long c,int d){a=c;b=d;}
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
				return a[0]-b[0];
			}
				});
	}
	static interface combiner
	{
		public int combine(int a, int b);
	}
	static void pr(Object a){output.append(a).append('\n');}
	static void pr(){output.append('\n');}
	static void p(Object a){output.append(a);}
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
	static long powm(long a, long b, long mod){long an=1;long c=a%mod;while(b>0){if(b%2==1)an=(an*c)%mod;c=(c*c)%mod;b>>=1;}return an;}
	static long powm(long a, long b){long an=1;long c=a%mod;while(b>0){if(b%2==1)an=(an*c)%mod;c=(c*c)%mod;b>>=1;}return an;}
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