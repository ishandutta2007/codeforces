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
        ll n, x;
        cin >> n >> x;
        multiset<ll> st;
        for (int i = 1, v; i <= n; ++i) cin >> v, st.insert(v);
        int res = 0;
        while (!st.empty())
        {
            ll v = *st.begin();
            st.erase(st.begin());
            if (st.count(v * x)) st.erase(st.find(v * x));
            else res++;
        }
        cout << res << "\n";
    }
    return 0;
}