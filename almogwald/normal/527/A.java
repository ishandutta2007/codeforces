import java.util.Scanner;

public class paper {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		long a = in.nextLong();
		long b = in.nextLong();
		long c;
		long answer = 0;
		while (a != b) {
			if (a > b) {
				c = (a - 1) / b;
				a -= c * b;
				answer += c;
			} else {
				c = (b - 1) / a;
				b -= c * a;
				answer += c;
			}
		}
		answer++;
		System.out.println(answer);

	}

}