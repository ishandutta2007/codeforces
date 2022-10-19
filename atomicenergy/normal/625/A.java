import java.util.Scanner;

public class CodeforcesA {

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		long n = Long.parseLong(in.next());
		long a = Long.parseLong(in.next());
		long b = Long.parseLong(in.next());
		long c = Long.parseLong(in.next());
		if(a<=b-c){
			System.out.println(n/a);
		}
		else{
			long output = 0;
			if(n-b>=0){
				output+=(n-b)/(b-c);
				n-=(((n-b)/(b-c))*(b-c));
			}
			if(n>=b){
				n-=(b-c);
				output++;
			}
			output+=n/a;
			System.out.println(output);
		}
	}
	
}