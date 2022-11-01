using System;
using System.Collections.Generic;

namespace ConsoleApplication1 {
    class MainClass {
        public static void Main(string [] args) {
            const int INF = 2000 * 1000 * 1000 + 10;
            int n = Convert.ToInt32(Console.ReadLine());
            string s = Convert.ToString(Console.ReadLine());
            //int ans1 = INF;
            int c1 = 0, c2 = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'r')
                    if (i % 2 == 0)
                        c1++;
                if (s[i] == 'b')
                    if (i % 2 == 1)
                        c2++;
            }

            int c3 = 0, c4 = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'r')
                    if (i % 2 == 1)
                        c3++;
                if (s[i] == 'b')
                    if (i % 2 == 0)
                        c4++;
            }
            int ans1 = Math.Max(c1, c2);
            int ans2 = Math.Max(c3, c4);
            Console.Write(Math.Min(ans1, ans2));
        }
    }
}