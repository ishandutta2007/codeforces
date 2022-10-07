#include <iostream>
#include <cstdio>

using namespace std;
int a[3000];
bool use[3000];

int main()
{
   int n, i, res = 0, count = 0;
    cin >> n;
    for (i = 0; i < n; i++)
   {
        cin >> a[i];
        a[i]--;
   }
    while (count < n)
    {
        for (i = 0; i < n; i++)
            if (a[i] == -2 && (! use[i]))
            {
                use[i] = true;
                count++;
            }
        for (i = 0; i < n; i++)
        {
            if (a[i] != -2 && use[a[i]])
                a[i] = -2;
        }
        res++;
    }
    cout << res;

    return 0;
}