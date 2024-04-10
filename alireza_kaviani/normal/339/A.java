import java.util.*;


public class codeforces1
{
    private static Scanner sc=new Scanner(System.in);

    public static void main(String[] args) {
        String s=sc.next();

        ArrayList<Integer> a=new ArrayList<>();

        int temp=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='+')
            {
                a.add(temp);
                temp=0;
            }
            else
            {
                temp*=10;
                temp+=Integer.parseInt(String.valueOf(s.charAt(i)));
            }
        }

        a.add(temp);

        Collections.sort(a);

        for(int i=0;i<a.size();i++)
        {
            System.out.print(a.get(i));
            if(i!=a.size()-1)
            {
                System.out.print("+");
            }
        }
    }
}