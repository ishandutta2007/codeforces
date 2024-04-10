import java.util.Scanner;


public class A384 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		System.out.println((n / 2) * (n / 2) + (n / 2 + (n % 2)) * (n / 2 + (n % 2)));
		
		String [] st = new String[2];
		
		for(int i = 1; i <= 2; i++){
			
			String s = "";
			int a = i % 2;
			
			for(int j = 1; j <= n; j++){
				if (j % 2 == a){
					s = s.concat("C");
				}else{
					s = s.concat(".");
				}
			}
			
			st[i-1] = s;
			
		}
		
		for(int i = 0; i< n; i++){
			System.out.println(st[i % 2]);
		}
		
		sc.close();
		
	}
	
}