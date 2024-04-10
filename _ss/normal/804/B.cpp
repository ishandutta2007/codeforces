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
const int mod = 1e9 + 7;
int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int res = 0;
    for (int i = (int)s.length() - 1, cnt = 0; i >= 0; --i)
        if (s[i] == 'b') cnt++;
        else
        {
            res = (res + cnt) % mod;
            cnt = cnt * 2 % mod;
        }
    cout << res;
    return 0;
}