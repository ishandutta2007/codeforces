import java.util.Scanner;

public class test
{
	public static void main(String[] args)
	{
		int n = new Scanner(System.in).nextInt();
		System.out.println(n%2 == 0 && n > 2 ? "YES" : "NO");
	}
}