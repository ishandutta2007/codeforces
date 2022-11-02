using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeForces
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] c = { '<', '=', '>' };
Console.WriteLine(c[ConvertString(Console.ReadLine()).CompareTo(ConvertString(Console.ReadLine())) + 1]);
        }
        public static String ConvertString(String a) {
            int n = 1000000 - a.Length;
            StringBuilder b = new StringBuilder();
            for (int i = 0; i < n; i++)
                b.Append('0');
            b.Append(a);
            return b.ToString();
        }
    }
   

}