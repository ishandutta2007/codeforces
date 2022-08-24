import java.util.HashSet;
import java.util.Scanner;

public class BUNT
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int c1 = scan.nextInt();
		int c2 = scan.nextInt();
		String s = scan.nextLine();
		s = scan.nextLine();
		int a = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
		    if (s.charAt(i) == '1')
		    {
		        a++;
		    }
		    else
		    {
		        b++;
		    }
		}
		long ans = Long.MAX_VALUE;
		for (int cnt = 1; cnt <= a; cnt++)
		{
		    int other = b + a - cnt;
		    int kek = other / cnt;
		    long res = c1 * (long) cnt;
		    int ost = other % cnt;
		    res += (cnt - ost) * (long) kek * (long) kek * (long) c2;
		    res += ost * (long) (kek + 1) * (long) (kek + 1) * (long) c2;
		    ans = Math.min(ans, res);
		}
		System.out.println(ans);
	}
}