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
        String s = in.next();
        boolean[] b = new boolean[26];
        if(s.length()<26){
            System.out.println(-1);
            return;
        }
        boolean happy=false;
        int k;
        for(k=0; k<=s.length()-26&&!happy; k++){
            happy=true;
            for(int i=0; i<26; i++){
                b[i]=true;
            }
            for(int i=0; i<26; i++){
                if(s.charAt(i+k)!='?'){
                    if(b[s.charAt(i+k)-'A']==false){
                        happy=false;
                    }
                    b[s.charAt(i+k)-'A']=false;
                }
            }
        }
        if(!happy){
            System.out.println(-1);
            return;
        }
        k--;
        int j=0;
        for(int i=0; i<k; i++){
            if(s.charAt(i)!='?'){
                System.out.print(s.charAt(i));
            }
            else{
                System.out.print('A');
            }
        }
        for(int i=0; i<26; i++){
            if(s.charAt(i+k)!='?'){
                System.out.print(s.charAt(i+k));
            }
            else{
                while(b[j]==false){
                    j++;
                }
                System.out.print((char)('A'+j));
                b[j]=false;
            }
        }
        for(int i=k+26; i<s.length(); i++){
            if(s.charAt(i)!='?'){
                System.out.print(s.charAt(i));
            }
            else{
                System.out.print('A');
            }
        }
        System.out.println();
        
    }
}