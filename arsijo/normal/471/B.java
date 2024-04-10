import java.util.Scanner;


public class B471 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] ar = new int[n];
		int[] index = new int[n];
		for(int i = 0; i < n; i++){
			ar[i] = sc.nextInt();
			index[i] = i+1;
		}
		QuickSort qs = new QuickSort();
		qs.sort(ar, index);
		int[][] indexes = new int[2][2];
		int k = 0;
		for (int i = 1; i < n; i++){
			if (ar[i] == ar[i-1]){
				indexes[k][0] = i-1;
				indexes[k][1] = i;
				k++;
				if (k == 2){
					break;
				}
			}
		}
		if (k != 2){
			System.out.println("NO");
			return;
		}
		System.out.println("YES");
		int[] a1 = index.clone();
		int[] a2 = index.clone();
		int temp = a1[indexes[0][0]];
		a1[indexes[0][0]] = a1[indexes[0][1]];
		a1[indexes[0][1]] = temp;
		temp = a2[indexes[1][0]];
		a2[indexes[1][0]] = a2[indexes[1][1]];
		a2[indexes[1][1]] = temp;
		printArray(index);
		printArray(a1);
		printArray(a2);
		/*for(int i = 0; i < n; i++){
			System.out.print(index[i] + " ");
		}
		System.out.println();
		for(int j = 0; j < 2; j++){
			for(int i = 0; i < n; i++){
				if (indexes[j][0] == i){
					System.out.print(index[indexes[j][1]] + " ");
				} else if (indexes[j][1] == i){
					System.out.print(index[indexes[j][0]] + " ");
				} else {
					System.out.print(ar[i] + " ");
				}
			}
			System.out.println();
		}*/
	}
	
	public static void printArray(int[] array){
		for(int i = 0; i < array.length; i++){
			System.out.print(array[i] + " ");
		}
		System.out.println();
	}
	
	public static class QuickSort {
		private int array[];
		private int length;
		private int indexes[];
		
		public void sort(int[] inputArr, int[] indexes) {

			if (inputArr == null || inputArr.length == 0) {
				return;
			}
			this.indexes = indexes;
			this.array = inputArr;
			length = inputArr.length;
			quickSort(0, length - 1);
		}

		private void quickSort(int lowerIndex, int higherIndex) {

			int i = lowerIndex;
			int j = higherIndex;
			int pivot = array[lowerIndex + (higherIndex - lowerIndex) / 2];
			while (i <= j) {
				while (array[i] < pivot) {
					i++;
				}
				while (array[j] > pivot) {
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

		private void exchangeNumbers(int i, int j) {
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			temp = indexes[i];
			indexes[i] = indexes[j];
			indexes[j] = temp;
		}

	}

	
}