import java.util.Scanner;
import java.util.Arrays;
public class e {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		boolean [] horizontal = new boolean[n];
		boolean [] vertical = new boolean[n];
		for (int i = 0; i < n; ++i) {
			horizontal[i] = false;
			vertical[i] = false;
		}

		boolean is_first = true;
		for (int i = 0; i < n * n; ++i) {
			int h = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			if (!horizontal[h] && !vertical[v]) {
				horizontal[h] = true;
				vertical[v] = true;
				if (is_first) {
					is_first = false;
				} else {
					System.out.print(" ");
				}
				System.out.print(i + 1);
			}
			in.nextLine();
		}
		in.close();
	}
}