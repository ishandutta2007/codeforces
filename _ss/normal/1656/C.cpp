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
        int n;
        cin >> n;
        bool one = false;
        set<int> st;
        for (int i = 1, x; i <= n; ++i)
        {
            cin >> x;
            if (x == 1) one = true;
            st.insert(x);
        }
        if (!one)
        {
            cout << "YES\n";
            continue;
        }
        bool check = true;
        for (int x : st)
            if (st.count(x + 1)) check = false;
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}