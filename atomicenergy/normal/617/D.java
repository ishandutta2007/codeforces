import java.util.*;
import java.math.*;
import java.io.*;
/**
 *
 * @author Zach
 */

public class ACM {
   
    
   
   
    
    public static void main(String[] args){
        int xa, xb, xc, ya, yb, yc;
        Scanner r = new Scanner(System.in); 
        xa = r.nextInt();
        ya = r.nextInt();
        xb = r.nextInt();
        yb = r.nextInt();
        xc = r.nextInt();
        yc = r.nextInt();
        if(xa==xb&&xb==xc||ya==yb&yb==yc){
            System.out.println(1);
        }
        else if((xa==xb&&((yc>yb) ^ (yc<ya)))||(xa==xc&&((yb>ya) ^ (yb<yc)))||(xc==xb&&((ya>yb) ^ (ya<yc)))){
            System.out.println(2);
        }
        else if((ya==yb&&((xc>xb) ^ (xc<xa)))||(ya==yc&&((xb>xa) ^ (xb<xc)))||(yc==yb&&((xa>xb) ^ (xa<xc)))){
            System.out.println(2);
        }
        else if((xa==xb&&((yc==yb) || (yc==ya)))||(xa==xc&&((yb==ya) || (yb==yc)))||(xc==xb&&((ya==yb) || (ya==yc)))){
            System.out.println(2);
        }
        else if((ya==yb&&((xc==xb) || (xc==xa)))||(ya==yc&&((xb==xa) || (xb==xc)))||(yc==yb&&((xa==xb) || (xa==xc)))){
            System.out.println(2);
        }
        else{
            System.out.println(3);
        }
    } 
    
}