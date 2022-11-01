import java.util.Scanner;

public class e {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n= in.nextInt();
		int[] diagonal_ltr =new int[2001];
		int[] diagonal_rtl =new int[2001];
		
		for (int i=0;i<n;i++){
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			diagonal_ltr[y - x + 999]++;
			diagonal_rtl[y + x]++;
		}
		in.close();
		long total_pairs = 0;
		for (int i = 0; i < 2001; ++i) {
			total_pairs += (diagonal_ltr[i]*(diagonal_ltr[i]-1)) / 2;
			total_pairs += (diagonal_rtl[i]*(diagonal_rtl[i]-1)) / 2;
		}
			
		System.out.println(total_pairs);
		in.close();
	}
}