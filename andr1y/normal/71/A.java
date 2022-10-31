
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class main {
    public static void main(String[] args) throws IOException {
        p71a(
            read()
        );
    }
    
    public static ArrayList<String> read() throws IOException{
        ArrayList<String> ret = new ArrayList();
        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        String line = buff.readLine();
        int ll = Integer.parseInt(line);
        for(int i=0;i<ll;i++){
            line = buff.readLine();
            ret.add(line);
        }
        
        return ret;
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
}