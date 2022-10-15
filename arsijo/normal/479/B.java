import java.util.Scanner;


public class B479 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] ar = new int[n];
		int[] x = new int[k];
		int[] y = new int[k];
		boolean[][] bol = new boolean[n][n];
		for (int i = 0; i < n; i++){
			ar[i] = sc.nextInt();
		}
		for (int j = 0; j < k; j++){
			int min = ar[0];
			int max = ar[0];
			int minIndex = 0;
			int maxIndex = 0;
			for (int i = 1; i < n; i++){
				if (ar[i] < min){
					min = ar[i];
					minIndex = i;
				}
				if (ar[i] > max){
					max = ar[i];
					maxIndex = i;
				}
			}
			if(bol[minIndex][maxIndex] || ar[maxIndex] - ar[minIndex] < 2){
				System.out.println((max - min) + " " + j);
				for (int i = 0; i < j; i++){
					System.out.println((x[i] + 1) + " " + (y[i] + 1));
				}
				return;
			}
			bol[maxIndex][minIndex] = true;
			x[j] = maxIndex;
			y[j] = minIndex;
			ar[minIndex]++;
			ar[maxIndex]--;
		}
		int min = ar[0];
		int max = ar[0];
		for (int i = 1; i < n; i++){
			if (ar[i] < min){
				min = ar[i];
			}
			if (ar[i] > max){
				max = ar[i];
			}
		}
		System.out.println((max - min) + " " + k);
		for (int i = 0; i < k; i++){
			System.out.println((x[i] + 1) + " " + (y[i] + 1));
		}
		return;
	}
	
}