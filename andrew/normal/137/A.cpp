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

bool f[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string a;
    cin >> a;
    vector <char> b;
    for(auto i : a)b.p_b(i);

    ll ans = 0;
    char cc;
    ll kol = 1;
    ans = 1;
    cc = b.back();
    b.pop_back();
    while(!b.empty()){
        if(kol == 5){
            cc = b.back();
            ans++;
            kol = 1;
        }else{
            if(cc == b.back()){
                kol++;
            }else {
                cc = b.back();
                kol = 1;
                ans++;
            }
        }
        b.pop_back();
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}