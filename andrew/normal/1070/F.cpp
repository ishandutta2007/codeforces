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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    ll ans = 0, kol = 0;
    vector <ll> va, vb, vc;
    multiset <ll> mb;
    for(int i = 1; i <= n; i++){
        string s;
        ll x;
        cin >> s >> x;
        if(s == "11"){
            kol++;
            ans += x;
        }
        if(s == "00"){
            mb.insert(x);
        }
        if(s == "10"){
            va.p_b(x);
        }
        if(s == "01"){
            vb.p_b(x);
        }
    }

    ll xe = min(va.size(), vb.size());
    sort(all(va));
    sort(all(vb));
    reverse(all(va));
    reverse(all(vb));

    for(int i = 0; i < xe; i++)ans += va[i];
    for(int i = 0; i < xe; i++)ans += vb[i];

    for(int i = xe; i < va.size(); i++)mb.insert(va[i]);
    for(int i = xe; i < vb.size(); i++)mb.insert(vb[i]);

    for(int i = 0; i < kol; i++){
        if(mb.empty())break;
        ans += *(--mb.end());
        mb.erase(--mb.end());
    }
    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}