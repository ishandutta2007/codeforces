import java.util.Scanner;

public class CodeforcesD {

	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		String s = in.next();
		long c=0;
		if(s.charAt(0)%4==0){
			c=1;
		}
		for(int i=1; i<s.length(); i++){
			if(s.charAt(i)%4==0){
				c++;
			}
			if(s.charAt(i)%4==0&&s.charAt(i-1)%2==0){
				c+=i;
			}
			if(s.charAt(i)%4==2&&s.charAt(i-1)%2==1){
				c+=i;
			}
		}
		System.out.println(c);

	}
	
}