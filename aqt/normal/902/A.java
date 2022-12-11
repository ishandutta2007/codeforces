import java.util.*;
public class _453_A_VisitingAFriend {
	
	public static class Pair implements Comparable<Pair>{
		int start, end;
		public Pair(int start, int end) { this.start = start; this.end = end;}
		@Override
		public int compareTo(Pair o) {
			return Integer.compare(this.start, o.start);
		}
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
				
		int N = sc.nextInt(), M = sc.nextInt();
		
		Pair arr[] = new Pair[N];
		
		for(int i = 0; i<N; i++) arr[i] = new Pair(sc.nextInt(), sc.nextInt());
		
		Arrays.sort(arr);
		int crnt = 0;
		for(int i = 0; i<N; i++) {
			if(crnt < arr[i].start) break;
			else crnt = Math.max(crnt, arr[i].end);
		}
		
		if(crnt >= M) System.out.println("YES");
		else System.out.println("NO");
		
	}

}