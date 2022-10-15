#include <bits/stdc++.h>
using namespace std;
#define ll long long
#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "<<#__VA_ARGS__<<"-", _do(__VA_ARGS__)
template<typename T> void _do( T && x) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do( T && x, S&&...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#endif // BALBIT

const int maxn = 1e5+5;
int mo[maxn];
bool np[maxn];

ll nth(ll x, ll n) {
    // returns the floor of x^(1/n) -1
    ll ans = floorl(powl(x,1/(long double)n));
    while (powl(ans, n) > x) -- ans;
    while (powl(ans+1, n) <= x) ++ ans;
    return ans-1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    fill(mo, mo+maxn, 1);
    for (int i = 2; i<100; ++i) {
        if (!np[i]) {
            mo[i] = -mo[i];
            for (int j = i+i; j<100; j+=i) {
                mo[j]=-mo[j];
                np[j] = 1;
            }
            for (int k = i*i; k<100; k+=i*i) {
                mo[k] = 0;
            }
        }
    }

    int T; cin>>T;
    while (T--) {
        ll x; cin>>x;
        ll re = x-1;
        for (int i = 2; i<60; ++i) {
            if (mo[i]) re += mo[i]*nth(x,i);
            // if (i < 5) cout<<"N"<<x<<' '<<i<<' '<<nth(x,i)<<endl;
        }
        cout<<re<<'\n';
    }
}