import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;
import static java.util.Collections.reverseOrder;
import static java.util.Collections.sort;

public class J {
    private static class BufferedScanner {
        BufferedReader mReader;
        StringTokenizer mTokenizer;

        BufferedScanner(InputStream inputStream) {
            mReader = new BufferedReader(new InputStreamReader(inputStream));
        }
        String next() {
            while (mTokenizer == null || !mTokenizer.hasMoreElements()) {
                String line = readLine();
                if (line != null) {
                    mTokenizer = new StringTokenizer(line);
                } else {
                    break;
                }
            }
            return mTokenizer != null ? mTokenizer.nextToken() : null;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            return readLine();
        }

        private String readLine() {
            try {
                return mReader.readLine();
            } catch (IOException ignore) {
                return null;
            }
        }
    }

    private static InputStream getInputStream() throws IOException {
        InputStream inputStream;
        if (System.getProperty("ONLINE_JUDGE") != null) {
            inputStream = System.in;
        } else {
            File inputFile = new File("input.txt");
            if (!inputFile.exists()) {
                inputFile.createNewFile();
                throw new FileNotFoundException("File wasn't found, but now is created");
            }
            inputStream = new FileInputStream(inputFile);
        }
        return inputStream;
    }

    public static void main(String[] args) throws IOException {
        new J(getInputStream()).solve();
    }

    private BufferedScanner mReader;

    private J(InputStream inputStream) throws IOException {
        mReader = new BufferedScanner(new BufferedInputStream(inputStream));
    }

    private void solve() throws IOException {
        int n = mReader.nextInt();
        PrintWriter out = new PrintWriter(System.out);
        TreeSet<Segment> segments = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            int l = mReader.nextInt();
            int r = mReader.nextInt();
            Segment segment = new Segment(l, r);
            if (segments.isEmpty()) {
                segments.add(segment);
            } else {
                if (segments.first().l > r || segments.last().r < l) {
                    segments.add(segment);
                } else {
                    Segment toDelete;

                    while (true) {
                        toDelete = segments.ceiling(segment);
                        if (toDelete != null && toDelete.l <= r) {
                            l = Math.min(toDelete.l, l);
                            r = Math.max(toDelete.r, r);
                            segments.remove(toDelete);
                        } else {
                            break;
                        }
                    }
                    while (true) {
                        toDelete = segments.floor(segment);
                        if (toDelete != null && toDelete.r >= l) {
                            l = Math.min(toDelete.l, l);
                            r = Math.max(toDelete.r, r);
                            segments.remove(toDelete);
                        } else {
                            break;
                        }
                    }

                    segments.add(new Segment(l, r));
                }
            }
            out.print(segments.size() + " ");
        }
        out.println();
        out.flush();
    }

    private static class Segment implements Comparable<Segment> {
        final int l;
        final int r;

        Segment(int l, int r) {
            this.l = l;
            this.r = r;
        }
        @Override
        public int compareTo(Segment o) {
            return l != o.l ? l - o.l : r - o.r;
        }
    }
}