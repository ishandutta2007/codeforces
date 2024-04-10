import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	static boolean[] letters = new boolean[26] ;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int ans = -1;
		
		int counter = 0;
		
		for(int i = 1; i <= n; ++i) {
			char action = in.next().charAt(0);
			String w = in.next();

			if(action == '.') {
				
				for(int j = 0; j < w.length(); ++j) {
					letters[w.charAt(j)-'a'] = true;
				}
			}
			else if(action == '!') {
				if(ans!= -1) counter++;
				Set<Character> s = new HashSet<Character>();

				for(int j = 0; j < w.length(); ++j) {
					s.add(w.charAt(j));
				}
				
				for(int j = 0; j < 26; ++j) {
					char c = (char) ('a' + j);
					if(!s.contains(c)) letters[j] = true;
				}
			
			}
			else {
				char guess = w.charAt(0);
				if(i < n) {
					if(ans!=-1) counter++;
					letters[guess-'a'] = true;
				}
			}
			int count = 0;
			for(int j = 0; j < 26; ++j) {
				if(!letters[j]) count++;
			}
			if(count == 1 && ans == -1) {
				ans = n-i-1; 
			}
		}
		System.out.println(counter);
	}

}