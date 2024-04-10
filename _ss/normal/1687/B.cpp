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
int ask(string s)
{
    cout << "? " << s << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<pii> val(m);
    for (int i = 0; i < m; ++i)
    {
        string s;
        for (int j = 0; j < m; ++j) s += '0';
        s[i] = '1';
        val[i] = mp(ask(s), i);
    }
    sort(all(val));
    int res = 0;
    string s;
    for (int j = 0; j < m; ++j) s += '0';
    for (int i = 0; i < m; ++i)
    {
        s[val[i].se] = '1';
        int tmp = ask(s);
        if (tmp != res + val[i].fi) s[val[i].se] = '0';
        else res = tmp;
    }
    cout << "! " << res << endl;
    return 0;
}