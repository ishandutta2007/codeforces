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
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void main_solve(){
    ll n, m;
    cin >> n >> m;
    vector <vector <ll>> a(n + 1);
    for(int i = 1; i <= n; i++){
        a[i].resize(m + 1);
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    ll answer = 0;

    vector <ll> idx(n * m + 2), zp(n * m + 2);
    ll qr = 0;

    for(int j = 1; j <= m; j++){
        ll res = n;
        ++qr;
        vector <ll> cnt(n);
        vector <ll> A(n), B(n);

        for(int i = 0; i < n; i++){
            A[i] = a[i + 1][j];
            B[i] = m * i + j;
            idx[B[i]] = i;
            zp[B[i]] = qr;
        }

        for(int i = 0; i < n; i++)if(A[i] <= n * m && zp[A[i]] == qr){
            ll nw = i, pos = idx[A[i]];
            ll fst = nw - pos;
            if(fst < 0)fst += n;
            if(fst >= n)fst -= n;
            cnt[fst]++;
        }

        for(int i = 0; i < n; i++){
            res = min(res, i + n - cnt[i]);
        }

        answer += res;
    }

    cout << answer << "\n";

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        ll id = 0;
        while(t--){
            cout << "Test number " << ++id << ": \n";
            main_solve();
        }
    #else
        main_solve();
    #endif // LOCAL



    return 0;
}