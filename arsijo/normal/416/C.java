import java.util.Scanner;


public class C416 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int c[] = new int[n];
		int p[] = new int[n];
		int ci[] = new int[n]; // clients indexes
		
		int l = 0; //max number of orders
		long sum = 0; 
		
		int o[] = new int[n]; 
		int t[] = new int[n];
		
		for(int i = 0; i < n; i++){
			c[i] = sc.nextInt();
			p[i] = sc.nextInt();
			ci[i] = i + 1;
		}
		
		int k = sc.nextInt();
		int r[] = new int[k];
		int ri[] = new int[k]; //orders indexes
		int e[] = new int[k]; //this is empty array, i need it only to sort another array
		
		for (int i = 0; i < k; i++){
			r[i] = sc.nextInt();
			ri[i] = i + 1;
		}
		
		sc.close();
		sort(r, ri, e);
		sort(p, c, ci);
		
		boolean b[] = new boolean[k];
		
		
		for(int i = 0; i < n; i++){
			
			for(int j = k-1; j >=0; j--){
				if(c[i] <= r[j] && !b[j]){
					o[l] = ci[i];
					t[l] = ri[j];
					sum+=p[i];
					l++;
					b[j] = true;
					break;
				}
			}
			
		}
		
		System.out.println(l + " " + sum);
		for(int i = 0; i < l; i++){
			System.out.println(o[i] + " " + t[i]);
		}
		/*
		 * nothing interesting
		 * System.out.println();
		for(int i = 0; i < n; i++){
			System.out.println(c[i] + " " + p[i]);
		}
		System.out.println();
		for(int i = 0; i < k; i++){
			System.out.println(r[i]);
		}*/
	}
	
	//QuickSort nothing interesting
	
	private static int array[];
	private static int array2[];
	private static int array3[];
	private static int length;

	public static void sort(int[] inputArr, int[] inputArr2, int[] inputArr3) {

		if (inputArr == null || inputArr.length == 0) {
			return;
		}
		array = inputArr;
		length = inputArr.length;
		array2 = inputArr2;
		array3 = inputArr3;
		quickSort(0, length - 1);
	}

	private static void quickSort(int lowerIndex, int higherIndex) {

		int i = lowerIndex;
		int j = higherIndex;
		int pivot = array[lowerIndex + (higherIndex - lowerIndex) / 2];
		while (i <= j) {
			while (array[i] > pivot) {
				i++;
			}
			while (array[j] < pivot) {
				j--;
			}
			if (i <= j) {
				exchangeNumbers(i, j);
				i++;
				j--;
			}
		}
		if (lowerIndex < j)
			quickSort(lowerIndex, j);
		if (i < higherIndex)
			quickSort(i, higherIndex);
	}

	private static void exchangeNumbers(int i, int j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		temp = array2[i];
		array2[i] = array2[j];
		array2[j] = temp;
		temp = array3[i];
		array3[i] = array3[j];
		array3[j] = temp;
	}
	
}