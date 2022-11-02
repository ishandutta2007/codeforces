#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

const int MAX_N = 100009;
ld l[MAX_N];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> l[i];
    cin >> s;
    ld gr = 0;
    ld w = 0;
    ld t = 0;
    bool is_water = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
        {
            w += l[i] / 2;
            t += l[i] * 2;
            is_water = true;
        }
        else if (s[i] == 'G')
        {
            ld cur = min(w, l[i] / 2);
            w -= cur;
            t += 4 * cur;
            l[i] -= 2 * cur;
            gr += 2 * cur;
            gr += l[i] / 2;
            t += l[i] * 3;
        }
        else
        {
            t += l[i];
            ld cur = min(w, l[i] / 2);
            w -= cur;
            t += 2 * cur;
            l[i] -= 2 * cur;
            cur = min(gr, l[i] / 2);
            gr -= cur;
            t += 4 * cur;
            l[i] -= 2 * cur;
            if (is_water)
                t += l[i] * 3;
            else
                t += l[i] * 5;
        }
        //cout << w << " " << gr << " " << t << "\n";
    }
    cout << (int)(t + 0.5);
}