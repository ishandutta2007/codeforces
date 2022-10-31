import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Prob4A {

    public static void main(String[] args) {
        String readed = new String();
        String ret = "NO";
        try {
            readed = read();
        } catch (IOException e) {
            e.printStackTrace();
        }
        Long w = Long.parseLong(readed);

        if(w%2==0){
            for(int i=2;i<=w-2;i+=2){
                if(i%2==0&&(w-i)%2==0){
                    ret="YES";
                }
            }
        }
        System.out.print(ret);
    }
    public static String read() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        return line;
    }
}