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

pll ask(vector <ll> q){
    cout << "?";
    for(auto i : q)cout << " " << i;
    cout << endl;
    pll xe;
    cin >> xe.fi >> xe.se;
    return xe;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    if(k == 1){
        cout << "! 1" << endl;
        return 0;
    }
    vector <ll> ga, gb;
    vector <ll> q;
    for(int i = 1; i <= k; i++)q.p_b(i);

    pll md = ask(q);

    vector <ll> c;

    map <ll, ll> mp;
    mp[md.fi] = md.se;

    for(int i = 0; i < k; i++)if(q[i] != md.fi){
        c.p_b(q[i]);
    }

    q = c;
    q.p_b(k + 1);

    pll kek = ask(q);
    c.clear();
    mp[kek.fi] = kek.se;

    for(int i = 0; i < k; i++)if(q[i] != kek.fi){
        c.p_b(q[i]);
    }

    if(md.se < kek.se){
        ll pos = 1;
        for(int i = 0; i < sz(c); i++){
            q.clear();
            for(int j = 0; j < sz(c); j++)if(i != j)q.p_b(c[j]);
            q.p_b(md.fi);
            q.p_b(kek.fi);
            pll fufel = ask(q);
            if(fufel.fi == kek.fi)pos++;
        }
        cout << "! " << pos << endl;
        return 0;
    }else{
        ll pos = k;
        for(int i = 0; i < sz(c); i++){
            q.clear();
            for(int j = 0; j < sz(c); j++)if(i != j)q.p_b(c[j]);
            q.p_b(md.fi);
            q.p_b(kek.fi);
            pll fufel = ask(q);
            if(fufel.fi == kek.fi)pos--;
        }
        cout << "! " << pos << endl;
        return 0;
    }

    return 0;
}