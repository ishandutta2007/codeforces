import java.util.Scanner;


//Zachary Polansky
//CSC171
//Lab02
//LinkedList





public class Lab2ZP {

    /**
     * @param args the command line arguments
     */
  
    
    public static  void  main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n=in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        int c = ((a+b)%n+2*n)%n;
        if(c==0){
            c+=n;
        }
        System.out.println(c);
    }
    
  
     
    
    
    
    
}