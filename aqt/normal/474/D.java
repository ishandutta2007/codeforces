import java.util.*;
import java.io.*;
public class _474_D_Flowers {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int constant = 1000000007;
		int T = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
		int DP[] = new int[100001];
		
		for(int i = 0; i<k; i++) DP[i] = 1;
		
		for(int i = k; i<=100000; i++) DP[i] = (DP[i-1] + DP[i-k])%constant;
		
		for(int i = 1; i<=100000; i++) DP[i] = (DP[i] + DP[i-1])%constant;
		
		for(int t = 0; t<T; t++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
			System.out.println((DP[b] + constant - DP[a-1])%constant);
		}
		
		
	}

}