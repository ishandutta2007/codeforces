import java.util.*;
import java.io.*;
public class _455_E_Coprocessor {
	
	static int count = 0;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
		
		boolean which[] = new boolean[N];
		ArrayList<Integer> graph[] = new ArrayList[N];		
		int indegree[] = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i<N; i++) if(st.nextToken().equals("1")) which[i] = true;
		
		for(int i = 0; i<N; i++) graph[i] = new ArrayList<Integer>();
		
		for(int i = 0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
			graph[b].add(a);
			indegree[a]++;
		}
		
		LinkedList<Integer> manu = new LinkedList<Integer>();
		LinkedList<Integer> comp = new LinkedList<Integer>();
		
		for(int i = 0; i<N; i++) {
			if(indegree[i] == 0) {
				if(which[i]) comp.add(i);
				else manu.add(i);
			}
		}
		
		manual(which, graph, indegree, manu, comp);
		System.out.println(count);
		
	}
	
	public static void manual(boolean which[], ArrayList<Integer> graph[], int indegree[], LinkedList<Integer> manu, LinkedList<Integer> comp) {
		
		while(!manu.isEmpty()) {
			int n = manu.pop();
			for(int e : graph[n]) {
				indegree[e]--;
				if(indegree[e] == 0) {
					if(which[e]) comp.add(e);
					else manu.add(e);
				}
			}
		}
		
		if(comp.isEmpty()) return;
		
		count++;
		comp(which, graph, indegree, manu, comp);
		
	}
	
	public static void comp(boolean which[], ArrayList<Integer> graph[], int indegree[], LinkedList<Integer> manu, LinkedList<Integer> comp) {
		while(!comp.isEmpty()) {
			int n = comp.pop();
			for(int e : graph[n]) {
				indegree[e]--;
				if(indegree[e] == 0) {
					if(which[e]) comp.add(e);
					else manu.add(e);
				}
			}
		}
		
		manual(which, graph, indegree, manu, comp);
	}

}