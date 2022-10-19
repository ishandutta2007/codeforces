import java.util.Scanner;

public class CodeforcesD {

	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int b = in.nextInt();
		String c = in.next();
		char[] s = c.toCharArray();
		for(int i=0; i<s.length; i++){
			if(s[i]-'a'>=b){
				s[i]=(char) (s[i]-b);
				System.out.println(s);
				return;
			}
			if('z'-s[i]>=b){
				s[i]=(char) (s[i]+b);
				System.out.println(s);
				return;
			}
			if(s[i]<='m'){
				b-='z'-s[i];
				s[i]='z';
			}
			else{
				b-=s[i]-'a';
				s[i]='a';
			}
		}
		System.out.println(-1);

	}
	
}