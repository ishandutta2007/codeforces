import java.util.Scanner;


public class A112 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s1 = sc.nextLine();
		String s2 = sc.nextLine();
		sc.close();
		int a = s1.compareToIgnoreCase(s2);
		if (a < 0){
			System.out.println(-1);
		}else if (a > 0){
			System.out.println(1);
		}else{
			System.out.println(0);
		}
	}
	
}