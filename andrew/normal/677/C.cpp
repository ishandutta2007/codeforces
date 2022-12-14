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
    string a;
    string con;

    for(char i = '0'; i <= '9'; i++)con += i;
    for(char i = 'A'; i <= 'Z'; i++)con += i;
    for(char i = 'a'; i <= 'z'; i++)con += i;
    con += "-";
    con += "_";
    cin >> a;
    ll n = a.size();
    vector <ll> ans(n);
    ll res = 1;
    for(int i = 0; i < n; i++){
        int x = con.find(a[i]);
        for(int i1 = 0; i1 < 64; i1++)
            for(int j = 0; j < 64; j++)if((i1 & j) == x)ans[i]++;
        ll mod = 1e9 + 7;
        res = (res * ans[i]) % mod;
    }
    cout << res << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}