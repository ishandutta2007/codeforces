#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

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
        if (s.back() != 'B')
        {
            cout << "NO\n";
            continue;
        }
        int cnt = 0;
        bool check = true;
        for (char c : s)
            if (c == 'A') cnt++;
            else
            {
                cnt--;
                if (cnt < 0) check = false;
            }
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}