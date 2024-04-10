import java.util.*;
public class _35_A_NearestMinimum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		int arr[] = new int[N+1];
		
		int min = Integer.MAX_VALUE;
		
		for(int i = 1; i <=N; i++) {
			arr[i] = sc.nextInt();
			min = Math.min(min, arr[i]);
		}
		
		int idx = -200000;
		int minDis = Integer.MAX_VALUE;
		
		for(int i = 1; i<=N; i++) {
			if(arr[i] == min) {
				minDis = Math.min(minDis, i-idx);
				idx = i;
			}
		}
		
		System.out.println(minDis);
	}

}