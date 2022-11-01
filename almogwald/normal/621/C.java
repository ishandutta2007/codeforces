import java.util.Scanner;

public class e {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int p = in.nextInt();
		int[] num_ps = new int[n];
		int[] options = new int[n];

		for (int i = 0; i < n; i++) {
			int l = in.nextInt();
			int r = in.nextInt();
			options[i] = r - l + 1;

			int first_p = ((l + p - 1) / p);
			int last_p = ((r + p) / p);
			num_ps[i] = last_p - first_p ;
		}
		in.close();

		double sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += 2000.0 * (1 - (1 - num_ps[i]*1.0 / options[i]) * (1 - (num_ps[(i + 1) % n]*1.0 / options[(i + 1) % n])));
		}

		System.out.println(sum);
		in.close();
	}
}