import java.util.*;
import java.util.Arrays;
import java.math.*;
import java.io.*;
/*
     Zachary Polansky
     CSC171
     Lab06
     Queue
*/



public class ACM {    
   
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int c = in.nextInt();
        int last = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            int x = in.nextInt();
            if(x-last>c){
                count=1;
            }
            else{
                count++;
            }
            last=x;
        }
        System.out.println(count);
        
    }
}