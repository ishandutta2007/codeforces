import java.util.Arrays;
import java.util.Scanner;


public class C472 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[][] names = new String[sc.nextInt()][2];
		for (int i = 0; i < names.length; i++){
			names[i] = new String[] {sc.next(), sc.next()};
			Arrays.sort(names[i]);
		}
		String word = names[sc.nextInt()-1][0];
		for(int j = 0; j < names.length - 1; j++){
			String[] next = names[sc.nextInt()-1];
			if (word.compareTo(next[0]) < 0){
				word = next[0];
			} else if (word.compareTo(next[1]) < 0){
				word = next[1];
			} else {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
	
}