import java.util.Scanner;

public class IceBreak {

	public static void main(String[] args) {
		int n, m, r1, c1, r2, c2;
		byte[][] map;
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();
		map = new byte[n + 2][m + 2];
		for (int i = 1; i <= n; i++) {
			String c = in.next();
		//	System.out.println(c);
			for (int j=1;j<=m;j++) {
				if (c.charAt(j-1) == '.') {
					map[i][j] = 1;
				}
			}
		}

		r1 = in.nextInt();
		c1 = in.nextInt();
		r2 = in.nextInt();
		c2 = in.nextInt();
		in.close();

		printmap(map,n,m);
		
		boolean solveable = false;
		if (map[r2][c2] == 0) {
			//System.out.println("ZERO");
			solveable = solve(map,r1,c1,r2,c2);			
		} else {
			if (map[r2-1][c2] == 1) {
				byte[][] map2 = map.clone();
				for (int i = 0; i < map2.length; i++) {
				    map2[i] = map2[i].clone();
				}
				map2[r2-1][c2] = 0;
				map2[r2][c2] = 0;
				solveable = solve(map2,r1,c1,r2,c2);		
				//System.out.println("UP");
				printmap(map,n,m);
				printmap(map2,n,m);
			}
			if (map[r2+1][c2] == 1 && !solveable) {
				byte[][] map2 = map.clone();
				for (int i = 0; i < map2.length; i++) {
				    map2[i] = map2[i].clone();
				}
				map2[r2+1][c2] = 0;
				map2[r2][c2] = 0;
				solveable = solve(map2,r1,c1,r2,c2);			
				//System.out.println("DOWN");
				printmap(map,n,m);
				printmap(map2,n,m);
			}
			if (map[r2][c2-1] == 1 && !solveable) {
				byte[][] map2 = map.clone();
				for (int i = 0; i < map2.length; i++) {
				    map2[i] = map2[i].clone();
				}
				map2[r2][c2-1] = 0;
				map2[r2][c2] = 0;
				solveable = solve(map2,r1,c1,r2,c2);			
				//System.out.println("LEFT");
				printmap(map,n,m);
				printmap(map2,n,m);
			}
			if (map[r2][c2+1] == 1 && !solveable) {
				byte[][] map2 = map.clone();
				for (int i = 0; i < map2.length; i++) {
				    map2[i] = map2[i].clone();
				}
				map2[r2][c2+1] = 0;
				map2[r2][c2] = 0;
				solveable = solve(map2,r1,c1,r2,c2);			
			//	System.out.println("RIGHT");
				printmap(map,n,m);
				printmap(map2,n,m);
			}
		}
		
		if (solveable) {
			System.out.println("YES");
		} else {
			System.out.println("NO");			
		}
		
		
	}

	private static void printmap(byte[][] map,int n, int m) {
/*		System.out.println("");
		for (int i = 0; i <= n+1; i++) {
			for (int j=0;j<=m+1;j++) {
				if (map[i][j] == 1) {
					System.out.print('.');
				} else {
					System.out.print(map[i][j]);					
				}
			}
			System.out.println("");
		}*/
	}

	private static boolean solve(byte[][] map, int r1, int c1, int r2, int c2) {
		//System.out.println(r1+" "+c1);
		if (((r1 == r2 + 1) && c1 == c2) ||
			((r1 == r2 - 1) && c1 == c2) ||
			((r1 == r2) && c1 == c2 + 1) ||
			((r1 == r2) && c1 == c2 - 1)) {
			return true;
		}
		map[r1][c1] = 2;
		if (map[r1-1][c1] == 1) {
			if (solve(map,r1-1,c1,r2,c2)) return true;
		}
		if (map[r1+1][c1] == 1) {
			if (solve(map,r1+1,c1,r2,c2)) return true;
		}
		if (map[r1][c1-1] == 1) {			
			if (solve(map,r1,c1-1,r2,c2)) return true;
		}
		if (map[r1][c1+1] == 1) {
			if (solve(map,r1,c1+1,r2,c2)) return true;			
		}
		return false;		
	}

}