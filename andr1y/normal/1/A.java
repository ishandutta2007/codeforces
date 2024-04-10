import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Prob1A {

    public static void main(String[] args) {
        String[] readed = new String[3];
        try {
            readed = read();
        } catch (IOException e) {
            e.printStackTrace();
        }
        Long n = Long.parseLong(readed[0]);
        Long m = Long.parseLong(readed[1]);
        Long a = Long.parseLong(readed[2]);

        if(n%a!=0)
            n = (((n/a)*a)+a)/a;
        else
            n = n/a;

        if(m%a!=0)
            m = (((m/a)*a)+a)/a;
        else
            m= m/a;
        System.out.println(n*m);
    }
    public static String[] read() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        String[] data = line.split(" ");
        return data;
    }
}