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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    set <pll> s;
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 1, r = n, le = 1, ri = m;
    for(int i = 0; i < k; i++, l += 2, le += 2, ri -= 2, r -= 2){
        for(int j = l; j <= r; j++)s.insert({j, le});
        for(int j = l; j <= r; j++)s.insert({j, ri});

        for(int j = le; j <= ri; j++)s.insert({l, j});
        for(int j = le; j <= ri; j++)s.insert({r, j});
    }
    cout << s.size() << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}