using System;
using System.Linq;

public static class Program
{
    public static void Main()
    {
        var nn = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var n = nn[0];
        var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        
        for (int i = 1; i <= n; i++) {
            if (n % i != 0) continue;
            bool b = true;
            int p = 1 - a[0];
            for (int j = 0; j < n; j++) {
                if (j % i == 0) p = 1 - p;
                if (a[j] != p) b = false;
            }
            if (b) {
                Console.WriteLine("YES");
                return;
            }
        }
        
        Console.WriteLine("NO");
    }
}