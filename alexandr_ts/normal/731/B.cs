using System;
using System.Collections.Generic;

namespace ConsoleApplication1 {
    class MainClass {
        public static void Main(string [] args) {
            int n = Convert.ToInt32(Console.ReadLine());
            string s = Convert.ToString(Console.ReadLine());
            string[] s2 = s.Split(' ');
            int[] a = new int[200001];
            for (int i = 0; i < n; i++)
                a[i] = (Convert.ToInt32(s2[i]));
            for (int i = 0; i < n - 1; i++)
                if (a[i] % 2 == 1 && a[i + 1] == 0)
                {
                    Console.Write("NO");
                    return;
                }
                else if (a[i] % 2 == 1 && a[i + 1] >= 1)
                    a[i + 1]--;
            if (a[n - 1] % 2 == 1)
                Console.Write("NO");
            else
                Console.Write("YES");
        }

        public static void swap(ref int a, ref int b) {
            int c = a;
            a = b;
            b = c;
        }
    }
}