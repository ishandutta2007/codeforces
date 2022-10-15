import java.util.Scanner;


public class B133 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = "";
		String n = sc.nextLine();
		
		for(int i = 0; i < n.length(); i++){
			s+=get(n.charAt(i));
		}
		
		System.out.println(translate(s));
	}
	
	public static long translate(String s){
		long ans = 0;
		
		for (int i = 0; i < s.length(); i++){
			
			ans = ans * 2;
			
			if(s.charAt(i) == '1')
				ans++;
			
			ans = ans % 1000003;
		}
		
		return ans;
	}
	
	public static String get(char c){
		switch (c) {
		
		case '>':
			return "1000";
			
		case '<':
			return "1001";
			
		case '+':
			return "1010";
			
		case '-':
			return "1011";
			
		case '.':
			return "1100";
			
		case ',':
			return "1101";
			
		case '[':
			return "1110";
			
		case ']':
			return "1111";
			

		default:
			return "";
		}
	}
	
}