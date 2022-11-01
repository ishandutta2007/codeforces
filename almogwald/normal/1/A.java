import java.util.Scanner;

public class Theatre {

	public static void main(String[] args) {
		double n, m, a;
		long result;
		Scanner in = new Scanner(System.in);
		n = in.nextLong();
		m = in.nextLong();
		a = in.nextLong();
		result = (new Double(Math.ceil(n / a))).longValue()
				* (new Double(Math.ceil(m / a))).longValue();
		System.out.println(result);
		in.close();
	}

}