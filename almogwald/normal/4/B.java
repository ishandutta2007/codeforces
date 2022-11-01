import java.util.Scanner;

public class timer {
	public static void main(String[] args) {
		int n,sam;
		int[] maxim, minim;
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		sam = in.nextInt();
		maxim=new int[n];
		minim=new int[n];
		int sammin=0;
		int sammax=0;
		for (int i=0;i<n;i++){
			minim[i] = in.nextInt();
			maxim[i] = in.nextInt();
			sammin+=minim[i];
			sammax+=maxim[i];
		}
		if(sammin<=sam&&sam<=sammax){
			System.out.println("YES");
			int d=sammax-sam;
			int y=0;
			for (int i=0;i<n;i++){
				if(d==0){
					y=maxim[i];
				}else{
					y=minim[i];
					d-=maxim[i]-minim[i];
					if(d<0){
						y-=d;
						d=0;
					}
				}
				System.out.print(y);
				if(i!=n-1){
					System.out.print(" ");
				}
			}
		}else{
			System.out.println("NO");
		}
		
		in.close();
	}
}