import java.util.*;
import java.io.*;
public class _020_C_Dijkstra {
	
	public static class Edge{
		int src, dest, weight;
		
		public Edge(int src, int dest, int weight) {
			this.src = src; this.dest = dest; this.weight = weight;
		}

	}
	
	public static class Pair implements Comparable<Pair>{
		int node; long weight;
		public Pair(int node, long dist) {
			this.node = node; this.weight = dist;
		}
		@Override
		public int compareTo(Pair o) {
			return Long.compare(this.weight, o.weight);
		}
	}

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
		
		HashMap<Integer, ArrayList<Edge>> map = new HashMap<Integer, ArrayList<Edge>>();
		
		for(int i = 1; i<=N; i++) map.put(i, new ArrayList<Edge>());
		
		for(int i = 1; i<=M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), w = Integer.parseInt(st.nextToken());
			map.get(a).add(new Edge(a, b, w)); map.get(b).add(new Edge(b, a, w));
		}
		
		long dist[] = new long[N+1];
		Arrays.fill(dist, Long.MAX_VALUE);
		dist[N] = 0;
		int parent[] = new int[N+1];
		PriorityQueue<Pair> queue = new PriorityQueue<Pair>();
		queue.add(new Pair(N, 0));
		
		while(!queue.isEmpty()) {
			Pair p = queue.poll();
			int currentNode = p.node; long wt = p.weight;
			if(dist[currentNode] != wt) continue;
			for(Edge e : map.get(currentNode)) {
				if(dist[e.dest] > dist[currentNode] + e.weight) {
					dist[e.dest] = dist[currentNode] + e.weight;
					parent[e.dest] = currentNode;
					queue.add(new Pair(e.dest, dist[e.dest]));
				}
			}
		}		
		
		if(dist[1] == Long.MAX_VALUE) {System.out.println(-1); System.exit(0);}
		int point = 1;
		while(point != 0) {
			System.out.print(point + " ");
			point = parent[point];
		}
		
		
		
		
		
		
	}

}