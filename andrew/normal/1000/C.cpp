#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

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
    set <ll> s;
    map <ll, ll> mp;
    map <ll, ll> mp1;
    vector <ll> res(n + 5);
    ll m = n;
    ll conM = -1e18;
    while(m--){
        ll l, r;
        cin >> l >> r;
        mp[l]++;
        mp[r + 1]--;
        s.insert(l);
        s.insert(r + 1);
    }
    ll last = 0, val = 0;
    for(auto it : s){
        res[val] += it - last;
        val += mp[it];
        last = it;
    }
    for(int i = 1; i <= n; i++)cout << res[i] << " ";
    return 0;
}