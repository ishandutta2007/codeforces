// h+x - (b- x) = y
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
#define md 1000000007
#define pb push_back
#define ff first
#define ss second
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
using namespace __gnu_pbds;
typedef priority_queue<int, vector<int>, greater<int> > min_pq;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

ll power(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : ((x % m) * p) % m;
}

ll epower(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = epower(x, y / 2);
    p = (p * p);

    return (y % 2 == 0) ? p : (x * p);
}

ll modInverse(ll a, ll m)
{
    return power(a, m - 2, m);
}

// #######################################CODE!!#####################################################
set<int>st;
void solve() {
    int n;
    cin >> n;
    st.clear();
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        st.insert(v);
    }
    string ans = "YES";
    int v = *st.begin();
    st.erase(st.begin());
    while (not st.empty()) {
        if (v + 1 != *st.begin()) {
            ans = "NO";
            break;
        }
        v = *st.begin();
        st.erase(st.begin());
    }
    cout << ans << endl;
}

int main() {
    fio();
    int t;
    cin >> t;
    //t = 1;
    while (t--) {
        solve();
    }
    return 0;
}