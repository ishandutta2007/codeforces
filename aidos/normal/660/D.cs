using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgoTraining.Codeforces.D_s
{
    
    public class FastScanner : StreamReader
    {
        private string[] _line;
        private int _iterator;

        public FastScanner(Stream stream) : base(stream)
        {
            _line = null;
            _iterator = 0;
        }
        public int NextInt()
        {
            if (_line == null || _iterator >= _line.Length)
            {
                _line = base.ReadLine().Split(' ');
                _iterator = 0;
            }
            if (_line.Count() == 0) throw new IndexOutOfRangeException("Input string is empty");
            return Convert.ToInt32(_line[_iterator++]);
        }
        public long NextLong()
        {
            if (_line == null || _iterator >= _line.Length)
            {
                _line = base.ReadLine().Split(' ');
                _iterator = 0;
            }
            if (_line.Count() == 0) throw new IndexOutOfRangeException("Input string is empty");
            return Convert.ToInt64(_line[_iterator++]);
        }
    }
    class NumberOfParallelogramsECR11
    {
        public static void Main(string[] args)
        {
            using (FastScanner fs = new FastScanner(new BufferedStream(Console.OpenStandardInput())))
            using (StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput())))
            {
                int n = fs.NextInt();
                Point[] points = new Point[n];
                for (int i = 0; i < n; i++)
                {
                    points[i] = new Point { X = fs.NextInt(), Y = fs.NextInt() };
                }
                List<Point> ls = new List<Point>();
                for (int i = 0; i < n; i++)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        Point p = new Point { X = points[j].X + points[i].X, Y = points[j].Y + points[i].Y };
                        ls.Add(p);
                    }
                }
                ls.Sort((x, y) =>x.compareTo(y));
                
                long c = 0;
                for(int i = 0; i < ls.Count; ){
                     int j = i;
                     while(i < ls.Count && ls[i].Equals(ls[j])) i++;
                     long t = i - j;
                     c += t * (t-1);
                }
                writer.WriteLine(c / 2);
            }
        }
    }
    class Point
    {
        public int X;
        public int Y;

        public override bool Equals(object obj)
        {
            Point p = obj as Point;
            return this.X == p.X && this.Y == p.Y;
        }
        public int compareTo(Point p){
             if(p.X == X) {
                  if(Y < p.Y) return -1;
                  if(Y > p.Y) return 1;
                  return 0;
             }
               if(X < p.X) return -1;
               if(X > p.X) return 1;
               return 0;
        }
        public override int GetHashCode()
        {
            int hash = 13;
            hash = (hash * 7) + this.X.GetHashCode();
            hash = (hash * 7) + this.Y.GetHashCode();
            return hash;
        }
    }
}