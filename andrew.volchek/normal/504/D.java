import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;



public class Solution {
    public static void main(String[] args) throws Exception {
      //  Scanner in = new Scanner(new BufferedReader(new FileReader("duplicate_sample.in")));
     //   PrintWriter out = new PrintWriter(new File("duplicate_sample.out"));

        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        long start = System.currentTimeMillis();

        solve(in, out);

        long end = System.currentTimeMillis();

        System.err.println("execute time: " + (end - start) / 1000.0);

        in.close();
        out.close();
    }


    static Vector < BitSet > a;
    static Vector < BitSet > marks;


    public static void solve(Scanner in, PrintWriter out) throws Exception {
        int n = in.nextInt();

        a = new Vector<BitSet>(n);
        marks = new Vector<BitSet>(n);

        final int ub = 2200;

        in.nextLine();

        for (int i = 0; i < n; i++) {
            BigInteger x = new BigInteger(in.nextLine());
            String s = x.toString(2);

            BitSet bs = new BitSet(ub);
            for (int j = 0; j < s.length(); j++) {
                bs.set(ub - 1 - (s.length() - 1 - j), s.charAt(j) == '1');
            }

            a.add(bs);

            BitSet ms = new BitSet(ub);
            ms.set(i, true);
            marks.add(ms);
        }


        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < ub && a.get(i).get(j) == false) j++;

            if (j == ub)
            {
                Vector < Integer > ans = new Vector<Integer>();
                for (int h = 0; h < ub; h++) {
                    if (marks.get(i).get(h) && h != i) {
                        ans.add(h);
                    }
                }

                out.print(ans.size());

                for (Integer x : ans) {
                    out.print(" " + x);
                }

                out.print("\n");

                continue;
            }
            else {
                out.print("0\n");
            }

            if (j != i) {
                for (int h = i; h < n; h++) {
                    boolean val = a.get(h).get(i);
                    boolean val2 = a.get(h).get(j);
                    a.get(h).set(i, val2);
                    a.get(h).set(j, val);
                }
            }


            for (int h = i + 1; h < n; h++) {
                if (a.get(h).get(i) == true) {
                    a.get(h).xor(a.get(i));
                    marks.get(h).xor(marks.get(i));
                }
            }
        }
    }


}