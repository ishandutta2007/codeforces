import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class C120 {

	public static boolean isDebug = false;
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc;
		PrintStream ps;
		if (isDebug){
			sc = new Scanner(System.in);
			ps = new PrintStream(System.out);
		}else{
			ps = new PrintStream(new File("output.txt"));
			sc = new Scanner(new File("input.txt"));
		}
		int n = sc.nextInt();
		int k = sc.nextInt();
		long ans = 0;
		for (int i = 0; i < n; i++){
			int a = sc.nextInt();
			boolean b = false;
			for(int j = 0; j < 3; j++){
				if(a < k){
					ans+= a;
					b = true;
					break;
				}
				a-=k;
			}
			if (!b) {
				ans+= a;
			}
		}
		ps.print(ans);
	}
	
}