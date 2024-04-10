import java.util.Arrays;
import java.util.Scanner;

public class mikebears {

	public static void main(String[] args) {
		int n, m, q;
		byte[][] map;
		int[] maxcons, m2;
		int q1,q2;
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();
		q = in.nextInt();
		map = new byte[n+1][m+1];
		maxcons = new int[n+1];
		for (int i = 1; i <= n; i++) {
			for (int j=1;j<=m;j++) {
				map[i][j] = in.nextByte();
			}
			maxcons[i] = maxcon(map[i]);
		}
		//System.out.println(Arrays.toString(maxcons));
		
		for (int j=0;j<q;j++) {
			q1 = in.nextInt();
			q2 = in.nextInt();
			map[q1][q2] = (byte) Math.abs(map[q1][q2]-1); 
			maxcons[q1] = maxcon(map[q1]);
			//System.out.println(Arrays.toString(maxcons));
			m2 = Arrays.copyOf(maxcons,maxcons.length);
			Arrays.sort(m2);
			System.out.println(m2[m2.length-1]);
		}

		in.close();
		//printmap(map,n,m);
		//System.out.println(Arrays.toString(maxcons));
		System.exit(0);
				
	}

	private static int maxcon(byte[] line) {
		int tmpmax = 0;
		int mo=0;
		for (int i=0; i< line.length;i++) {
			if(line[i]==1){
				mo++;
			}else{
				mo=0;
			}
			tmpmax=Math.max(mo, tmpmax);
		}
		return tmpmax;
	}
	private static void printmap(byte[][] map,int n, int m) {
		System.out.println("");
		for (int i = 0; i <= n; i++) {
			for (int j=0;j<=m;j++) {

					System.out.print(map[i][j]);					
			}
			System.out.println("");
		}
	}

}