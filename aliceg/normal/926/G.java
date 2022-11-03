import java.io.*;
import java.util.*;

public class Main
{
   public static void main(String[] args)
   {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int a = 0;
    int b = 0;
    int n = in.nextInt();
    for (int i = 0; i < n; i++){
    	int x = in.nextInt();
    	if (x % 2 == 0)
    		a += 1;
    	else
    		b += 1;
    }
    if (a < b)
	out.println(a + (b - a) / 3);
    else
	out.println(b);	

    out.flush();
   }
}