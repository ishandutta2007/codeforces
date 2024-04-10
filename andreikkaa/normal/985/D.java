//package com.company;

import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static class Task {
        long sum(long from, long to) {
            if(from > to) {
                return 0;
            }

            if(BigInteger.valueOf(from + to).multiply(BigInteger.valueOf(to - from + 1))
                    .divide(BigInteger.valueOf(2)).compareTo(BigInteger.valueOf(Long.MAX_VALUE)) > 0) {
                return Long.MAX_VALUE;
            }

            return BigInteger.valueOf(from + to).multiply(BigInteger.valueOf(to - from + 1))
                    .divide(BigInteger.valueOf(2)).longValueExact();
        }

        long g(long from, long to, long cnt) {
            if(sum(from, to) > cnt) {
                return Long.MAX_VALUE;
            }

            cnt -= sum(from, to);

            if(sum(1, to - 1) > cnt) {
                return Long.MAX_VALUE;
            }

            cnt -= sum(1, to - 1);
            return to - from + to + (cnt + to - 1) / to;
        }

        long f(long cnt, long first) {
            if(first > cnt) {
                return Long.MAX_VALUE;
            }

            long l = first;
            long r = cnt + 1;
            while(l != r) {
                long m = (l + r) / 2;

                if(g(first, m, cnt) == Long.MAX_VALUE) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }

            --l;
            if(l < first) {
                return Long.MAX_VALUE;
            }

            long ans = g(first, l, cnt);
            assert ans != Long.MAX_VALUE;
            return ans;
        }

        void run(Scanner in, PrintWriter out) {
            //for(long n = 1; n <= 100; ++n) {

            long n = in.nextLong();
                long h = in.nextLong();
                //long h = n;

                long l = 1;
                long r = h + 1;

                while (l != r) {
                    long m = (l + r) / 2;

                    if (f(n, m) == Long.MAX_VALUE) {
                        r = m;
                    } else {
                        l = m + 1;
                    }
                }

                out.println(f(n, l - 1));
            //}
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Task().run(in, out);
        out.flush();
    }
}