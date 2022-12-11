import java.util.*;
public class _456_A_TrickyAlchemy {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		long A = sc.nextInt(), B = sc.nextInt();
		
		long X = sc.nextInt(), Y = sc.nextInt(), Z = sc.nextInt();
		
		long totalA = X*2 + Y;
		long totalB = Y + 3*Z;
		
		System.out.println(Math.max(0, totalA-A) + Math.max(0, totalB-B));
	}

}