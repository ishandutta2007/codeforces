import java.util.*;
public class _455_A_GenerateLogin {
	
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		
		String first = sc.next();
		String last = sc.next();
		
		String best = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
		PriorityQueue<String >queue = new PriorityQueue<String>();
		
		for(int i = 1; i<=first.length(); i++) {
			String s = first.substring(0, i);
			for(int j = 1; j<=last.length(); j++) {
				s += last.substring(0, j);
				queue.add(s);
				
			}
		}
		
		System.out.println(queue.poll());
		
		
	}
}