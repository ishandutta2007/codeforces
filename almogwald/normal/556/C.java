import java.util.Scanner;

public class w {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		in.nextLine();
		int seconds = 0;
		boolean had_first_chain = false;
		for (int i = 0; i < k; i++) {
			int chain_len = in.nextInt();
			seconds += chain_len - 1; // For the disassembly
			if (had_first_chain) {
			} else {
				int babushka = in.nextInt();
				if (babushka == 1) {
					had_first_chain = true;
					for (int j = 1; j < chain_len; ++j) {
						if (in.nextInt() == j + 1) {
							seconds-=2;
						}else{
							break;
						}
					}
				}

			}
			in.nextLine();
		}
		seconds+=n-1;
		System.out.println(seconds);
		in.close();
	}

}