using System;
using System.Collections.Generic;

namespace ConsoleApplication1 {
    class MainClass {
        public static void Main(string [] args) {
            string s = Convert.ToString(Console.ReadLine());
            string[] s2 = s.Split(' ');
            Int64 n = Convert.ToInt64(s2[0]);
            Int64 k = Convert.ToInt64(s2[1]);
            Console.Write(k + n / k * k);
        }
    }
}