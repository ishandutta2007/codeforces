

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class A253 {

	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(new File("input.txt"));
        PrintStream out = new PrintStream (new File("output.txt"));
        StringBuffer sb = new StringBuffer ();
        int a = scan.nextInt(), b = scan.nextInt();
        if(a==b){
            for(int i = 0; i < a; i ++){
                sb.append("BG");
            }
        }else if (a>b) {
            for(int i = 0; i < b; i ++){
                sb.append("BG");
            }
            for(int i = 0; i < (a-b); i ++)
                sb.append("B");
        }else {
            for(int i = 0; i < a; i ++){
                sb.append("GB");
            }
            
            for(int i = 0; i < (b-a); i ++)
                sb.append("G");
        }
        out.print(sb.toString());
        out.close();

	}

}