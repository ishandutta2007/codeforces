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
    string x;
    x = "1";
    ll ans = 0;
    string kek;
    while(n--){
        cin >> kek;
        bool fl = 0;
        if(kek == "0"){
            x = "0";
            break;
        }

        for(int i = 1; i < kek.size(); i++)if(kek[i] != '0')fl = 1;

        if(fl || kek[0] != '1')x = kek;
        else ans += kek.size() - 1;
    }
    cout << x;
    if(x != "0")for(int i = 0; i < ans; i++)cout << 0;
    cout << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}