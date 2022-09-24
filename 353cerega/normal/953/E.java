import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
	static TreeSet<Integer> kek = new TreeSet<Integer>();
	static int n;
	static int[] a = new int[200005];
	static boolean[] eqn = new boolean[200005];
	static boolean[] alive = new boolean[200005];
	static int[] ri = new int[200005];
	static int[] le = new int[200005];
	public static void main (String[] args) throws java.lang.Exception
	{
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		n = in.nextInt();
		for(int i = 0; i < n; i++){
			alive[i] = true;
			eqn[i] = false;
			ri[i] = i + 1;
			le[i] = i - 1;
			a[i] = in.nextInt();
		}
		for(int i = 0; i < n - 1; i++){
			if(a[i] == a[i + 1]){kek.add(n - i); eqn[i] = true;}
		}
		while(!kek.isEmpty()){
			int i = n - kek.last();
			//out.print(i); out.println();
			kek.remove(n - i);
			int j = ri[i];
			int k = le[i];
			eqn[i] = false;
			alive[j] = false;
			eqn[j] = false;
			kek.remove(n - j);
			ri[i] = ri[j];
			le[ri[i]] = i;
			if(k > -1 && eqn[k]){eqn[k] = false; kek.remove(n - k);}
			a[i]++;
			if(k > -1 && a[k] == a[i]){eqn[k] = true; kek.add(n - k);}
			if(ri[i] < n && a[i] == a[ri[i]]){eqn[i] = true; kek.add(n - i);}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++)if(alive[i])cnt++;
		out.print(cnt); out.println();
		for(int i = 0; i < n; i++)if(alive[i]){out.print(a[i]); out.print(' ');}
		out.println();
		out.flush();
	}
	static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}