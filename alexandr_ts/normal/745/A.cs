using System;

namespace ConsoleApplication1 {
    class MainClass {
        public static void Main (string [] args) {
            string s = Convert.ToString(Console.ReadLine());
            int n = s.Length;
            int answer = 0;
            string[] st = new string[50];
            for (int i = 0; i < n; i++) {
                st[i] = s;
                s = s.Substring(1, n - 1) + s[0];
            }
            for (int i = 0; i < n; i++) {
                bool fnd = false;
                for (int j = 0; j < i; j++)
                    if (st[j] == st[i])
                        fnd = true;
                if (!fnd)
                    answer++;
            }
            Console.WriteLine(answer);
        }
    }
}