import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class A490 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		List<Integer> a = new ArrayList<>();
		List<Integer> b = new ArrayList<>();
		List<Integer> c = new ArrayList<>();
		for (int i = 1; i <= n; i++){
			int g = sc.nextInt();
			if (g == 1){
				a.add(i);
			}else if (g == 2){
				b.add(i);
			}else{
				c.add(i);
			}
		}
		sc.close();
		int len = Math.min(a.size(), Math.min(b.size(), c.size()));
		System.out.println(len);
		for(int i = 0; i < len; i++){
			System.out.println(a.get(i) + " " + b.get(i) + " " + c.get(i));
		}
	}
	
}