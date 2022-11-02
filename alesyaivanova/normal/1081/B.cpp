#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
int a[MAX_N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    map<int, int> m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = n - a[i];
        m[a[i]]++;
    }
    bool u = true;
    int cnt = 1;
    map<int, int> num;
    for (auto e = m.begin(); e != m.end(); e++)
    {
        if ((*e).second % (*e).first != 0)
            u = false;
        num.emplace((*e).first, cnt);
        cnt++;
    }
    if (!u)
    {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible\n";
    for (int i = 0; i < n; i++)
    {
        auto e = m.find(a[i]);
        cout << num[a[i]] << " ";
        (*e).second--;
        if ((*e).second % a[i] == 0)
        {
            num[a[i]] = cnt;
            cnt++;
        }
    }
}