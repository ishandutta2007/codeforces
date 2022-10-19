
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
        int k = in.nextInt();
        String s = in.next();
        int i=0;
        while(s.charAt(i)!='G'&&s.charAt(i)!='T'){
            i++;
        }
        i+=k;
        while(i<s.length()&&s.charAt(i)!='G'&&s.charAt(i)!='T'){
            if(s.charAt(i)=='#'){
                System.out.println("NO");
                return;
            }
            i+=k;
        }
        if(i>=s.length()){
            System.out.println("NO");
                return;
        }
        System.out.println("YES");
        return;
    }
}