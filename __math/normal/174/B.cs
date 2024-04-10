using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace csharp
{
    class Program
    {
        static bool check(string[] s)
        {
            if (s.Length < 2) return false;
            if (s[0].Length == 0 || s[0].Length > 8) return false;
            if (s[s.Length - 1].Length == 0 || s[s.Length - 1].Length > 3) return false;
            for (int i = 1; i < s.Length-1; i++)
            {
                if (s[i].Length < 2 || s[i].Length > 11) return false;
            }
            return true;
        }

        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split('.');
            if (!check(s)) { Console.WriteLine("NO"); return; }
            Console.WriteLine("YES");
            for (int i = 0; i < s.Length-1; i++)
            {
                int idx = Math.Max(1,s[i+1].Length - 8);
                s[i] = s[i] + "." + s[i + 1].Substring(0,idx);
                s[i + 1] = s[i + 1].Substring(idx);
            }
            s[s.Length - 2] += s[s.Length - 1];
            for (int i = 0; i < s.Length -1; i++)
            {
                Console.WriteLine(s[i]);
            }
        }
    }
}