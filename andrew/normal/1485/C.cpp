#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 2e5;
const int inf = 1e8;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    ll x, y, l, r, mid, ans = 0;
    cin >> x >> y;
    for(ll b = 2; b <= 45000; b++){
        if(b > y)continue;
        l = 0, r = b - 1;
        while(l < r){
            mid = (l + r + 1) >> 1;
            if(mid * (b + 1) <= x)l = mid;
            else r = mid - 1;
        }
        ans += l;
    }
    for(ll c = 1; c <= 45000; c++){
        l = 0, r = y;
        while(l < r){
            mid = (l + r + 1) >> 1;
            if(c * (mid + 1) <= x)l = mid;
            else r = mid - 1;
        }
        ans += max(0LL, l - 45000LL);
    }
    cout << ans << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--){
        solve();
    }
    

    return 0;
}

/*
1
50 3
*/