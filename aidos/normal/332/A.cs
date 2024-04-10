using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            solve();
        }
        private static void solve() {
            int n = NextInt(), ans = 0;
            string s = NextToken();
            int x = (int)s.Length;
            for (int i = n; i < x; i = i+n) {
                if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]) ans = ans+1;
            }
            Console.WriteLine("{0}", ans);
        }
        private static string NextToken()
        {
            StringBuilder result = new StringBuilder();
            while (true)
            {
                int c = Console.Read();
                if (c == -1)
                    return result.ToString();
                if (char.IsWhiteSpace((char)c))
                {
                    if (result.Length > 0)
                    {
                        return result.ToString();
                    }
                }
                else
                {
                    result.Append((char)c);
                }
            }
        }

        private static int NextInt()
        {
            return int.Parse(NextToken());
        }
        private static long NextLong()
        {
            return long.Parse(NextToken());
        }
        private static double NextDouble()
        {
            return double.Parse(NextToken());
        }
    }
}