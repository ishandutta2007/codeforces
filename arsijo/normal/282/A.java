import java.util.Scanner;


public class A282 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.nextLine();
		int a = 0;
		for(int i = 0; i < n; i++){
			s = sc.nextLine();
			if(s.charAt(1) == '-'){
				a--;
			}else{
				a++;
			}
		}
		System.out.println(a);
	}
	
}