using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgoTraining.Codeforces.B_s
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
        public string NextToken()
        {
            if (_line == null || _iterator >= _line.Length)
            {
                _line = base.ReadLine().Split(' ');
                _iterator = 0;
            }
            if (_line.Count() == 0) throw new IndexOutOfRangeException("Input string is empty");
            return _line[_iterator++];
        }
        public int NextInt()
        {
            return Convert.ToInt32(NextToken());
        }
        public long NextLong()
        {
            return Convert.ToInt64(NextToken());
        }
        public float NextFloat()
        {
            return float.Parse(NextToken());
        }
        public double NextDouble()
        {
            return Convert.ToDouble(NextToken());
        }
    }
    class ABTask
    {
        public static void Main(string[] args)
        {
            using (FastScanner fs = new FastScanner(new BufferedStream(Console.OpenStandardInput())))
            using (StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput())))
            {
                int l = fs.NextInt();
                int r = fs.NextInt();
                long a = 1;
                int ans = 0;
                for(int i = 0; a <= r; i++){
                    long b = a;
                    for(int j = 0; b <= r; j++){
                        if(l <= b) ans++;
                        b *= 3;
                    }
                    a *= 2;
                }
                 writer.WriteLine(ans);
            }
        }
    }
}