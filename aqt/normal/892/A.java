import java.util.*;
import java.io.*;
public class _446_A_Greed {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		long total = 0;
		for(int i = 0; i<N; i++) total += Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int max = 0, secondMax = 0;
		for(int i = 0; i<N; i++) {
			int n = Integer.parseInt(st.nextToken());
			if(n >= max) {
				secondMax = max;
				max = n;
			}
			else if(n > secondMax) {
				secondMax = n;
			}
		}
		
		if(max + secondMax >= total) System.out.println("YES");
		else System.out.println("NO");
		
	}

}