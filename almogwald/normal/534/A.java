import java.util.Scanner;

public class Exam {

	public static void main(String[] args) {
		long n;
		Scanner in = new Scanner(System.in);
		n = in.nextLong();
		if (n==1 || n==2) {
			System.out.println("1");
			System.out.println("1");
		} else
		if (n==3) {
			System.out.println("2");
			System.out.println("1 3");
		} else
		if (n==4) {
			System.out.println("4");
			System.out.println("2 4 1 3");
		}
		else {
			System.out.println(n);
			for(long i=1;i<=n;i+=2){
				System.out.print(i+" ");
			}
			System.out.print("2");			
			for(long i=4;i<=n;i+=2){
				System.out.print(" "+i);
			}
			System.out.println("");
		}
		in.close();
	}

}