import java.io.*;
import java.util.*;
public class Main2
{
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String ns()
	{
		while(st==null||(!st.hasMoreTokens()))
		{	try {
				st=new StringTokenizer(br.readLine());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}
	static int ni()
	{
		return Integer.parseInt(ns());
	}
	public static void main(String[]args) throws Exception
	{
		int n=ni(),m=ni();
		long time=System.currentTimeMillis();
		int[]a=new int[n];
		long sum=0;
		for(int i=0; i<n; i++)
		{
			a[i]=ni();
			sum+=a[i];
		}
		sum*=2;
		sum%=m;
		Random rn=new Random();
		int teo,temp;
		for(int i=0; i<n; i++)
		{
			teo=rn.nextInt(n);
			temp=a[teo];
			a[teo]=a[i];
			a[i]=temp;
		}
		ArrayList<Integer> hol=new ArrayList<Integer>();
		for(int i=0; i<n; i++)
		{
			if(((a[0]+a[i]+0L)*n)%m==sum)
				hol.add((a[0]+a[i])%m);
		}
		Set<Integer> val=new HashSet<Integer>();
		for(int i=0; i<n; i++)
			val.add(a[i]);
		for(int i=1; i<n&&(System.currentTimeMillis()-time<1.2e3); i++)
		{
			ArrayList<Integer> te=new ArrayList<Integer>();
			for(int j:hol)
				if(val.contains((j-a[i]+m)%m))
					te.add(j);
			hol=te;
		}
		System.out.println(hol.size());
		StringBuilder out=new StringBuilder();
		if(hol.size()>0)
		{
			Collections.sort(hol);
			for(int i=0; i<hol.size()-1; i++)
				out.append(hol.get(i)+" ");
			out.append(hol.get(hol.size()-1));
			System.out.println(out);
		}
	}
}