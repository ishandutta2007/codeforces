import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String s=in.next();
		int l=s.length(),te = 0,te2=0;
		int beuno[][]=new int[l][3];
		for(int i=0; i<l; i++)
		{
			if(s.charAt(i)=='a')
			{
				te=0;te2=0;
				for(int j=0; j<i; j++)
				{
					te=Math.max(te, beuno[j][0]);
					te2=Math.max(te2, beuno[j][2]);
					te2=Math.max(te2, beuno[j][1]);
				}
				beuno[i][0]=te+1;
				beuno[i][2]=te2+1;
				//System.out.println(beuno[i][0]+" "+beuno[i][2]);
			}
			if(s.charAt(i)=='b')
			{
				te=0;
				for(int j=0; j<i; j++)
				{
					te=Math.max(te, beuno[j][1]);
					te=Math.max(te, beuno[j][0]);
				}
				beuno[i][1]=te+1;
				//System.out.println(beuno[i][1]+" "+te);
			}
		}
		int ans=0;
		for(int i=0; i<l; i++)
		{
			ans=Math.max(ans, beuno[i][0]);
			ans=Math.max(ans, beuno[i][1]);
			ans=Math.max(ans, beuno[i][2]);
		}
		System.out.println(ans);
	}

}