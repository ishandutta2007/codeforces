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
		int n=ni();
		String[]a=new String[n];
		int[]nums=new int[n];
		Map<Integer,Integer> hola=new HashMap<Integer,Integer>();
		for(int i=0; i<n; i++)
		{
			a[i]=ns();
			for(int j=0; j<a[i].length(); j++)
				nums[i]^=(1<<(a[i].charAt(j)-'a'));
			hola.put(nums[i], hola.getOrDefault(nums[i],0)+1);
		}
		long ans=0;
		for(int i:hola.keySet())
		{
			long val=hola.get(i);
			ans+=((val)*(val-1));
			for(int j=0; j<26; j++)
				ans+=val*hola.getOrDefault(i^(1<<j),0);
		}
		System.out.println(ans/2);
	}
}