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
	static int[]diam,par;
	static boolean[] ass;
	static node[]gra;
	public static void main(String[] args)
	{
		int n=ni(),m=ni(),q=ni();
		gra=new node[n];
		diam=new int[n];
		par=new int[n];
		ass=new boolean[n];
		for(int i=0; i<n; i++)
		{
			gra[i]=new node();
			par[i]=i;
		}
		for(int i=0; i<m; i++)
		{
			int te=ni()-1,te1=ni()-1;
			gra[te].a.add(te1);
			gra[te1].a.add(te);
		}
		for(int i=0; i<n; i++)
			if(!ass[i])
				dfs(i,i);
		for(int i=0; i<q; i++)
		{
			if(ni()==1)
			{
				int te=ni()-1,te1=te;				
				while(par[te1]!=te1)
					te1=par[te1];
				pr(diam[te1]);
			}
			else
			{
				int te1=ni()-1,te2=ni()-1;
				while(te1!=par[te1])
					te1=par[te1];
				while(te2!=par[te2])
					te2=par[te2];
				if(te1!=te2)
				{
					diam[Math.min(te1,te2)]=Math.max(Math.max(diam[te1],diam[te2]),(1+diam[te1])/2+(1+diam[te2])/2+1);
					par[Math.max(te1, te2)]=Math.min(te1, te2);
				}
			}
		}
		System.out.println(output);
	}
	static int dfs(int a,int m)
	{
		ass[a]=true;
		par[a]=m;
		Iterator<Integer> it=gra[a].a.iterator();
		int te=0,te2=0,te3=0;
		while(it.hasNext())
		{
			int te1=it.next();
			if(!ass[te1])
			{
				te=dfs(te1,m)+1;
				if(te>te2)
				{
					te3=te2;
					te2=te;
				}
				else if(te>te3)
					te3=te;
				diam[m]=Math.max(diam[m], te2+te3);
			}
		}
		return te2;
	}
	static class node
	{
		List<Integer> a=new ArrayList<Integer>();
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
	static void psort(Integer[][] a)
	{
		Arrays.sort(a, new Comparator<Integer[]>()
		{
			@Override
			public int compare(Integer[]a,Integer[]b)
			{
				if(a[0]>b[0])
					return 1;
				else if(b[0]>a[1])
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