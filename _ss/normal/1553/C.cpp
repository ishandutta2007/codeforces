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
const int N = 1e5 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int res = 10, d = 0;
        for (int i = 0; i < 10; ++i)
        {
            if (s[i] == '1' || (s[i] == '?' && (i & 1) == 0))
            {
                if (i & 1) d--;
                else d++;
            }
            if (d > (9 - i + 1) / 2)
            {
                res = i + 1;
                break;
            }
        }
        d = 0;
        for (int i = 0; i < 10; ++i)
        {
            if (s[i] == '1' || (s[i] == '?' && (i & 1)))
            {
                if (i & 1) d++;
                else d--;
            }
            if (d > (9 - i) / 2)
            {
                res = min(res, i + 1);
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}