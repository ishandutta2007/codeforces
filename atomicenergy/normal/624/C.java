import java.util.*;
import java.math.*;
import java.io.*;
/**
 *
 * @author Zach
 */

public class ACM {    
    public static void main(String[] args){
        Scanner in = new Scanner (System.in);
        boolean[][] a = new boolean[500][500];
        int[] b = new int[500];
        int n = in.nextInt();
        int m = in.nextInt();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                a[i][j]=false;
            } 
            b[i]=-1;
            
        }
        //System.out.println(b[0] + " " + b[1] + " " + b[2] + " " + b[3]);
        for(int i=0; i<m; i++){
            int q = in.nextInt()-1;
            int w = in.nextInt()-1;
            a[q][w]=true;
            a[w][q]=true;
        }
        for(int i=0; i<n; i++){
            boolean c = true;
            for(int j=0; j<n; j++){
                if(i!=j&&!a[i][j]){
                    c=false;
                }
            }
            if(c){
                b[i]=2;
                //System.out.println(i);
            }
        }
        //System.out.println(b[0] + " " + b[1] + " " + b[2] + " " + b[3]);
        for(int i=0; i<n; i++){
            if(b[i]==-1){
                b[i]=1;
                for(int j=0; j<n; j++){
                    if(j!=i&&b[j]==-1){
                        if(a[i][j]){
                            b[j]=1;
                        }
                        else{
                            b[j]=3;
                        }
                    }
                }
            }
        }
        
        //System.out.println(b[0] + " " + b[1] + " " + b[2] + " " + b[3]);
        boolean c = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    if(a[i][j]==(b[i]*b[j]==3)){
                        c=false;
                    }
                }
            }
        }
        if(c){
            System.out.println("YES");
            for(int i=0; i<n; i++){
                if(b[i]==1){
                    System.out.print('a');
                }
                if(b[i]==2){
                    System.out.print('b');
                }
                if(b[i]==3){
                    System.out.print('c');
                }
            }
            System.out.println();
        }
        else{
            System.out.println("NO");
        }
    } 
}