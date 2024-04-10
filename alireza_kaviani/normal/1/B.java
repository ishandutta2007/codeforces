import java.util.*;
import static java.lang.Math.*;

public class codeforces4
{
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n=sc.nextInt();

        for(int k=0;k<n;k++)
        {
            String s=sc.next();
            int c=0;
            boolean z=true;
            for(int i=0;i<s.length();i++)
            {
                if((int)s.charAt(i)<65 && z)
                {
                    c++;
                    z=false;
                }
                if(s.charAt(i)=='C')
                {
                    z=true;
                }
            }
            if(c>=2)
            {
                String t[]=new String[2];
                t[0]="";t[1]="";
                int j=0;
                for(int i=1;i<s.length();i++)
                {
                    if(s.charAt(i)=='C')
                    {
                        j++;
                    }
                    else
                    {
                        t[j]+=s.charAt(i);
                    }
                }
                int x=Integer.parseInt(t[0]);
                int y=Integer.parseInt(t[1]);
                String ans="";
                while(y!=0)
                {
                    int te=(y-1)%26;
                    y=(y-1)/26;
                    ans=(char)(te+65)+ans;
                }
                System.out.println(ans+""+x);
            }
            else
            {
                String t[]=new String[2];
                t[0]="";t[1]="";
                int j=0;
                boolean b=true;
                for(int i=0;i<s.length();i++)
                {
                    if((int)s.charAt(i)<65 && b)
                    {
                        j++;
                        b=false;
                    }
                    t[j]+=s.charAt(i);
                }

                int x=Integer.parseInt(t[1]);
                String y=t[0];

                j=0;
                int ans=0;
                for(int i=y.length()-1;i>=0;i--)
                {
                    ans+=(((int)y.charAt(i))-64)*(int)pow(26,j);
                    j++;
                }

                System.out.println("R"+x+"C"+ans);
            }
        }
    }
}