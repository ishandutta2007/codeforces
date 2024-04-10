
import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.List;

public class main {
    public static void main(String[] args) throws IOException {
        p867a(
            read()
        );
    }
    
    public static String read() throws IOException{
        ArrayList<Integer> ret = new ArrayList();
        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        buff.readLine();
        return buff.readLine();
        /*String line = buff.readLine();
        String[] ar_s = line.split(" ");
        Integer[] ar = new Integer[ar_s.length];
        int i=0;
        for(String s:ar_s){
            ar[i] = Integer.parseInt(ar_s[i]);
            i++;
        }
        return ar;*/
    }
    
    public static void p71a(ArrayList<String> data){
        for(int i=0;i<data.size();i++){
            String line = data.get(i);
            if(line.length() > 10){
                String gener = "";
                gener+=line.charAt(0);
                gener+=line.length()-2;
                gener+=line.charAt(line.length()-1);
                System.out.println(gener);
            }else{
                System.out.println(line);
            }
        }
    }
    
    public static void p158a(ArrayList<Integer> arr){
        ArrayList<Integer> balls = new ArrayList(arr.subList(2, arr.size()));
        if(balls.size() ==0){
            System.out.println(0);
            return;
        }
        int k = arr.get(1);
        int phd = balls.get(k-1);
        int phd_c = 0;
        for(int i=0;i<balls.size();i++){
            int ths = balls.get(i);
            if(ths>=phd && ths!=0){
                phd_c++;
            }
        }
        
        System.out.println(phd_c);
    }
    
    public static void p118a(String in){
        String ret = in.toLowerCase();
        ret=ret.replaceAll("[aoyeui]", "");
        String nw_ret = "";
        for(int i=0;i<ret.length();i++){
            nw_ret= nw_ret + "." + ret.toCharArray()[i];
        }
        
        System.out.println(nw_ret);
    }
    
    public static void p155a(Integer[] data){
        int record = -1;
        int anti_record = -1;
        int unical=0;
        for(int i=0;i<data.length;i++){
            int th = data[i];
            if(th>record && i!=0){
                record = th;
                unical++;
            }else if(th<anti_record && i!=0){
                anti_record=th;
                unical++;
            }else if(i==0){
                record=th;
                anti_record=th;
            }
        }
        System.out.println(unical);
    }
    public static void p59a(String data){
        int all = data.length();
        int mtt = all/2;
        int big = 0;
        for(Character c:data.toCharArray())
            if(Character.isUpperCase(c))
                big++;
        if(big>mtt){
            $(data.toUpperCase());
        }else{
            $(data.toLowerCase());
        }
    }
    public static void p867a(String data){
        String letters[] = data.split("");
        int ffts = 0;
        int fstf = 0;
        for(int i=1;i<letters.length;i++){
            if("F".equals(letters[i-1]) && "S".equals(letters[i])){
                ffts++;
            }else if("S".equals(letters[i-1]) && "F".equals(letters[i])){
                fstf++;
            }
        }
        if(fstf>ffts)
            $("YES");
        else
            $("NO");
    }
    public static void $(String out){
        System.out.println(out);
    }
    public static void $_(String out){
        System.out.print(out);
    }
}