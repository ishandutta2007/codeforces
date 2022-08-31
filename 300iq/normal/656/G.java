import java.util.*;
public class Main {
public static void main(String[]b) {
Scanner p = new Scanner(System.in);
int n=0,f=p.nextInt(),i=p.nextInt(),t=p.nextInt(),a[]=new int[i],kitten;
for (int k=0;k<f;k++) {
String s=p.next();
for (int j=0;j<i;j++) {
char c=s.charAt(j);
if (c=='Y') 
a[j]++;
}
}
for (int k=0; k<i; k++) 
if (a[k] >= t) 
n++;
System.out.println(n);
}
}