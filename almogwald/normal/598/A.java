import java.util.Scanner;

public class e {
	public static long sum2(long n){
		long i=1;
		while(i<=n)
			i*=2;
		return i-1;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long p = in.nextLong();
		for (int i=0;i<p;i++){
			long n= in.nextLong();
			long answer=(1+n)*n/2;
			answer-=2*sum2(n);
			System.out.println(answer);
		}
		
		in.close();
	}
}