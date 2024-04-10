using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyConsoleApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            solve();
        }
        private static void solve() {
            int n = NextInt(), m = NextInt();
            int[] a = new int[5100], b = new int[5100], t = new int[5100], l = new int[5100], r = new int[5100], d=new int[5100];
            for (int i = 0; i < n; i++)
                a[i] = 1000000000;
            for (int i = 0; i < m; i++) {
                t[i] = NextInt();
                l[i] = NextInt();
                r[i] = NextInt();
                d[i] = NextInt();
                if (t[i] == 1)
                {
                    for (int j = l[i] - 1; j < r[i]; j++)
                        b[j] += d[i];
                }
                else {
                    for (int j = l[i] - 1; j < r[i]; j++)
                        if (d[i] - b[j] < a[j]) a[j] = d[i] - b[j];
                }
            }
            for (int i = 0; i < n; i++)
                b[i] = a[i];
            for (int i = 0; i < m; i++) {
                if (t[i] == 1)
                {
                    for (int j = l[i] - 1; j < r[i]; j++)
                        b[j] += d[i];
                }
                else {
                    int maxn = l[i] - 1;
                    for (int j = l[i]; j < r[i]; j++)
                        if (b[maxn] < b[j]) maxn = j;
                    if (b[maxn] != d[i]) {
                        Console.WriteLine("NO");
                        return;
                    }
                }
            }
            for(int i = 0; i<n; i++)
                if(a[i] > 1000000000 || a[i] < -1000000000){
                    Console.WriteLine("NO");
                    return;
                }
            Console.WriteLine("YES");
            for(int i = 0; i<n; i++)
                Console.Write("{0} ", a[i]);
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
        private static long NextLong() {
            return long.Parse(NextToken());
        }
        private static double NextDouble()
        {
            return double.Parse(NextToken());
        }
    }
}