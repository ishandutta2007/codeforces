
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class main {
    public static void main(String[] args) throws IOException {
        p118a(
            read()
        );
    }
    
    public static String read() throws IOException{
        ArrayList<Integer> ret = new ArrayList();
        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        
        return buff.readLine();
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
}