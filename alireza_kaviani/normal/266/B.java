import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt(),t= sc.nextInt();

        String temp=sc.next();

        char[] s=temp.toCharArray();

        for(int i=0;i<t;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(s[j]=='B' && s[j]!=s[j+1])
                {
                    char c=s[j];
                    s[j]=s[j+1];
                    s[j+1]=c;
                    j++;
                }
            }
        }

        String ans=new String(s);

        System.out.println(ans);
    }

}