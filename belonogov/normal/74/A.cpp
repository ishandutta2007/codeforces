#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;


int main()
{
   int i, n, m, j, p, res1 = -100500, res, x, ans;
    string s, b[100];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        b[i] = s;
        cin >> p >> m;
        res = p * 100 - m * 50;
        for (j = 0; j < 5; j++)
        {
            cin >> x;
            res += x;
        }
        if (res1 < res)
        {
            res1 = res;
            ans = i;
        }
    }
    cout << b[ans];

    return 0;
}