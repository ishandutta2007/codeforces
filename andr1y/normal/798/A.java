import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Objects;
import java.util.Scanner;

public class Prob798A {

    public static void main(String[] args) {
        String readed = new String();
        try {
            readed = read();
        } catch (IOException e) {
            e.printStackTrace();
        }
        Boolean centered = readed.length()%2==1;
        System.out.print((centered?parseCNTRD(readed):parseDOUBLE(readed))?"YES":"NO");
    }
    public static String read() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        return line;
    }
    public static Boolean parseCNTRD(String str){
        char[] charArr = str.toCharArray();
        Integer index = str.length()/2;
        charArr[index] = ' ';
        String nwStr = new String(charArr);
        nwStr = nwStr.replace(" ", "");

        return parseDOUBLE(nwStr) || checkForTry(str);
    }
    public static Boolean parseDOUBLE(String nwStr){
        boolean rtn = false;
        Integer cngd = 0;
        char[] nwStrCharArr = nwStr.toCharArray();
        char[] firstPartCharArray = Arrays.copyOfRange(nwStrCharArr, 0, nwStrCharArr.length/2);
        char[] secondPartCharArray = Arrays.copyOfRange(nwStrCharArr, nwStrCharArr.length/2, nwStrCharArr.length);
        for(int i=0;i<firstPartCharArray.length;i++){
            char original = firstPartCharArray[i];
            char p2 = secondPartCharArray[secondPartCharArray.length-1-i];
            if(Objects.equals(original, p2)){
                rtn=true;
                continue;
            }
            original = p2;
            firstPartCharArray[i] = p2;
            cngd++;
            rtn=true;
        }
        if(rtn||cngd>1){
            for(int j=0;j<secondPartCharArray.length;j++){
                char original = secondPartCharArray[firstPartCharArray.length-1-j];
                char p2 = firstPartCharArray[j];
                if(Objects.equals(original, p2)){
                    rtn=true;
                    continue;
                }
                original = p2;
                secondPartCharArray[j] = p2;
                donothing();
                cngd++;
                rtn=true;
            }
        }
        return cngd == 1 && rtn;
    }
    public static Boolean checkForTry(String fullstr){
        char[] charArr = fullstr.toCharArray();
        Integer index = fullstr.length()/2;
        charArr[index] = ' ';
        String nwStr = new String(charArr);
        nwStr = nwStr.replace(" ", "");
        char[] nwStrCharArr = nwStr.toCharArray();
        char[] firstPartCharArray = Arrays.copyOfRange(nwStrCharArr, 0, nwStrCharArr.length/2);
        char[] secondPartCharArray = Arrays.copyOfRange(nwStrCharArr, nwStrCharArr.length/2, nwStrCharArr.length);
        return Arrays.equals(firstPartCharArray, reverse(secondPartCharArray));
    }
    public static char[] reverse(char[] data) {
        for (int left = 0, right = data.length - 1; left < right; left++, right--) {
            char temp = data[left];
            data[left]  = data[right];
            data[right] = temp;
        }
        return data;
    }
    private static void donothing(){
        return;
    }
}