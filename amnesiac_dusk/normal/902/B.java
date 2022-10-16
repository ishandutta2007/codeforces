import java.util.*;
import java.io.*;
 
public class Main 
{
	static class node
	{
		Vector<Integer> imd=new Vector<Integer>();
		int col;
	}
	static int colorit(node nod, int runcol)
	{
		Iterator<Integer> i=nod.imd.iterator();
		int ans=0;
		if(runcol!=nod.col)
		{
			ans++;
			runcol=nod.col;
		}
		while(i.hasNext())
		{
			ans+=colorit(tree[i.next()], runcol);
		}
		return ans;
	}
	static node[] tree;
	public static void main(String[] args) throws IOException
	{	
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		tree=new node[n+1];
		for(int i=1; i<=n; i++)
			tree[i]=new node();
		int te;
		for(int i=2; i<=n; i++)
		{
			te=in.nextInt();
			tree[te].imd.add(i);
		}
		for(int i=1; i<=n; i++)
			tree[i].col=in.nextInt();
		int ans=colorit(tree[1], 0);
		System.out.println(ans);
		in.close();
	}
}