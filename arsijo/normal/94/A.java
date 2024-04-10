import java.util.Scanner;


public class A94 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		password = sc.nextLine();
		ar = new String[10];
		for(int i = 0; i < 10; i++){
			ar[i] = sc.nextLine();
		}
		for(int i = 0; i < 8; i++){
			System.out.print(get(i * 10));
		}
	}
	
	public static int get(int pos){
		for(int i = 0; i < 10; i++){
			if(ar[i].equals((password.substring(pos , pos + 10)))){
				return i;
			}
		}
		return 0;
	}
	
	public static String password;
	public static String[] ar;
	
}