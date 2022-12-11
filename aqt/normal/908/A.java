import java.util.*;
public class CF_2017_Q1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		
		int count = 0;
		for(int i = 0; i<s.length(); i++) {
			if(s.charAt(i) - '0' <= 9) {
				if((s.charAt(i) - '0')%2 == 1)
				count++;
			}
			
			else if("aeiou".contains(s.charAt(i) + "")) count++;
		}
		System.out.println(count);
	}

}