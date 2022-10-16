using System;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            string hola=Console.ReadLine();
            int n=Int32.Parse(hola);
            int[] a=new int[n];
            for (int i = 0; i < n; i++)
            {
                string getal = Console.ReadLine();
                a[i]=(getal[0]-'0')*600+(getal[1]-'0')*60+(getal[3]-'0')*10+(getal[4]-'0');
            }
            Array.Sort(a);
            int ho=0;
            for(int i=1; i<n; i++)
            {
              if(ho<a[i]-a[i-1])
                ho=a[i]-a[i-1];
            }
            if(ho<1440+a[0]-a[n-1])
              ho=1440+a[0]-a[n-1];
            ho=ho-1;
            if(ho/60>9&&ho%60>9)
            Console.WriteLine((ho/60)+":"+(ho%60));
            else if(ho/60>9)
            Console.WriteLine((ho/60)+":0"+(ho%60));
            else if(ho%60>9)
            Console.WriteLine("0"+(ho/60)+":"+(ho%60));
            else
            Console.WriteLine("0"+(ho/60)+":0"+(ho%60));
        }
    }
}