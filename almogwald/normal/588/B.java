import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class e {

	static boolean is_lovely(long n) {
		for (int i = 2; i < (int) (Math.sqrt(n)) + 1; ++i) {
			if (n % (i * i) == 0)
				return false;
		}
		return true;
	}

	public static List<Long> primeFactors(long number) {
		long n = number;
		List<Long> factors = new ArrayList<Long>();
		for (long i = 2; i <= Math.sqrt(n); i++) {
			while (n % i == 0) {
				factors.add(i);
				n /= i;
			}
		}
		if (n > 1) {
		  factors.add(n);
		}
		return factors;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		in.close();

		if (n == 1) {
			System.out.println(1);
			System.exit(0);			
		}
		
		List<Long> factors = primeFactors(n);
		Long last = factors.get(0);
		long total = last;
		for (int i = 1; i < factors.size(); ++i) {
			if (factors.get(i).equals(last)) {							
				continue;
			}
			last = factors.get(i);
			total = total * last;
		}
		
		System.out.println(total);
		

	}
}