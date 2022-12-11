import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;

public class LostNumbers {

	static int[] numbers = new int[] { 4, 8, 15, 16, 23, 42 };
	static int[] x = new int[] { 0, 1, 3, 4 };
	static int[] y = new int[] { 1, 2, 4, 5 };
	static int[] product = new int[4];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// Randomize numbers
//		int[] shuffle = new int[] { 4, 8, 15, 16, 23, 42 };
//		shuffleArray(shuffle);
//		System.out.println(Arrays.toString(shuffle));

		// Queries
		for (int i = 0; i < product.length; i++) {
			System.out.println("? " + (x[i] + 1) + " " + (y[i] + 1));
			product[i] = sc.nextInt();
//			product[i] = shuffle[x[i]] * shuffle[y[i]];
		}

		Set<Integer> set = new HashSet<Integer>();
		for (int i : numbers)
			set.add(i);

		permutations(set, new Stack<Integer>(), set.size());
	}

	public static void permutations(Set<Integer> items, Stack<Integer> permutation, int size) {

		/* permutation stack has become equal to size that we require */
		if (permutation.size() == size) {
			Integer[] perm = permutation.toArray(new Integer[0]);
			for (int i = 0; i < product.length; i++) {
				if (product[i] != perm[x[i]] * perm[y[i]])
					return;
			}
			System.out.print("!");
			for (int i : perm)
				System.out.print(" " + i);
			System.out.println();

//			System.exit(0);
			return;
		}

		/* items available for permutation */
		Integer[] availableItems = items.toArray(new Integer[0]);
		for (Integer i : availableItems) {
			/* add current item */
			permutation.push(i);

			/* remove item from available item set */
			items.remove(i);

			/* pass it on for next permutation */
			permutations(items, permutation, size);

			/* pop and put the removed item back */
			items.add(permutation.pop());
		}
	}

	static void shuffleArray(int[] ar) {
		Random rnd = new Random();
		for (int i = ar.length - 1; i > 0; i--) {
			int index = rnd.nextInt(i + 1);
			// Simple swap
			int a = ar[index];
			ar[index] = ar[i];
			ar[i] = a;
		}
	}
}