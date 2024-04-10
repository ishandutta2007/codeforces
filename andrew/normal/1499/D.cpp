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
const int N = 2e7;
const int M = 1e7;
const int inf = 1e8;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int last[N + 1], cnt[N + 1];

ll res, y, p1, p2, p;

ll f(ll c, ll d, ll x, ll i){
    res = 1;
    y = x + d * i;
    if(y % c)return 0;
    y /= c;
    if(y % i)return 0;

    y /= i;

    return cnt[y];
}

int val;

void solve(){
    ll c, d, x;
    cin >> c >> d >> x;
    ll ans = 0;

    for(int i = 1; i * i <= x; i++)if(x % i == 0){
        ans += f(c, d, x, i);
        if(i * i != x){
            ans += f(c, d, x, x / i);
        }
    }

    cout << ans << "\n";
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    fill(cnt, cnt + N + 1, 1);

    for(ll i = 2; i <= N; i++)if(!last[i]){
        last[i] = i;
        for(ll j = i; j <= N; j += i){
            last[j] = i;
            cnt[j] *= 2;
        }
    }

    int t;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}