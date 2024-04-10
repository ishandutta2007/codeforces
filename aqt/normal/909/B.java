import java.util.*;
public class _455_B_Segments {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		if(N%2 == 1) System.out.println((N/2+1)*(N/2+1));
		else System.out.println((N/2+1)*(N/2));
	}

}