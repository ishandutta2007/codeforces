import java.util.Scanner;


public class A431 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a1, a2, a3, a4;
		a1 = sc.nextInt();
		a2 = sc.nextInt();
		a3 = sc.nextInt();
		a4 = sc.nextInt();
		String s = sc.nextLine();
		s = sc.nextLine();
		int c = 0;
		for (int i = 0; i < s.length(); i++){
			switch(s.charAt(i)){
			case '1':{
				c+=a1;
				break;
			}
			case '2':{
				c+=a2;
				break;
			}
			case '3':{
				c+=a3;
				break;
			}
			case '4':{
				c+=a4;
				break;
			}
			}
		}
		System.out.println(c);
	}
	
}