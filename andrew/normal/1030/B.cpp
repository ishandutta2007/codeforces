#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

bool fl[1001][1001];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, d;
    cin >> n >> d;
    vector <pll> coord;
    coord.p_b({0, d});
    coord.p_b({n - d, n});
    coord.p_b({n, n - d});
    coord.p_b({d, 0});
    coord.p_b({0, d});
    ll l = d, r = d;
    ll le = -1, re = 1;
    for(int i = 0; i <= n; i++){
        for(int j = l; j <= r; j++)fl[i][j] = 1;
        //cout << i << " " << l << " " << r << "\n";
        l += le, r += re;
        if(l == 0){
            le = 1;
        }
        if(r == n)re = -1;
    }
    ll q;
    cin >> q;
    while(q--){
        ll x, y;
        cin >> x >> y;
        if(fl[x][y])cout << "YES\n"; else cout << "NO\n";
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}