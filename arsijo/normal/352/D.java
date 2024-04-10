import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ar[] = new int[n];
		for(int i = 0; i < n; i++)
			ar[i] = sc.nextInt();
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(ar[i] > ar[j])
					ans++;
			}
		}
		if(ans == 0){ 
			System.out.println(0); 
		}else if((ans & 1) == 0){
			System.out.println(ans * 2);
		}else{
			System.out.println((ans - 1) * 2 + 1);
		}
		sc.close();
	}
	
}