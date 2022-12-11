import java.util.*;
public class _118_A_StringTask {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		s = s.toLowerCase();
		s = s.replace("a", "");
		s = s.replace("e", "");
		s = s.replace("i", "");
		s = s.replace("o", "");
		s = s.replace("u", "");
		s = s.replace("y", "");
		
		for(int i = 0; i<s.length(); i++) System.out.print('.' + "" + s.charAt(i));

	}

}