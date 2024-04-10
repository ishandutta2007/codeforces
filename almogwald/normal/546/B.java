import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class soldierbadges {

	public static void main(String[] args) {
		int n;

		Scanner in = new Scanner(System.in);
		n = in.nextInt();

		long[] a = new long [n];
	
		for (int i=0;i<n;i++) {
			a[i] = in.nextLong();
		}
		Arrays.sort(a);
		long minhonor=1;
		long coins=0;
		for (int i=0;i<n;i++) {
			minhonor = Math.max(minhonor,a[i]);
			coins+=minhonor-a[i];
			minhonor++;
		}
		
		System.out.println(coins);
		in.close();
	}

};