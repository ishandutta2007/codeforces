import java.util.Scanner;


public class A110 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		int b = 0;
		while(a != 0){
			if (a % 10 == 4 || a % 10 == 7){
				b++;
			}
			a = a / 10;
		}
		if(b == 4 || b == 7){
			System.out.println("YES");
		}else{
			System.out.println("NO");
		}
	}
	
}