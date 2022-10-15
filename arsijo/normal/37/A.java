import java.util.Scanner;


public class A37 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		int ar[] = new int[1000];
		
		for(int i = 0; i < n; i++){
			int a = sc.nextInt();
			ar[a-1]++;
		}
		
		int len = 0;
		int max = 0;
		
		for(int i = 0; i < 1000; i++){
			if (ar[i] != 0){
				len++;
				max = Math.max(max, ar[i]);
			}
		}
		
		System.out.println(max + " " + len);
	
		sc.close();
		
	}
	
}