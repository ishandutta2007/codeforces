import java.util.Scanner;
import java.util.Arrays;
public class e {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		int [] arr = new int[n];
		boolean [] gotit = new boolean[n];

		for (int i = 0; i < n; ++i) {
			arr[i] = in.nextInt();
			gotit[i] = false;
		}
		in.close();
		
		int cur_pieces = 0;
		int turns_count = 0;
		int direction = 1;
		int pos = 0;
		while (true) {
			if ((!gotit[pos]) && arr[pos] <= cur_pieces) {
				++cur_pieces;
				if (cur_pieces == n)
					break;
				gotit[pos] = true;
			}
			
			pos += direction;
			if (pos < 0) {
				pos = 1;
				direction = 1;
				++turns_count;
			} else if (pos == n) {
				pos = n- 2;
				direction = -1;
				++turns_count;
			}
		}

		System.out.println(turns_count);
	}
}