using System;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int on = 0;
        int en = 0;
        var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        for(int i = 0; i < n; i++){
           //int a = int.Parse(Console.Read());
            //Console.WriteLine(a[i]);
            if(a[i]%2 == 0)en++;
            else on++;
        }
        if(on < en){
            Console.WriteLine(on);
        }
        else{
            int ans = en;
            on -= en;
            ans += on/3;
            Console.WriteLine(ans);
        }
    }

}