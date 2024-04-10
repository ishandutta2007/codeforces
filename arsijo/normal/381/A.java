

import java.util.Scanner;

public class A381 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int ar[] = new int[n];
		
		for(int i = 0; i < n; i++){
			ar[i] = sc.nextInt();
		}
		
		int l = 0;
		int r = n - 1;
		
		boolean isSergey = true;
		
		long s = 0;
		long d = 0;
		
		while(l != r){
			int plus;
			
			if(ar[l] > ar[r]){
				plus = ar[l];
				l++;
			}else{
				plus = ar[r];
				r--;
			}
			
			if(isSergey){
				s += plus;
			}else{
				d += plus;
			}
			//System.out.println(s + " " + d);
			isSergey = !isSergey;
		}
		
		if(isSergey){
			s += ar[l];
		}else{
			d += ar[l];
		}
			
		
		System.out.println(s + " " + d);
		sc.close(); 
	}
	
}