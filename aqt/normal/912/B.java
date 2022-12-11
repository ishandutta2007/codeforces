import java.util.*;
public class _456_B_NewYearEve {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		long N = sc.nextLong(), K = sc.nextLong();
				
		if(K >= 2) {
			System.out.println(Long.highestOneBit(N)^((Long.highestOneBit(N)-1)));
		}
		else {
			System.out.println(N);
		}
	}

}