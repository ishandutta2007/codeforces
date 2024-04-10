//package cfgamewithstring;

import java.io.*;
import java.util.*;

public class Cfgamewithstring {
    //Things to check if you don't AC:
    //1. If you get IR, make sure to check the read()/readLine() buffer sizes if String input is long!!!
    //2. Don't forget to change int to long for large Integer input sizes!!!
    //3. Debug code logic/rethink complexity if TLE
    //4. Pad your arrays in case of IR!!!

    public static void main(String[] args) throws IOException {
        int q = readInt();
        main: for (; q > 0; q--) {
            int a = readInt(), b = readInt();
            String s = read();
            ArrayList<Integer> sz = new ArrayList<>();
            s += 'X';
            int len = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '.') {
                    len++;
                } else {
                    if (len > 0) {
                        sz.add(len);
                        len = 0;
                    }
                }
            }
            int x = 2 * b;
            int fair = 0;
            int cnt = 0;
            int seg = -1;
            for (int i : sz) {
                if (i < b) {
                    continue;
                }
                if (i < a && i >= b) { //B always have extra move
                    println("NO");
                    continue main;
                }
                if (i >= x) {
                    cnt++;
                    seg = i;
                }
                if (i >= a && i < x) {
                    fair++;
                }
            }
            if (cnt > 1) {
                println("NO");
                continue;
            }
            if (cnt == 0) {
                if (fair % 2 == 0) {
                    println("NO");
                } else {
                    println("YES");
                }
                continue;
            }
            int flag = 0;
            int tmp;
            for (int i = 0; seg - a - i >= 0; i++) {
                tmp = fair;
                int s1 = i;
                int s2 = seg - a - i;
                //if (s2 < 0) break;
                if (s1 >= a) {
                    tmp++;
                }
                if (s2 >= a) {
                    tmp++;
                }
                if (s1 < a && s1 >= b) continue;
                if (s2 < a && s2 >= b) continue;
                if (s1 >= x || s2 >= x) {
                    continue;
                }
                if (tmp % 2 == 0) {
                    println("YES");
                    flag++;
                    break;
                }
            }
            if (flag == 0) {
                println("NO");
            }
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
        byte[] ret = new byte[400001];
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