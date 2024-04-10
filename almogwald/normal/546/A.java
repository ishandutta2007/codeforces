import java.util.Scanner;

public class soldierbannana {

	public static void main(String[] args) {
		long k,n,w;
		Scanner in = new Scanner(System.in);
		k = in.nextLong();
		n = in.nextLong();
		w = in.nextLong();
		long topay = k* ((1+w)*w/2);
		long borrow = topay - n;
		
		
	
		System.out.println(Math.max(0,borrow));
		in.close();
	}

}