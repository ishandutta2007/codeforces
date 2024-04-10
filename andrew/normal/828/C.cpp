#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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

set <ll> ans;
multiset <ll> mb;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("flag.in","r",stdin);
    //freopen("flag.out","w",stdout);
    ll n;
    cin >> n;
    vector <string> a(n);
    vector <vector <ll> > v(n);

    ll N = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        ll x;
        cin >> x;
        ll ChtoTiTutDelaesh = a[i].size();
        while(x--){
            ll pos;
            cin >> pos;
            pos--;
            N = max(N, pos + ChtoTiTutDelaesh);
            v[i].p_b(pos);
        }
    }
    vector <char> ans(N);
    vector <pll> b(N);
    for(int i = 0; i < N; i++)mb.insert(i);
    for(int i = 0; i < n; i++){
        for(auto j : v[i]){
            if(a[i].size() > b[j].fi){
                b[j].fi = a[i].size();
                b[j].se = i;
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(ans[i] == 0){
                ans[i] = 'a';
        }
        if(b[i].fi != 0){
            ll l = i, r = b[i].fi + i - 1;
            set <ll> :: iterator it = mb.lower_bound(l);
            while(it != mb.end() && *it <= r){
                ll pos = *it;
                ans[pos] = a[b[i].se][pos - i];
                mb.erase(pos);
                it = mb.lower_bound(pos);
            }

        }
    }

    for(auto i : ans)cout << i;
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}