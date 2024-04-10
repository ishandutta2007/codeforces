import java.io.*;
import java.util.*;

public class Main {
    static class InputReader {
        StringTokenizer tokenizer = null;
        BufferedReader reader = null;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch(IOException e) {
                    e.printStackTrace();
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextDouble() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int a = in.nextInt();

        int res;

        if (a % 2 == 0) {
            a = (n + 1 - a);
        }

        out.println((a + 1) / 2);

        out.close();
    }
}