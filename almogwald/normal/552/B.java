import java.util.Scanner;
public class bookdigits {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long a = in.nextLong();
		in.close();
		int b = Long.toString(a).length();
		long count = 0;
		for (int i =1;i<=b;i++) {
			if (i==b) {
				count += a * i;
			} else {
			   count += 9*(Math.pow(10, i-1))*(i);
			   a-=9*(Math.pow(10, i-1));
			}
		}
		System.out.println(count);
		
	}

}