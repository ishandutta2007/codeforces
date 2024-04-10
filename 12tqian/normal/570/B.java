import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// TASK: Simple Game
public class Problem_570B {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        double n = Integer.parseInt(st.nextToken());
        double m = Integer.parseInt(st.nextToken());
        if(m == 1 && n== 1){
            System.out.println(1);
        }
        else if(m > n/2){
            System.out.println((int)m-1);
        }
        else{
            System.out.println((int)m+1);
        }
        br.close();
        System.exit(0);
    }
}