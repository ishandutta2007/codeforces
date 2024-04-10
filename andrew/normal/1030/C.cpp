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
    ll n;
    cin >> n;
    vector <ll> a(n);
    for(int i = 0; i < n; i++){
        char cc;
        cin >> cc;
        a[i] = cc - '0';
    }
    for(int i = 0; i <= 1000; i++){
        bool fl = 0;
        ll sc = 0, kol = 0;
        for(int j = 0; j < n; j++){
            sc += a[j];
            if(sc == i){sc = 0;kol++;}
            else if(sc > i){
                fl = 1;
                break;
            }
        }
        if(sc == 0 && !fl && kol > 1)vout("YES");
    }
    vout("NO");
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}