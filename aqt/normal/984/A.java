import java.util.*; import java.io.*;
public class A {

	public static void main(String [] args) throws IOException{
		int N = readInt(); Integer arr[] = new Integer[N+1]; arr[0] = -1; for(int i = 1; i<=N; i++) arr[i] = readInt(); Arrays.sort(arr);
		println(arr[(N+1)/2]); exit();
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	
	static String read() throws IOException{
		while(st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine().trim()); 
		return st.nextToken();
	}
	
	static int readInt() throws IOException{
		return Integer.parseInt(read());
	}
	
	static void println(Object o) {
		pr.println(o);
	}
	
	static void exit() throws IOException{
		br.close(); pr.close(); System.exit(0);
	}
}