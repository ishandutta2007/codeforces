using System;
using System.Collections.Generic;

namespace ConsoleApplication1 {
    class MainClass {
        public static void Main(string [] args) {
            int n = Convert.ToInt32(Console.ReadLine());
            string s = Convert.ToString(Console.ReadLine());
            for (int i = n - 2; i >= 0; i -= 2)
                Console.Write(s[i]);
            for (int i = (n + 1) % 2; i < n; i += 2)
                Console.Write(s[i]);
        }
    }
}