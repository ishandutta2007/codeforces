import java.util.Scanner;



public class A119 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int n = sc.nextInt();
		sc.close();
		while (true){
			int nsd = nsd(a, n);
			if (nsd < n){
				n-=nsd;
			}else{
				System.out.println(0);
				return;
			}
			nsd = nsd(b, n);
			if (nsd < n){
				n-=nsd;
			}else{
				System.out.println(1);
				return;
			}
		}
	}
	
	public static int nsd(int a, int b){
		while (a != 0 && b != 0){
			if (a > b){
				a %= b;
			}else{
				b %= a;
			}
		}
		return a + b;
	}
	
}