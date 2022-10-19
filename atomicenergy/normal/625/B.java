import java.util.Scanner;

public class Codeforces {

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		String s = in.next();
		String t = in.next();
		int i=0;
		int c=0;
		for(int j=0; j<s.length()-t.length()+1; j++){
			if(s.substring(j, j+t.length()).equals(t)){
				j=j+t.length()-1;
				c++;
			}
		}
		System.out.println(c);
	}
	
}