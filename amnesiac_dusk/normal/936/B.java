import java.io.*;
import java.util.*;
/*
 * 	Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid to fall...
 */
public class Main
{
	static final long mod=1000000007;
	static final double eps=1e-8;
	static final boolean debug=false;
	static Reader in=new Reader();
	static node[] grap;
	static boolean win=false;
	static boolean draw=false;
	static Stack<Integer> anser;
	static boolean visited[][];
	static boolean dfser[];
	static void dfs(int at, int dep)
	{
		pd("de "+at+" "+dep);
		dfser[at]=true;
		if(!visited[at][dep%2])
		{
			visited[at][dep%2]=true;
			if(!win)
			{
				if(grap[at].count==0)
				{
					if(dep%2==1)
						win=true;
				}
				else
				{
					Iterator<Integer> itr=grap[at].adj.iterator();
					while(itr.hasNext()&&(!win))
					{
						int te=itr.next();
						if(dfser[te])
							draw=true;
						dfs(te,dep+1);
					}
				}
			}
			if(win)
				anser.push(at+1);
		}
		dfser[at]=false;
	}
	public static void main(String[] args) throws IOException
	{
		int n=ni();
		ni();
		grap=new node[n];
		anser=new Stack<Integer>();
		int te;
		visited=new boolean[n][2];
		dfser=new boolean[n];
		for(int i=0; i<n; i++)
		{
			grap[i]=new node();
			te=ni();
			grap[i].count=te;
			for(int j=0; j<te; j++)
				grap[i].adj.add(ni()-1);
		}
		int st=ni()-1;
		dfs(st, 0);
		if(win)
		{
			pr("Win");
			while(!anser.isEmpty())
				p(anser.pop()+" ");
			pr("");
		}
		else if(draw)
			pr("Draw");
		else
			pr("Lose");
		System.out.println(ans);
	}
	static StringBuilder ans=new StringBuilder();
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
	static void pde()
	{
		if(debug)
			ans.append("hola");
	}
	static void pd(Object a)
	{
		if(debug)
			ans.append(a+"\n");
	}
	static void pr(Object a)
	{
		ans.append(a+"\n");
	}
	static void p(Object a)
	{
		ans.append(a);
	}
	static int ni()
	{
		return in.nextInt();
	}
	static long nl()
	{
		return in.nextLong();
	}
	static String ns()
	{
		return in.next();
	}
	static double nd()
	{
		return in.nextDouble();
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
class node
{
	ArrayList<Integer> adj=new ArrayList<Integer>();
	int count;
}