
import java.io.*;
import java.util.Scanner;
import java.util.Random;
import java.util.ArrayList;
import java.util.Collections;

//Zachary Polansky
//CSC171
//Project04
//RoadMapping

//Dan is here with me
//Bus buds' busts buzz but bus bumps buds' butts. 
//Commas are fun, so your rule must have one
//Dan the man and Zach attack 
//:)
//_header_
//what

public class ACM2 {
    
    
   
    
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        long a = 1;
        long b = 2;
        long c = 2;
        int i = 0;
        while(b<=n){
            c = b;
            b += a;
            a = c;
            i++;
        }
        System.out.println(i);
    }
}