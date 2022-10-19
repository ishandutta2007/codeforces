


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
        int n = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        ArrayList<Integer> k = new ArrayList<>();
        if(b<a){
            int t = b;
            b = a;
            a = t;
        }
        for(int i=0; i<n; i++){
            k.add(in.nextInt());
        }
        Collections.sort(k);
        double t = 0;
        for(int i=n-1; i>=n-a; i--){
            t+=k.get(i);
        }
        t/=a;
        double u = 0;
        for(int i=n-a-1; i>=n-a-b; i--){
            u+=k.get(i);
        }
        u/=b;
        System.out.println(u+t);
        
    }
}