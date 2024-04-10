import java.util.Scanner;
public class q {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		//int [] eat = new int[n];
		//int [] price = new int [n];
		int minprice=1000, total = 0;
		for (int i = 0; i < n; ++i) {
			//eat[i] = in.nextInt();
			//price[i] = in.nextInt();
			int eat = in.nextInt();
			int price = in.nextInt();
			minprice = Math.min(minprice, price);
			total += eat * minprice;
		}
		System.out.println(total);
	}

}