import java.util.*;
public class _231_A_Team {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int count = 0;
		for(int i = 0; i<N; i++) {
			if(sc.nextInt() + sc.nextInt() + sc.nextInt() >= 2) count++;
		}
		
		System.out.println(count);
	}

}