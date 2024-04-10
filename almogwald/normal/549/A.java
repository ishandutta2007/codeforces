import java.util.Arrays;
import java.util.Scanner;

public class Face {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		// a = in.nextLine();
		int n, m;
		n = in.nextInt();
		m = in.nextInt();
		String[] stringy;
		in.nextLine();

		stringy = new String[n];
		for (int i = 0; i < n; i++) {
			stringy[i] = in.nextLine();
		}

		String[] searchy = new String[] { "fa", "fc", "fe", "af", "ac", "ae",
				"ca", "cf", "ce", "ec", "ea", "ef" };
		String[] searchy2 = new String[] { "ce", "ae", "ac", "ce", "fe", "fc",
				"fe", "ae", "fa", "fa", "cf", "ac" };
		String[] searchy3 = new String[] { "ec", "ea", "ca", "ec", "ef", "cf",
				"ef", "ea", "af", "af", "fc", "ca" };

		//System.out.println(Arrays.toString(stringy));
		int counter = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < searchy.length; j++) {
				int fapos = 0;
				while (fapos != -1) {
					fapos = stringy[i].indexOf(searchy[j], fapos);
					if (fapos != -1) {
						//System.out.println(stringy[i + 1].substring(fapos, fapos + 2));
						if (stringy[i + 1].substring(fapos, fapos + 2).equals(
								searchy2[j])
								|| stringy[i + 1].substring(fapos, fapos + 2)
										.equals(searchy3[j])) {
							counter++;
						}
						fapos++;
					}
				}
			}

		}
		System.out.println(counter);

	}

}