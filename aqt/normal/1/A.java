import java.util.*;
public class _1A_TheatreSquare {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(), m = sc.nextInt(), a = sc.nextInt();
		
		System.out.println((long)(Math.ceil(n*1.0/a) * Math.ceil(m*1.0/a)));
	}

}