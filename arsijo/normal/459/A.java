import java.util.Scanner;


public class A459 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int x1 = sc.nextInt();
		int y1 = sc.nextInt();
		
		int x2 = sc.nextInt();
		int y2 = sc.nextInt();
		
		if(x1 == x2){
			int x = Math.abs(y1 - y2) + x1;
			System.out.println(x + " " + y1 + " " + x + " " + y2);
		}else if (y1 == y2){
			int y = Math.abs(x1 - x2) + y1;
			System.out.println(x1 + " " + y + " " + x2 + " " + y);
		}else if (Math.abs(x1 - x2) == Math.abs(y1 - y2)){
			System.out.println(x1 + " " + y2 + " " + x2 + " " + y1);
		}else{
			System.out.println(-1);
		}
		
		sc.close();
		
	}
	
}