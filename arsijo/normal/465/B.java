import java.util.Scanner;


public class B465 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int count = 0;
		boolean flag = false; // is array[i-1] == 1
		for(int i = 0; i < n; i++){
			int r = sc.nextInt();
			if (r == 1){
				if (!flag && count != 0){
					count++;
				}
				count++;
			}
			flag = (r == 1);
		}
		System.out.println(count);
	}
	
}