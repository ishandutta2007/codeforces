import java.util.Scanner;


public class A133 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.nextLine();
		
		sc.close();
		
		for(int i = 0; i < s.length(); i++){
			
			char c = s.charAt(i);
			
			if (c == 'H' || c == 'Q' || c == '9'){
				
				System.out.println("YES");
				return;
				
			}
		}
		System.out.println("NO");
		
	}
	
}