#include <bits/stdc++.h>
using namespace std;

const int t[7] = {1, 2, 3, 1, 3, 2, 1};

int aa, bb, cc;
int main()
{
    cin >> aa >> bb >> cc;
    int ans = 0;
    for (int i = 0; i < 7; ++i)
    {
        int a = aa;
        int b = bb;
        int c = cc;
        for (int j = i; j < 7; ++j)
        {
            if (t[j] == 1)
                --a;
            else if (t[j] == 2)
                --b;
            else
                --c;
            if (a < 0 || b < 0 || c < 0)
                break;
            ans = max(ans, j - i + 1);
        }
        if (a < 0 || b < 0 || c < 0)
            continue;
        int yans = 7 - i;
        int s = min(a / 3, min(b / 2, c / 2));
        yans += s * 7;
        a -= s * 3;
        b -= s * 2;
        c -= s * 2;
        for (int j = 0; j < 7; ++j)
        {
            if (t[j] == 1)
                --a;
            else if (t[j] == 2)
                --b;
            else
                --c;
            if (a < 0 || b < 0 || c < 0)
                break;
            yans++;
        }
        ans = max(ans, yans);
    }
    cout << ans << endl;
    return 0;
}