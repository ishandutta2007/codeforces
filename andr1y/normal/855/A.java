
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
import java.util.Random;
import java.util.Scanner;

public class main {
    public static void main(String[] args) throws IOException {
        p855a(
            read()
        );
    }
    
    public static ArrayList<String> read() throws IOException{
        ArrayList<String> ret = new ArrayList();
        Scanner xc = new Scanner(System.in);
        int c_count = xc.nextInt();
        /*String org_name = xc.next();*/
        for(int i=0;i<c_count;i++){
            ret.add(xc.next());
        }
        return ret;
        /*InStack is = new InStack();
        is.name=org_name;
        is.pairs=ret;
        return is;*/
        /*BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        buff.readLine();
        return buff.readLine();*/
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
    public static void p282a(ArrayList<String> data){
        int x=0;
        for(String s:data){
            if(s.startsWith("X")){
                if(s.endsWith("+"))
                    x++;
                else
                    x--;
            }else{
                if(s.startsWith("+"))
                    x++;
                else
                    x--;
            }
        }
        $(x);
    }
    public static void p591b(InStack is){
        String now = is.name;
        for(String pair:is.pairs){
            String[] arr = pair.split(" ");
            String a = arr[0];
            String b = arr[1];
            if(a.equals(b)){
                continue;
            }
            now=now.replaceAll(a, "1");
            now=now.replaceAll(b, "2");
            
            now=now.replaceAll("1", b);
            now=now.replaceAll("2", a);
            /*int thi=0;
            for(String th:now.split("")){
                if(th.equals(a)){
                    now=repAt(now, thi, b.toCharArray()[0]);
                }else if(th.equals(b)){
                    now=repAt(now, thi, a.toCharArray()[0]);
                }
                thi++;
            }*/
        }
        $(now);
    }
    public static void p855a(ArrayList<String> names){
        ArrayList<String> already = new ArrayList<String>();
        for(String n:names){
            if(already.contains(n)){
                $("YES");
            }else{
                $("NO");
            }
            already.add(n);
        }
    }
    public static void gen(){
        Random rndm = new Random();
        String a = "abcdefghijklmnopqrstuvwxyz";
        for(int i=0;i<200000;i++){
            $(a.charAt(rndm.nextInt(a.length())) + " " + a.charAt(rndm.nextInt(a.length())));
        }
    }
    
    
    
    
    public static String repAt(String what, int pos, char byWhat){
        char[] cc = what.toCharArray();
        cc[pos]=byWhat;
        return String.valueOf(cc);
    }
    
    public static void $(String out){
        System.out.println(out);
    }
    public static void $_(String out){
        System.out.print(out);
    }
    public static void $(Integer i){
        $(String.valueOf(i));
    }
    public static void $_(Integer i){
        $_(String.valueOf(i));
    }
    
    
    public static class InStack{
        public String name;
        public ArrayList<String> pairs;
    }
}