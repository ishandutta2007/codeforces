import java.util.*;
import java.io.*;
public class _453_B_ColoringATree {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				
		int N = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		ArrayList<Integer> children[] = new ArrayList[N+1];
		
		for(int i = 1; i<=N; i++) children[i] = new ArrayList<Integer>();
		for(int i = 2; i<=N; i++) children[Integer.parseInt(st.nextToken())].add(i);
		
		st = new StringTokenizer(br.readLine());
		
		int color[] = new int[N+1];	
		
		for(int i = 1; i<=N; i++) color[i] = Integer.parseInt(st.nextToken());
		
		System.out.println(rec(children, 1, 0, color));
		
	}
	
	public static int rec(ArrayList<Integer> children[], int n, int prevCol, int color[]) {
		int count = 0;
		if(color[n] != prevCol) {
			prevCol = color[n];
			count++;
		}
//		if(children[n].isEmpty()) return count;
		
		for(int e: children[n]) count += rec(children, e, prevCol, color); 
		return count;
	}

}