import java.util.Scanner;


public class A82 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		while (n > 5){
			n -= 5;
			n = (n + 1) / 2;
		}
		switch (n % 5) {
		case 1:
			System.out.println("Sheldon");
			break;

		case 2:
			System.out.println("Leonard");
			break;
			
		case 3:
			System.out.println("Penny");
			break;
			
		case 4:
			System.out.println("Rajesh");
			break;
			
		case 0:
			System.out.println("Howard");
			break;
			
		default:
			break;
		}
		sc.close();
	}

	
}