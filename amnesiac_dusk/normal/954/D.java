import java.io.*;
import java.util.*;
/*
 * 	Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid to fall...
 */
public class Main 
{
	static final long mod=1000000007;
	static final double eps=1e-8;
	static final long inf=100000000000000000L;
	static final boolean debug=true;
	static Reader in=new Reader();
	public static void main(String[] args) throws IOException
	{
		int n=ni(),m=ni(),s=ni()-1,t=ni()-1;
		double[][] dist=new double[n][n];
		Graph a=new Graph(n);
		int te,te1;
		for(int i=0; i<m; i++)
		{
			te=ni()-1;
			te1=ni()-1;
			a.addEdge(te, te1, 1);
			a.addEdge(te1, te, 1);
		}
		Dijkstra obj=new Dijkstra();
		for(int i=0; i<n; i++)
		{
			
			for(int j=0; j<n; j++)
				a.getVertices().get(j).minDistance=Double.POSITIVE_INFINITY;
			obj.calculate(a.getVertices().get(i));
			for(int j=0; j<n; j++)
				dist[i][j]=a.getVertices().get(j).minDistance;
		}
		int an=0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(dist[i][j]>1)	
				if((dist[i][s]+dist[t][j]+1>=dist[s][t])&&(dist[j][s]+dist[t][i]+1>=dist[s][t]))
					{
						an++;
					}
			}
		}
		an/=2;
		pr(an);
		System.out.println(ans);
	}
	static StringBuilder ans=new StringBuilder();
	static long powm(long a, long b, long m)
	{
		long an=1;
		long c=a;
		while(b>0)
		{
			if(b%2==1)
				an=(an*c)%m;
			c=(c*c)%m;
			b>>=1;
		}
		return an;
	}
	static void pd(){if(debug)ans.append("hola");}
	static void pd(Object a){if(debug)ans.append(a+"\n");}
	static void pr(Object a){ans.append(a+"\n");}
	static void pr(){ans.append("\n");}
	static void p(Object a){ans.append(a);}
	static int ni(){return in.nextInt();}
	static long nl(){return in.nextLong();}
	static String ns(){return in.next();}
	static double nd(){return in.nextDouble();}
	static String pr(String a, long b)
	{
		String c="";
		while(b>0)
		{
			if(b%2==1)
				c=c.concat(a);
			a=a.concat(a);
			b>>=1;
		}
		return c;
	}
	static class Reader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
        	return Long.parseLong(next());
        }
        public double nextDouble() {
        	return Double.parseDouble(next());
        }
    }
}
class Dijkstra{
	public void calculate(Vertex source){
			// Algo:
			// 1. Take the unvisited node with minimum weight.
			// 2. Visit all its neighbours.
			// 3. Update the distances for all the neighbours (In the Priority Queue).
			// Repeat the process till all the connected nodes are visited.
			
			source.minDistance = 0;
			PriorityQueue<Vertex> queue = new PriorityQueue<Vertex>();
			queue.add(source);
			while(!queue.isEmpty()){
				
				Vertex u = queue.poll();
			
				for(Edge neighbour:u.neighbours){
					Double newDist = u.minDistance+neighbour.weight;
					
					if(neighbour.target.minDistance>newDist){
						// Remove the node from the queue to update the distance value.
						queue.remove(neighbour.target);
						neighbour.target.minDistance = newDist;
						queue.add(neighbour.target);					
					}
				}
			}
		}

	}
class Edge{
	  public final Vertex target;
		public final double weight;
		public Edge(Vertex target, double weight){
			this.target = target;
			this.weight = weight;
		}
	}
class Vertex implements Comparable<Vertex>{
	  public final String name;
		public ArrayList<Edge> neighbours;
		public LinkedList<Vertex> path;
		public double minDistance = Double.POSITIVE_INFINITY;
		public Vertex previous;
		public int compareTo(Vertex other){
			return Double.compare(minDistance,other.minDistance);		
		}
		public Vertex(String name){
			this.name = name;
			neighbours = new ArrayList<Edge>();
		}
		public String toString(){
			return name;
		}	
	}
class Graph {
	  private ArrayList<Vertex> vertices;
		public Graph(int numberVertices){
			vertices = new ArrayList<Vertex>(numberVertices);
			for(int i=0;i<numberVertices;i++){
				vertices.add(new Vertex("v"+Integer.toString(i)));
			}
		}
		
		public void addEdge(int src, int dest, int weight){
			Vertex s = vertices.get(src);
			Edge new_edge = new Edge(vertices.get(dest),weight);
			s.neighbours.add(new_edge);
		}
		
		public ArrayList<Vertex> getVertices() {
			return vertices;
		}
	}