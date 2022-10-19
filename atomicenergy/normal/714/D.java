import java.util.*;
import java.util.Arrays;
import java.math.*;
import java.io.*;
/**
 *
 * @author Zach
 */



public class ACM {    
    
    public static void main(String[] args){
        
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int l = 0;
        int r = n;
        while(r-l>1){
            int c = (r+l)/2;
            System.out.println('?' + " 1 1 " + c + " " + n);
            int x = in.nextInt();
            if(x==0){
                l=c;
            }
            else{
                r=c;
            }
        }
        int right1 = r;
        l = 0;
        r = n;
        while(r-l>1){
            int c = (r+l)/2;
            System.out.println('?' + " 1 1 " + c + " " + n);
            int x = in.nextInt();
            if(x<2){
                l=c;
            }
            else{
                r=c;
            }
        }
        int right2 = r;
        l = 0;
        r = n;
        while(r-l>1){
            int c = (r+l)/2;
            System.out.println('?' + " 1 1 " + n + " " + c);
            int x = in.nextInt();
            if(x==0){
                l=c;
            }
            else{
                r=c;
            }
        }
        int top1 = r;
        l = 0;
        r = n;
        while(r-l>1){
            int c = (r+l)/2;
            System.out.println('?' + " 1 1 " + n + " " + c);
            int x = in.nextInt();
            if(x<2){
                l=c;
            }
            else{
                r=c;
            }
        }
        int top2 = r;
        l = 1;
        r = n+1;
        while(r-l>1){
            int c = (r+l)/2;
            System.out.println('?' + " 1 " + c + " " + n + " " + n);
            int x = in.nextInt();
            if(x==0){
                r=c;
            }
            else{
                l=c;
            }
        }
        int down1 = l;
        l = 1;
        r = n+1;
        while(r-l>1){
            int c = (r+l)/2;
            System.out.println('?' + " 1 " + c + " " + n + " " + n);
            int x = in.nextInt();
            if(x<2){
                r=c;
            }
            else{
                l=c;
            }
        }
        int down2 = l;
        l = 1;
        r = n+1;
        while(r-l>1){
            int c = (r+l)/2;
            System.out.println('?' +  " "+c + " 1 "  + n + " " + n);
            int x = in.nextInt();
            if(x==0){
                r=c;
            }
            else{
                l=c;
            }
        }
        int left1 = l;
        l = 1;
        r = n+1;
        while(r-l>1){
            int c = (r+l)/2;
            System.out.println('?' +  " "+c + " 1 "  + n + " " + n);
            int x = in.nextInt();
            if(x<2){
                r=c;
            }
            else{
                l=c;
            }
        }
        int left2 = l;
        
        
        if(down1>top1 && left1>right1){
            System.out.println('?' +  " "+ left2 + " " +down1  + " " + right1 + " " + top2);
                if(in.nextInt()==1){
                    System.out.println('!' +  " "+ left2 + " " +down1  + " " + right1 + " " + top2+  " "+ left1 + " " +down2  + " " + right2 + " " + top1);
                }
                else{
                    System.out.println('!' +  " "+ left2 + " " +down2  + " " + right1 + " " + top1+  " "+ left1 + " " +down1  + " " + right2 + " " + top2);
                }
                
        }
        else if(down1 > top1){
            System.out.println('?' +  " "+ left1 + " " +down2  + " " + right1 + " " + top2);
            if(in.nextInt()==1){
               System.out.println('?' +  " "+ left1 + " " +down1  + " " + right1 + " " + top2);
                if(in.nextInt()==1){
                System.out.println('!' +  " "+ left1 + " " +down1  + " " + right1 + " " + top2+  " "+ left2 + " " +down2  + " " + right2 + " " + top1);
                }
                else{
                    System.out.println('!' +  " "+ left2 + " " +down1  + " " + right2 + " " + top2+  " "+ left1 + " " +down2  + " " + right1 + " " + top1);
            
                } 
            }
            else{
                System.out.println('?' +  " "+ left1 + " " +down1  + " " + right2 + " " + top2);
                if(in.nextInt()==1){
                    System.out.println('!' +  " "+ left1 + " " +down1  + " " + right2 + " " + top2+  " "+ left2 + " " +down2  + " " + right1 + " " + top1);
                }
                else{
                    System.out.println('!' +  " "+ left2 + " " +down1  + " " + right1 + " " + top2+  " "+ left1 + " " +down2  + " " + right2 + " " + top1);
            
                }
            
            }
        }
        else{
            System.out.println('?' +  " "+ left2 + " " +down1  + " " + right2 + " " + top1);
            if(in.nextInt()==1){
               System.out.println('?' +  " "+ left1 + " " +down1  + " " + right2 + " " + top1);
                if(in.nextInt()==1){
                System.out.println('!' +  " "+ left1 + " " +down1  + " " + right2 + " " + top1+  " "+ left2 + " " +down2  + " " + right1 + " " + top2);
                }
                else{
                    System.out.println('!' +  " "+ left1 + " " +down2  + " " + right2 + " " + top2+  " "+ left2 + " " +down1  + " " + right1 + " " + top1);
            
                } 
            }
            else{
                System.out.println('?' +  " "+ left1 + " " +down1  + " " + right2 + " " + top2);
                if(in.nextInt()==1){
                    System.out.println('!' +  " "+ left1 + " " +down1  + " " + right2 + " " + top2+  " "+ left2 + " " +down2  + " " + right1 + " " + top1);
                }
                else{
                    System.out.println('!' +  " "+ left2 + " " +down1  + " " + right1 + " " + top2+  " "+ left1 + " " +down2  + " " + right2 + " " + top1);
            
                }
            
            }
        }
        
        System.out.flush();
    }
}