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
        int n, m;
        n = in.nextInt();
        m = in.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        int cur = n;
        int k = 0;
        while (m > 0) {
            cur--;
            k++;
            m -= a[cur];
        }
        out.println(k);
        out.close();
    }
    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}