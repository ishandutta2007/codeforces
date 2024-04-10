import java.util.*;
import java.io.*;
public class _446_B_Wrath {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int arr[] = new int[N];
		boolean iskilled[] = new boolean[N];
		int point = N-1;
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i<N; i++) arr[i] = Integer.parseInt(st.nextToken());
		int count = 0;
		
		for(int i = N-1; i>=0; i--) {
			if(!iskilled[i]) count++;
			for(int j = point-1; j>=Math.max(i-arr[i], 0); j--) iskilled[j] = true;
			point = Math.min(point, Math.max(i-arr[i], 0));
//			System.out.println(i + " " + point);
		}
		System.out.println(count);

	}

}