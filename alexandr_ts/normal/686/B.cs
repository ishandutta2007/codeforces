using System;
using System.Collections.Generic;

namespace ConsoleApplication1 {
    class MainClass {
        public static void Main(string [] args) {
            int n = Convert.ToInt32(Console.ReadLine());
            string s = Convert.ToString(Console.ReadLine());
            string[] s2 = s.Split(' ');
            int[] a = new int[101];
            for (int i = 0; i < n; i++)
                a[i] = Convert.ToInt32(s2[i]);
            for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - 1 - i; j++)
                    if (a[j] > a[j + 1]) {
                        swap(ref a[j], ref a[j + 1]);
                        Console.WriteLine((j + 1) + " " + (j + 2));
                    }
        }

        public static void swap(ref int a, ref int b) {
            int c = a;
            a = b;
            b = c;
        }
    }
}