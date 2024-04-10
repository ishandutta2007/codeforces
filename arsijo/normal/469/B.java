import java.util.Scanner;


public class B469 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int p = sc.nextInt();
		q = sc.nextInt();
		int l = sc.nextInt();
		int r = sc.nextInt();
		a = new int[q];
		b = new int[q];
		ar = new boolean[2001];
		for(int i = 0; i < p; i++){
			int c = sc.nextInt();
			int d = sc.nextInt();
			for(int j = c; j <= d; j++){
				ar[j] = true;
			}
		}
		for(int i = 0; i < q; i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		int ans = 0;
		for(int i = l; i <= r; i++){
			if(check(i)){
				ans++;
			}
		}
		System.out.println(ans);
	}
	
	public static int q;
	public static int[] a;
	public static int[] b;
	public static boolean[] ar;
	
	public static boolean check(int f){
		for(int i = 0; i < q; i++){
			for(int j = a[i]; j <= b[i]; j++){
				if(ar[j+f]){
					return true;
				}
			}
		}
		return false;
	}
	
}