//package com.company;

import java.io.*;
import java.util.*;


public class Main {
    class FastScanner {
        BufferedReader br;
        StringTokenizer stok;

        FastScanner(FileInputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String nextToken() throws IOException {
            while (stok == null || !stok.hasMoreTokens()) {
                String s = br.readLine();
                if (s == null) {
                    return null;
                }
                stok = new StringTokenizer(s);
            }
            return stok.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        long nextLong() throws IOException {
            return Long.parseLong(nextToken());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(nextToken());
        }

        char nextChar() throws IOException {
            return (char) (br.read());
        }

        String nextLine() throws IOException {
            return br.readLine();
        }
    }
    private void run() throws IOException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        long n, m;
        n = in.nextLong();
        m = in.nextLong();
        Map <Integer, Integer> a = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            int k = in.nextInt();
            if (a.containsKey(k)) {
                a.put(k, a.get(k) + 1);
            }
            else {
                a.put(k, 1);
            }
        }
        long k = (n * (n - 1)) / 2;
        for (int i = 1; i <= m; i++) {
            long t = a.get(i);
            k -= (t * (t - 1)) / 2;
        }
        out.println(k);
        out.close();
    }
    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}