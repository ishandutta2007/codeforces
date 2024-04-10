#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>

using namespace std;

int n, m;
string s;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    cin >> n >> m >> s;
    for (int i = 0; i < n - 1 && m; i++)
        if (0 <= i && s[i] == '4' && s[i + 1] == '7')
        {
            m--;
            s[i] = s[i + 1] = (i & 1)? '7' : '4';
            if (s[i] == '4' && i + 2 < n && s[i + 2] == '7') m %= 2;
            i -= 2;
        }
    cout << s << endl;

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}