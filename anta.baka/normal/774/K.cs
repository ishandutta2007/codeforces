using System.IO;
using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var nn = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int n = nn[0];
        String s = Console.ReadLine();
        s = "$$" + s + "$$";
        for(int i = 2; i < n+2; ++i)
        {
            bool cond;
            char c = s[i];
            if (c == 'a' || c == 'i' || c == 'u' || c == 'y') cond = (c != s[i-1]);
            else if (c == 'o' || c == 'e') cond = (c == s[i-1] && c != s[i+1] && c != s[i-2]) || (c != s[i-1]);
            else cond = true;
            if (cond) Console.Write(c);
        }
    }
}