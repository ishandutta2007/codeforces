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


public class ACM2 {    
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n=in.nextInt();
        System.out.println(2);
        for(long i = 2; i<=n; i++){
            long j = i*i*i+2*i*i+1;
            System.out.println(j);
        }
        
        
    }
}