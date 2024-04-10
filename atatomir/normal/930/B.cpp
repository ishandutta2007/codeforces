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

#define maxN 5027
#define sigma 26

int n, i;
string s;
int sols;

int us[sigma + 5];

void check(char ch) {
    int i, j, dif, act;
    vector<int> pos = {};
    int ans = 0;


    for (i = 0; i < n; i++)
        if (s[i] == ch)
            pos.pb(i);

    for (dif = 1; dif < n; dif++) {
        memset(us, 0, sizeof(us));

        for (auto p : pos) {
            int id = s[(p + dif) % n] - 'a';
            us[id]++;
        }

        act = 0;
        for (i = 0; i < sigma; i++)
            if (us[i] == 1)
                act++;

        ans = max(ans, act);
    }

    sols += ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> s;
    n = s.size();

    for (char c = 'a'; c <= 'z'; c++)
        check(c);

    double ans = (1.00 * sols) / (1.00 * n);
    printf("%.20lf", ans);

    return 0;
}