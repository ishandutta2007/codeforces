using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            InputReader ir = new InputReader();
            OutputWriter ow = new OutputWriter();
            Task t = new Task(ir, ow);
            t.solve();            
        }
    }
    class Task{
        InputReader ir;
        OutputWriter ow;
        public Task(InputReader i, OutputWriter o) {
            ir = i;
            ow = o;
        }
        public void solve()
        {
            int n = ir.nextInt(), m = ir.nextInt(), k = 0, t = 0, l, r, z;
            for (int i = 0; i < n; i++) {
                z = ir.nextInt();
                if (z == -1) k++;
                else t++;
            }
            if (k > t) k = t;
            for (int i = 0; i < m; i++) {
                l = ir.nextInt();
                r = ir.nextInt();
                z = r - l + 1;
                if (z % 2 == 1 || (z > 2 * k)) ow.println(0);
                else ow.println(1);
            }
                    
        }
    }
    class InputReader {
        int read() { 
            return Console.Read();
        }
        public long nextLong()
        {
            int c = read(), sign = 1;
            while (isWhiteSpace(c))
                c = read();
            long res = 0;
            if (c == '-')
            {
                sign = -1;
                c = read();
            }
            do
            {
                res *= 10;
                res += (c - '0');
                c = read();
            }
            while (!isWhiteSpace(c));
            return res * sign;
        }
        public int nextInt()
        {
            int c = read(), sign = 1, res = 0;
            while (isWhiteSpace(c))
                c = read();
            if (c == '-')
            {
                sign = -1;
                c = read();
            }
            do
            {
                res *= 10;
                res += (c - '0');
                c = read();
            }
            while (!isWhiteSpace(c));
            return res * sign;
        }
        bool isWhiteSpace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t';
        }
        String next()
        {
            StringBuilder s = new StringBuilder();
            int c = read();
            while (isWhiteSpace(c))
                c = read();
            do
            {
                s.Append(c);
                c = read();
            }
            while (isWhiteSpace(c));
            return s.ToString();
        }
        public double nextDouble()
        {
            return Double.Parse(next());
        }
    }
    class OutputWriter {
        
        public void print(Object o) {
            Console.Write(o);            
        }
        public void println(Object o) { 
            Console.WriteLine(o);
        }
    }
}