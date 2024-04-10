import java.util.*;
public class _73_A_WayTooLongWords {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for(int i = 1; i<=N; i++) {
			String s = sc.next();
			if(s.length() <= 10) System.out.println(s);
			else System.out.println(s.charAt(0) + "" + (s.length()-2) + "" + s.charAt(s.length()-1));
		}
	}

}