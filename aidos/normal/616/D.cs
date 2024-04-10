using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeForces
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = Array.ConvertAll(Console.ReadLine().Split(), Convert.ToInt32);
            int[] a = Array.ConvertAll(Console.ReadLine().Split(), Convert.ToInt32);
            int[] b = new int[1000100];
            int n = arr[0];
            int k = arr[1];
            Fenwick fw = new Fenwick(n);
            int l = 0;
            int ans = 0;
            Tuple<int, int> tp = new Tuple<int, int>(0, 0);
            for (int i = 0; i < n; i++) {
                if (b[a[i]] > 0) {
                    fw.upd(b[a[i]]-1, -1);
                }
                fw.upd(i, 1);
                while (fw.get(l, i) > k) l++;
                b[a[i]] = i + 1;
                if(ans<i - l + 1){
                    ans = i - l + 1;
                    tp = new Tuple<int, int>(l+1, i + 1);
                }
            }
            Console.WriteLine(tp.Item1 + " " + tp.Item2);
        }
    }
    public class Fenwick {
        int[] t;// new int[1000100];
        int limit;
        public Fenwick() {

        }
        public Fenwick(int len)
        {
            limit = len;
            t = new int[len + 10];
        }
        public void upd(int pos, int v) {
            for (; pos < limit; pos |= (pos + 1))
                t[pos] += v;
        }
        int get(int pos) {
            int sum = 0;
            for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
                sum += t[pos];
            return sum;
        }
        public int get(int l, int r) {
            return get(r) - get(l - 1);
        }
    }

}