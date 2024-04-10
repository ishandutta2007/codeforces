import java.util.*;
import java.io.*;
import java.math.BigInteger;


public class Z {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        String s;
        int sum = 0;
        s = "";
        try {
            s = bi.readLine();
        }
        catch (Exception t) {

        }
        int cntQ = 0;
        for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) == '?')
                cntQ++;
        boolean[] use = new boolean[26];
        boolean flagFirst = false;
        if (s.charAt(0) == '?' || ('A' <= s.charAt(0) && s.charAt(0) <= 'Z'))
            flagFirst = true;

        for (int i = 0; i < 26; i++)
            use[i] = false;
    
        for (int i = 0; i < s.length(); i++)
            if ('A' <= s.charAt(i) && s.charAt(i) <= 'Z') {
                int pos = s.charAt(i) - 'A';
                use[pos] = true;
            }
        int cntL = 0;
        for (int i = 0; i < 26; i++)
            if (use[i])
                cntL++;

        BigInteger ans = new BigInteger("1");
        //out.println(cntQ); 
        int cntZero = 0;
        for (int i = 0; i < cntQ; i++) {
            if (flagFirst) {
                //out.println("sjdflasdfasdf\n");
                //out.println(ans.toString());
                ans = ans.multiply(new BigInteger("9"));
                //out.println(ans.toString());
                flagFirst = false;
            }
            else {
                cntZero++;
                //ans = ans.multiply(new BigInteger("10"));
            }
        }

        for (int i = 0; i < cntL; i++) {
            Integer tmp;
            if (i == 0 && flagFirst) {
                tmp = new Integer(9);
                flagFirst = false;
            }
            else {
                tmp = new Integer(10 - i);
            }
            ans = ans.multiply(new BigInteger(tmp.toString()));
        }
        out.print(ans.toString());
        for (int i = 0; i < cntZero; i++)
            out.print('0');
        out.println();
  
    }

    public void run() {
        try {
            //in = new FastScanner(new File(".in"));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new Z().run();
    }
}