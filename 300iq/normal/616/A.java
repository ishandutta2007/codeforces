import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private void solve() throws IOException {
        String a = next();
        String b = next();
        int i = 0;
        int j = 0;
        while (j < a.length() && a.charAt(j) == '0') {
            j++;
        }
        while (i < b.length() && b.charAt(i) == '0') {
            i++;
        }
        if (a.length() - j > b.length() - i) {
            out.println(">");
        }
        else if (a.length() - j < b.length() - i) {
            out.println("<");
        }
        else {
            int lena = a.length();
            int lenb = b.length();
            int t = i;
            i = j;
            j = t;
            try {
                while (a.charAt(i) == b.charAt(j)) {
                    i++;
                    j++;
                }
            } catch (Throwable error) {
                i--; j--;
            }
            if (a.charAt(i) > b.charAt(j)) {
                out.println(">");
            }
            else if (a.charAt(i) < b.charAt(j)) {
                out.println("<");
            }
            else {
                out.println("=");
            }
        }
    }

    private void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        br.close();
        out.close();
    }

    public static void main(String[] args) throws IOException {
	    new Main().run();
    }
}