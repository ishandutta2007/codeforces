import java.util.*;
public class _118_A_NextRound {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(), k = sc.nextInt();
		int marks[] = new int[101];
		for(int i = 0; i<n; i++) marks[sc.nextInt()]++;
		
		int count = 0;
		for(int i = 100; i>0; i--) {
			count += marks[i];
			if(count >= k) break;
		}
		
		System.out.println(count);
		
	}

}