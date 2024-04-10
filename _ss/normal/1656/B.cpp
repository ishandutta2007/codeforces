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
        int n, k;
        cin >> n >> k;
        set<int> st;
        for (int i = 1, x; i <= n; ++i) cin >> x, st.insert(x);
        bool check = false;
        for (int x : st)
            if (st.count(k + x))
            {
                check = true;
                break;
            }
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}