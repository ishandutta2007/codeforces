#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n;
int x[N];
int a, b;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x[i]);
    }
    sort(x + 1, x + n + 1);
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (x[i] != x[i - 1])
            v.push_back(x[i]);
    }
    scanf("%d%d", &a, &b);
    int i = n;
    int ans = 0;
    while (1)
    {
        if (a == b)
        {
            printf("%d\n", ans);
            return 0;
        }
        vector<int> vv;
        int minu = a - 1;
        for (int i = 0; i < v.size(); ++i)
        {
            if (a - (a % v[i]) < b)
                continue;
            minu = min(minu, a - (a % v[i]));
            vv.push_back(v[i]);
        }
        a = minu;
        v = vv;
        ++ans;
    }
    return 0;
}