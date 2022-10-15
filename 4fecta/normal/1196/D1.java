/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package d2.rgb.substring.hard.version;

import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.*;

/**
 *
 * @author edwardxiao
 */
public class D2RGBSubstringHardVersion {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        int q = readInt();
        for (; q > 0; q--) {
            int n = readInt(), k = readInt();
            char[] a = read().toCharArray();
            int[] c1 = new int[n]; // each c stores 1 if corect, 0 if not correct; c1 starts r, g, b, respectively
            int[] c2 = new int[n];
            int[] c3 = new int[n];
            //System.out.println(Arrays.toString(a));
            Deque<Integer> q1 = new LinkedList<>();
            Deque<Integer> q2 = new LinkedList<>();
            Deque<Integer> q3 = new LinkedList<>();
            int cnt1 = 0, cnt2 = 0, cnt3 = 0, max1 = 0, max2 = 0, max3 = 0;
            for (int i = 0; i < n; i++) {
                if (i % 3 == 0) {
                    if (a[i] == 'R') {
                        c1[i]++;
                    } else if (a[i] == 'G') {
                        c2[i]++;
                    } else {
                        c3[i]++;
                    }
                } else if (i % 3 == 1) {
                    if (a[i] == 'G') {
                        c1[i]++;
                    } else if (a[i] == 'B') {
                        c2[i]++;
                    } else {
                        c3[i]++;
                    }
                } else {
                    if (a[i] == 'B') {
                        c1[i]++;
                    } else if (a[i] == 'R') {
                        c2[i]++;
                    } else {
                        c3[i]++;
                    }
                }
                if (c1[i] > 0) {
                    cnt1++;
                }
                q1.add(c1[i]);
                if (c2[i] > 0) {
                    cnt2++;
                }
                q2.add(c2[i]);
                if (c3[i] > 0) {
                    cnt3++;
                }
                q3.add(c3[i]);
                if (q1.size() > k) {
                    if (q1.pollFirst() > 0) {
                        cnt1--;
                    }
                }
                if (q2.size() > k) {
                    if (q2.pollFirst() > 0) {
                        cnt2--;
                    }
                }
                if (q3.size() > k) {
                    if (q3.pollFirst() > 0) {
                        cnt3--;
                    }
                }
                max1 = Math.max(max1, cnt1);
                max2 = Math.max(max2, cnt2);
                max3 = Math.max(max3, cnt3);
                //System.out.println(q1);
                //System.out.println(q2);
                //System.out.println(q3);
            }
            //System.out.println(Arrays.toString(c1));
            //System.out.println(Arrays.toString(c2));
            //System.out.println(Arrays.toString(c3));

            println(Math.min(Math.min(k - max1, k - max2), k - max3));
        }
    }

    final private static int BUFFER_SIZE = 1 << 16;
    private static DataInputStream din = new DataInputStream(System.in);
    private static byte[] buffer = new byte[BUFFER_SIZE];
    private static int bufferPointer = 0, bytesRead = 0;
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    public static String readLine() throws IOException {
        byte[] buf = new byte[64]; // line length
        int cnt = 0, c;
        while ((c = Read()) != -1) {
            if (c == '\n') {
                break;
            }
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }

    public static String read() throws IOException {
        byte[] ret = new byte[1000000];
        int idx = 0;
        byte c = Read();
        while (c <= ' ') {
            c = Read();
        }
        do {
            ret[idx++] = c;
            c = Read();
        } while (c != -1 && c != ' ' && c != '\n' && c != '\r');
        return new String(ret, 0, idx);
    }

    public static int readInt() throws IOException {
        int ret = 0;
        byte c = Read();
        while (c <= ' ') {
            c = Read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = Read();
        }
        do {
            ret = ret * 10 + c - '0';
        } while ((c = Read()) >= '0' && c <= '9');

        if (neg) {
            return -ret;
        }
        return ret;
    }

    public static long readLong() throws IOException {
        long ret = 0;
        byte c = Read();
        while (c <= ' ') {
            c = Read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = Read();
        }
        do {
            ret = ret * 10 + c - '0';
        } while ((c = Read()) >= '0' && c <= '9');
        if (neg) {
            return -ret;
        }
        return ret;
    }

    public static double readDouble() throws IOException {
        double ret = 0, div = 1;
        byte c = Read();
        while (c <= ' ') {
            c = Read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = Read();
        }

        do {
            ret = ret * 10 + c - '0';
        } while ((c = Read()) >= '0' && c <= '9');

        if (c == '.') {
            while ((c = Read()) >= '0' && c <= '9') {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg) {
            return -ret;
        }
        return ret;
    }

    private static void fillBuffer() throws IOException {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1) {
            buffer[0] = -1;
        }
    }

    private static byte Read() throws IOException {
        if (bufferPointer == bytesRead) {
            fillBuffer();
        }
        return buffer[bufferPointer++];
    }

    public void close() throws IOException {
        if (din == null) {
            return;
        }
        din.close();
    }

    static void print(Object o) {
        System.out.print(o);
    }

    static void println(Object o) {
        System.out.println(o);
    }

    static void flush() {
        System.out.flush();
    }

    static void println() {
        System.out.println();
    }

    static void exit() throws IOException {
        din.close();
        pr.close();
        System.exit(0);
    }
}