import java.util.Scanner;


public class B467 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		k = sc.nextInt();
		String[] ar = new String[m];
		for (int i = 0; i < m; i++){
			ar[i] = getBinaryDigit(sc.nextInt());
		}
		String user =  getBinaryDigit(sc.nextInt());
		int res = 0;
		for(int i = 0; i < m; i++){
			if(check(user, ar[i])){
				res++;
			}
		}
		System.out.println(res);
	}
	
	public static int k;
	
	public static boolean check(String s1, String s2){
		int d = 0;
 		for(int j = 0; j < Math.min(s1.length(), s2.length()); j++){
			if(s1.charAt(j) != s2.charAt(j)){
				d++;
				if (d > k){
					return false;
				}
			}
		}
		if(s1.length() != s2.length()){
			if(s1.length() > s2.length()){
				for(int i = s2.length(); i < s1.length(); i++){
					if(s1.charAt(i) == '1'){
						d++;
						if (d > k){
							return false;
						}
					}
				}
			}else{
				for(int i = s1.length(); i < s2.length(); i++){
					if(s2.charAt(i) == '1'){
						d++;
						if (d > k){
							return false;
						}
					}
				}
			}
		}
		return true;
	}
	
	public static String getBinaryDigit(int a){
		String ans = "";
		while (a > 1) {
			ans = ans + (a % 2);
			a = a / 2;
		}
		ans = ans + (a % 2);
		return ans;
	}
	
}