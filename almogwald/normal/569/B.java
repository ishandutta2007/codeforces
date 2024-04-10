import java.util.Scanner;

public class w {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		int[] old=new int[n];
		boolean[] exists=new boolean[n];
		for(int i=0;i<n;i++){
			old[i]=in.nextInt();
			exists[i]=false;
		}
		in.close();		
		int[] new_vals=new int[n];
		for(int i=0;i<n;i++){
			if(old[i] <= n && !exists[old[i]-1]){
				exists[old[i]-1]=true;
				new_vals[i]=old[i];
			}
		}
		int pos=0;
		for(int i=0;i<n;i++){
			if(new_vals[i]==0){
				for (int j = pos; j < n; ++j) {
					++pos;
					if (exists[j])
						continue;
					new_vals[i] = j + 1;
					break;					
				}
			}
			System.out.print(new_vals[i]);
			if (i != n-1)
				System.out.print(" ");
		}
		System.out.println("");
	}

}