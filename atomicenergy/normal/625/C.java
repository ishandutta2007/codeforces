import java.util.Scanner;

public class CodeForcesC {

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int[][] x = new int[a][a];
		int j = 1;
		for(int i=0; i<a; i++){
			for(int k=0; k<b-1; k++){
				x[i][k]=j;
				j++;			
			}
		}
		for(int i=0; i<a; i++){
			for(int k=b-1; k<a; k++){
				x[i][k]=j;
				j++;			
			}
		}
		int s=0;
		for(int i=0; i<a; i++){
			s+=x[i][b-1];
		}
		System.out.println(s);
		for(int i=0; i<a; i++){
			for(int k=0; k<a; k++){
				System.out.print(x[i][k] + " ");
			}
			System.out.println();
		}
}
}