import java.util.Scanner;

public class cars {

	public static void main(String[] args) {
		double n,p;
		int[] a;
		int[] g;
		int go=0;
		int co=0;
		Scanner in = new Scanner(System.in);
		n = in.nextLong();
		a=new int[(int) n+1];
		g=new int[(int) n+1];
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				p=in.nextLong();
				if(p==1){a[i+1]=1;}
				if(p==2){a[k+1]=1;}
				if(p==3){a[i+1]=1;a[k+1]=1;}
			}
		}
		for(int i=1;i<n+1;i++){
			if(a[i]==0){
				go++;
				g[i]=1;
			}
		}
		System.out.println(go);
		for(int i=1;i<n+1;i++){
			if(g[i]==1){
				if(co==1){
					System.out.print(" ");
				} else {
					co++;
				}
				g[i]=1;
				System.out.print(i);
			}
		}
		in.close();
	}

}