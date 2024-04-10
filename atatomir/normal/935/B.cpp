#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long


int main()
{
    //freopen("test.in","r",stdin);

    int n, i, ans = 0;
    string s;
    int x, y, last = 0;

    cin >> n >> s;
    x = y = 0;

    for (auto e : s) {
        if (e == 'U') y++;
        else          x++;

        if (x == y) continue;
        if (x < y) {
            if (last != 0 && last != 2) ans++;
            last = 2;
        } else {
            if (last != 0 && last != 1) ans++;
            last = 1;
        }
    }

    cout << ans;






    return 0;
}