import java.util.Scanner;

public class e {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int s= in.nextInt();
		long rern=0,evensum=0,evenmin=-1,numeven=0;
		for (int i=0;i<s;i++){
			int l= in.nextInt();
			if(l%2==0){
				rern+=l;
			} else {
				evensum+=l;
				numeven++;
				if(evenmin==-1||evenmin>l){
					evenmin=l;
				}
			}
		}
		if(numeven%2==0){
			rern+=evensum;
		}else{
			rern+=evensum-evenmin;
		}
		System.out.println(rern);
		in.close();
	}
}