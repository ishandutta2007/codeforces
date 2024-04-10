#include <iostream>
#include <cstdio>

using namespace std;

const int MAXL = 1e5 + 100;

bool a[2 * MAXL];
int b[200];
int c[200];

int main()
{
   int  d, i, j, k, n, ll, rr, l, q, x, kol;
    bool check;
    cin >> l >> ll >> rr >> n;
    l += rr;
 //   d = max(ll, rr);
    for (i = 0; i < n; i++)
    {
        cin >> q >> x;
        if (q == 1)
        {
            j = 0;
            kol = ll;
          //  kol = 0;
            check = true;
            while(j < l && check)
            {
                if (! a[j])
                    kol++;
                else
                    kol = 0;
                j++;
                if (kol >= ll + x + rr)
                {
                    cout << j - rr - x << "\n";
                    for (k = j - rr - x; k < j - rr; k++)
                        a[k] = true;
                    b[i] = j - rr - x;
                    c[i] = x;
                    check = false;
                }
            }
          /*  if (check && kol >= ll + x)
            {
                cout << l - x << "\n";
                for (k = l; k > j - ll - x; k--)
                {
                    if (k >= 0)
                        a[k] = true;
                }
                b[i] = l - x;
                c[i] = x;
            }
            */if (check)
            {
                cout << -1 << "\n";
                b[i] = -1;
            }
        }
        if (q == 2)
        {
            x--;
            for (j = b[x]; j < b[x] + c[x]; j++)
            {
                a[j] = false;
            }
        }
    }


    return 0;
}