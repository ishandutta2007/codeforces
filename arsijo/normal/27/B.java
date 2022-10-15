import java.util.Scanner;


public class B27 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] ar1 = new int[n];
		int[] ar2 = new int[n];
		int games = (n * (n-1) / 2) - 1;
		for(int i = 0; i < games; i++){
			int g = sc.nextInt();
			int f = sc.nextInt();			
			ar1[g-1]++;
			ar2[f-1]++;
		}
		int a = 0;
		int b = 0;
		boolean bol = false;
		for(int i = 0; i < n; i++){
			if ((ar1[i] + ar2[i]) % (n-1) != 0){
				if(bol){
					b = i+1;
					break;
				}
				bol = true;
				a = i+1;
			}
		}
		if(ar1[a-1]>ar1[b-1]){
			System.out.println(a + " " + b);
		}else{
			System.out.println(b + " " + a);
		}
	}
	
}