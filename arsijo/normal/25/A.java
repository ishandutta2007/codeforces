import java.util.Scanner;


public class A25 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		int a = 0;
		int b = 0;
		
		int lastA = 0;
		int lastB = 0;
		
		for(int i = 0; i < n; i++){
			int c = sc.nextInt();
			if(c % 2 == 0){
				a++;
				lastA = i;
			}else{
				b++;
				lastB = i;
			}
		}
		
		sc.close();
		
		if(a == 1){
			System.out.println(lastA + 1);
		}else if (b == 1){
			System.out.println(lastB + 1);
		}
		
	}
	
}