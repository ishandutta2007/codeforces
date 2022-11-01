import java.util.Scanner;

public class w {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int song_length = in.nextInt();
		int start = in.nextInt();
		int dl_speed = in.nextInt();
		//in.nextLine();
		in.close();
		int rerun=0;
		while (true){
			start*=dl_speed;
			rerun++;
					if (start>=song_length){
						System.out.println(rerun);
						System.exit(0);
					}
		}		
	}

}