import java.util.*;
import java.io.*;
public class _453_C_HashingTrees {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int H = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine());
		int num[] = new int[H+1];

		boolean check = false, secondcheck = false;

		for(int i = 0; i<=H; i++) {
			num[i] = Integer.parseInt(st.nextToken());
			if(num[i] != 1) { 
				if(check) secondcheck = true;
				else check = true;
			}
			else {
				check = false;
			}
		}

		if(secondcheck) {
			System.out.println("ambiguous");
			ArrayList<Integer> set = new ArrayList<Integer>();
			set.add(0);

			int n = 0;
			for(int i = 0; i<=H; i++) {
				ArrayList<Integer> tempSet = new ArrayList<Integer>();
				for(int j = 0; j<num[i]; j++) {
					System.out.print(set.get(j%set.size()) + " ");
					tempSet.add(++n);
				}
				set = tempSet;
			}
			
			System.out.println();
			
			set.clear();
			set.add(0);
			
			n = 0;
			
			for(int i = 0; i<=H; i++) {
				ArrayList<Integer> tempSet = new ArrayList<Integer>();
				for(int j = 0; j<num[i]; j++) {
					System.out.print(set.get(0) + " ");
					tempSet.add(++n);
				}
				set = tempSet;
			}
			

		}
		else System.out.println("perfect");

	}

}