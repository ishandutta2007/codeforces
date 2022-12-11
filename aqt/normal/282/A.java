import java.util.*;
public class _282_A_BitPlusPlus {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt(), X = 0;
		for(int i = 0; i<N; i++) {
			String s = sc.next();
			if(s.charAt(1) == '+') X++;
			else X--;
		}
		
		System.out.println(X);
	}

}