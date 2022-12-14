#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e5;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

string a, b;
ll res = 0;
vector <pll> ans;
ll n;

void try_dec(ll pos);
void try_inc(ll pos);

void try_dec(ll pos){
    if(pos == n)vout(-1);
    if(sz(ans) == N){
        for(auto i : ans)cout << i.fi + 1 << " " << i.se << "\n";
        exit(0);
    }
    if(a[pos] == '0'){
        try_inc(pos + 1);
    }
    if(sz(ans) < N)ans.p_b({pos - 1, -1});
    a[pos]--;
    a[pos - 1]--;
}

void try_inc(ll pos){
    if(pos == n)vout(-1);
    if(sz(ans) == N){
        for(auto i : ans)cout << i.fi + 1 << " " << i.se << "\n";
        exit(0);
    }
    if(a[pos] == '9'){
        try_dec(pos + 1);
    }
    if(sz(ans) < N)ans.p_b({pos - 1, 1});
    a[pos]++;
    a[pos - 1]++;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    cin >> n >> a >> b;

    ll Sa, Sb;
    Sa = Sb = 0;
    for(int i = 0; i < n; i++){

        if(i % 2)Sa += a[i] - '0';
        else Sa -= a[i] - '0';

        if(i % 2)Sb += b[i] - '0';
        else Sb -= b[i] - '0';

    }

    if(Sa != Sb || b[0] == '0')vout("-1");

    ll delta = 0;

    for(int i = 0; i < n; i++){
        ll nw = a[i] + delta;
        res += abs(nw - b[i]);
        delta = b[i] - nw;
    }

    cout << res << "\n";

    for(int i = 0; i < n; i++){
        while(a[i] < b[i]){
            try_inc(i + 1);
        }
        while(a[i] > b[i]){
            try_dec(i + 1);
        }
    }

    for(auto i : ans)cout << i.fi + 1 << " " << i.se << "\n";

    return 0;
}