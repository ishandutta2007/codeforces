import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.util.Deque;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
import java.io.BufferedReader;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CBeautifulLyrics solver = new CBeautifulLyrics();
        solver.solve(1, in, out);
        out.close();
    }

    static class CBeautifulLyrics {
        static final String vowels = "aeiou";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String[] s = new String[n];
            for (int i = 0; i < n; i++) {
                s[i] = in.next();
            }

            HashMap<Integer, HashMap<Character, List<CBeautifulLyrics.Word>>> secondWords = new HashMap<>();
            HashMap<Integer, List<CBeautifulLyrics.Word>> firstWords = new HashMap<>();

            for (String cur : s) {
                CBeautifulLyrics.Word w = new CBeautifulLyrics.Word(cur);

                if (!secondWords.containsKey(w.count)) {
                    secondWords.put(w.count, new HashMap<>());
                    firstWords.put(w.count, new ArrayList<>());
                }

                if (!secondWords.get(w.count).containsKey(w.lastVowel)) {
                    secondWords.get(w.count).put(w.lastVowel, new ArrayList<>());
                }

                secondWords.get(w.count).get(w.lastVowel).add(w);
            }

            Deque<CBeautifulLyrics.Word> secondPairs = new ArrayDeque<>();
            for (Map.Entry<Integer, HashMap<Character, List<CBeautifulLyrics.Word>>> e : secondWords.entrySet()) {
                for (Map.Entry<Character, List<CBeautifulLyrics.Word>> e2 : e.getValue().entrySet()) {
                    List<CBeautifulLyrics.Word> bucket = e2.getValue();
                    if (bucket.size() % 2 == 0) {
                        secondPairs.addAll(bucket);
                    } else {
                        secondPairs.addAll(bucket.subList(0, bucket.size() - 1));
                        firstWords.get(e.getKey()).add(bucket.get(bucket.size() - 1));
                    }
                }
            }

            Deque<CBeautifulLyrics.Word> firstPairs = new ArrayDeque<>();
            for (Map.Entry<Integer, List<CBeautifulLyrics.Word>> e : firstWords.entrySet()) {
                List<CBeautifulLyrics.Word> bucket = e.getValue();
                if (bucket.size() % 2 == 0) {
                    firstPairs.addAll(bucket);
                } else {
                    firstPairs.addAll(bucket.subList(0, bucket.size() - 1));
                }
            }

            while (firstPairs.size() < secondPairs.size()) {
                firstPairs.addLast(secondPairs.pollFirst());
                firstPairs.addLast(secondPairs.pollFirst());
            }

            int answer = Math.min(firstPairs.size() / 2, secondPairs.size() / 2);

            out.println(answer);
            for (int i = 0; i < answer; i++) {
                CBeautifulLyrics.Word a = firstPairs.pollFirst(), b = secondPairs.pollFirst(), c = firstPairs.pollFirst(), d = secondPairs.pollFirst();
                assert a.count == c.count;
                assert b.count == d.count;
                assert b.lastVowel == d.lastVowel;
                out.println(a + " " + b);
                out.println(c + " " + d);
            }
        }

        static class Word {
            final String s;
            final int count;
            final char lastVowel;

            Word(String s) {
                this.s = s;
                int count = 0;
                char lastVowel = 'x';
                for (int i = 0; i < s.length(); i++) {
                    char c = s.charAt(i);
                    if (vowels.indexOf(c) >= 0) {
                        count++;
                        lastVowel = c;
                    }
                }

                this.count = count;
                this.lastVowel = lastVowel;
            }

            public String toString() {
                return s;
            }

        }

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