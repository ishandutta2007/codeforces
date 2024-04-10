import java.math.BigInteger;
import java.util.Scanner;

public class e {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String[] cur=in.nextLine().split(" ");
		BigInteger a=new BigInteger(cur[0]);
		BigInteger b=new BigInteger(cur[1]);
		if(a.compareTo(b)==0){
			System.out.println(a);
		}else{
			System.out.println(1);
		}
		in.close();
	}
}