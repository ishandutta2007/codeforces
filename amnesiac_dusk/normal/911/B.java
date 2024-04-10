
import java.util.*;

public class Main {
    public static void main(String[] args) {
    	Scanner in=new Scanner(System.in);  
    	int n=in.nextInt(),a=in.nextInt(),b=in.nextInt();
    	int te=(a*n)/(a+b);
    	int te1=(b*n)/(a+b);
    	int ans=0,ans1=0;
    	if(te!=0&&(n-te)!=0)
    	 ans=Math.min(b/(n-te), a/te);
    	if(n!=te1&&te1!=0)
    	 ans1=Math.min(a/(n-te1), b/te1);
    	int finans=Math.max(ans, ans1);
    	System.out.println(finans);
    }
}