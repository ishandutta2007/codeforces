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
    vector <ll> l(n + 1), r(n + 1);
    vector <bool> fl(n + 1);
    vector <ll> ans(n + 1);
    for(int i = 1; i <= n; i++)cin >> l[i];
    for(int i = 1; i <= n; i++)cin >> r[i];
    for(int i = n; i > 0; i--){
        vector <ll> a;
        ll kol = 0;
        for(int j = 1; j <= n; j++)if(!fl[j]){
            kol++;
            if(l[j] == r[j] && !l[j])a.p_b(j);
        }
        if(!kol)break;
        if(a.empty())vout("NO");
        for(auto j : a){
            for(int i1 = 1; i1 < j; i1++)r[i1]--;
            for(int i1 = n; i1 > j; i1--)l[i1]--;
            fl[j] = 1;
            ans[j] = i;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
    cout << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}