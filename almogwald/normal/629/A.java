import java.util.Scanner;


public class e {
	
	/*public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int b = in.nextInt();
		int k = in.nextInt();
		int x = in.nextInt();
		
		int [] digits = new int [10];
		for (int i = 0; i < n; ++i) {
			int cur_digit = in.nextInt();
			digits[cur_digit]++;
		}
		in.close();
		
		
	}*/

	public static double my_log(double a, double b) {
		return Math.log(b) / Math.log(a);
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] colum = new int[n];
		long answer=0;
		for(int j=0;j<n;j++){
			int row=0;
			String cur=in.next();
			for(int i=0;i<n;i++){
				if(cur.charAt(i)=='C'){
					answer+=row;
					row++;
					colum[i]++;
				}
			}
		}
		for(int i=0;i<n;i++){
			answer+=((colum[i]-1)*(colum[i]))/2;
		}
		in.close();
		System.out.println(answer);
	}
}