import java.util.Scanner;

public class CodeforcesD {

	static int[] A;
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		String s = in.next();
		if(s.equals("1")){
			System.out.println(0);
			return;
		}
		A = new int[s.length()];
		for(int i=0; i<A.length; i++){
			A[i] = s.charAt(i) - '0';
		}
		if(A[0] == 1){
			int[] Atemp = A.clone();
			solution = new int[A.length];
			solution[0] = 0;
			if(isPossible(1, A.length-1, true)){
				printSolution();
				return;
			}
			A = Atemp;
		}
		solution = new int[A.length];
		if(isPossible(0, A.length-1, false)){
			printSolution();
		}
		else{
			System.out.println("0");
		}
	}
	
	static int[] solution;
	public static void printSolution(){
		boolean zeroes=true;
		for(int i=0; i<solution.length; i++){
			if(solution[i]!=0){
				zeroes=false;
			}
			if(!zeroes){
				System.out.print(solution[i]);
			}
		}
		System.out.println();
		
		
	}
	
	public static boolean isPossible(int front, int end, boolean carry1){
		if(front+1 == end){
			if(!carry1){
				solution[end]=A[front]/2;
				solution[front]=A[front]-A[front]/2;
				return A[front]==A[end];
			}
			if(carry1){
				solution[end]=A[end]/2+5;
				solution[front]=A[end]-A[end]/2+5;
				return (A[front]-1)==A[end];
			}
		}
		else if(front == end){
			solution[front] = ((carry1?10:0)+A[front])/2;
			return (A[front]%2 == 0);
		}
		else{
			if(carry1&&A[end]!=9){
				A[end-1]--;
				int index = end-1;
				while(index>=front&&A[index]==-1){
					A[index]=9;
					index--;
					A[index]--;
				}
				if(index<front){
					return false;
				}
			}
			if((A[end]+1)%10 == A[front]){
				if(A[end]==9&&!carry1){
					return false;
				}
				solution[end]=A[end]/2;
				solution[front]=A[end]-A[end]/2;
				if(A[end]==0&&front==0){
					//System.out.println("ASAHAHJKAS");
					return false;
				}
				if(carry1&&A[end]!=9){
					solution[end]+=5;
					solution[front]+=5;
				}
				boolean weirdCase=false;
				/*if(A[front]==0){
					weirdCase = true;
				}*/
				//System.out.println(A[2] + " " + A[3]);
				return isPossible(front+1, end-1, !weirdCase);
			}
			else if(A[front] == A[end]){
				solution[end]=A[end]/2;
				solution[front]=A[end]-A[end]/2;
				if(carry1){
					solution[end]+=5;
					solution[front]+=5;
				}
				return isPossible(front+1, end-1, false);
			}
			else{
				return false;
			}
		}
		return false;
	}
	
}