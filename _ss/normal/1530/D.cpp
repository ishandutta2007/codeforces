#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 2e5 + 10;
int a[N], n, p[N], mark[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) p[i] = mark[i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (!mark[a[i]]) p[i] = a[i], mark[a[i]] = 1;
        }
        int j = 1;
        vi same, dif;
        for (int i = 1; i <= n; ++i)
            if (!p[i])
            {
                while (mark[j]) j++;
                p[i] = j;
                if (p[i] == i) same.eb(i);
                else dif.eb(i);
                j++;
            }
        if ((int)same.size() == 1 && (int)dif.size() == 0)
        {
            for (int i = 1; i < same[0]; ++i)
                if (a[i] == a[same[0]])
                {
                    swap(p[i], p[same[0]]);
                    break;
                }
        }
        else if ((int)same.size() == 1)
        {
            swap(p[same[0]], p[dif[0]]);
        }
        else if (!same.empty())
        {
            int len = same.size(), tmp = p[same[0]];
            for (int i = 0; i < len - 1; ++i) p[same[i]] = p[same[i + 1]];
            p[same.back()] = tmp;
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) res += (a[i] == p[i]);
        cout << res << "\n";
        for (int i = 1; i <= n; ++i) cout << p[i] << " ";
        cout << "\n";
    }
    return 0;
}