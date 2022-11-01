import java.util.Scanner;
public class e {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		int[] votes = new int[n];
		for(int i=0;i<n;i++){
			votes[i]=in.nextInt();
		}
		in.close();
		int candy =0;
		while(true){
			int max=votes[0];
			int maxplc=0;
			for(int i=1;i<n;i++){
				if(votes[i]>=max){
					maxplc=i;
					max=votes[i];
				}
			}
			if(maxplc==0){
				break;
			}else{
				candy++;
				votes[0]++;
				votes[maxplc]--;
			}
		}
		System.out.println(candy);
		
	}

}