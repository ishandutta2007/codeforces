#include <cstdio>
#include <iostream>

using namespace std;

int n;
string s, ans;
int x, xans;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    xans = -(int)1e+9;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int a, b;
        cin >> a >> b;

        x = a * 100 - b * 50;
        for (int j = 0; j < 5; j++)
        {
            int y;
            cin >> y;
            x += y;
        }

        if (x > xans)
        {
            xans = x;
            ans = s;
        }
    }
    cout << ans << endl;
    return 0;
}