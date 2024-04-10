import java.util.Scanner;

public class CodeforcesD {

	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(); 
		char c;
		int a, b;
		int[] m = new int[367];
		int[] f = new int[367];
		for(int i=0; i<n; i++){
			if(in.next().equals("M")){
				m[in.nextInt()-1]++;
				m[in.nextInt()]--;
			}
			else{
				f[in.nextInt()-1]++;
				f[in.nextInt()]--;
			}
		}
		int max=Math.min(m[0], f[0]);

		for(int i=1; i<366; i++){
			m[i]+=m[i-1];
			f[i]+=f[i-1];
			if(Math.min(m[i], f[i])>max){
				max=Math.min(m[i], f[i]);
			}
		}
		System.out.println(2*max);

	}
	
}