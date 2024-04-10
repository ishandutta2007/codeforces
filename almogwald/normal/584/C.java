import java.util.Scanner;
import java.util.Arrays;
public class e {

	public static char need_new(char c1, char c2) {
		if (c1 != 'a' && c2 != 'a') 
			return 'a';
		else if (c1 != 'b' && c2 != 'b') 
			return 'b';
		return 'c';
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int t = in.nextInt();
		in.nextLine();
		String s1 = in.next();
		in.nextLine();
		String s2 = in.next();
		in.close();
		
		if (s1.length() != n || s2.length() != n) {
	   		System.out.println(-1);		
			return;
		}
			
		int eq = 0;
		for (int i = 0; i < n; ++i) {
			if (s1.charAt(i) == s2.charAt(i))
				++eq;
		}
		
		if (t < (n - eq + 1) / 2) {
	   		System.out.println(-1);		
			return;
		}
		
		char [] built = new char[n];
		
		// Build the string
		if (n - t <= eq) {
			int save = n - t;
			for (int i = 0; i < n; ++i) {
				if (s1.charAt(i) != s2.charAt(i)) {
					built[i] = need_new(s1.charAt(i), s2.charAt(i));
				} else {
					if (save > 0) {
						--save;
						built[i] = s1.charAt(i);
					} else {
						built[i] = need_new(s1.charAt(i), s2.charAt(i));
					}
				}
			}
		} else {
			// n-t > eq
			int save1 = n - t - eq;
			int save2 = n - t - eq;
			for (int i = 0; i < n; ++i) {
				if (s1.charAt(i) == s2.charAt(i)) {
					built[i] = s1.charAt(i);
				} else if (save1 > 0) {
					--save1;
					built[i] = s1.charAt(i);					
				} else if (save2 > 0) {
					--save2;
					built[i] = s2.charAt(i);					
				} else {
					built[i] = need_new(s1.charAt(i), s2.charAt(i));
				}
			}
		}
		
		for (int i = 0; i < n; ++i)
			System.out.print(built[i]);		
	}
}