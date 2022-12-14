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

ll c[2][2];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    vector <ll> a(n), b(n);
    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 0; i < n; i++){
        a[i] = s1[i] - '0';
        b[i] = s2[i] - '0';
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++)
        for(int i1 = 0; i1 < 2; i1++){
            ll f, s, f1, s1;
            f = j | i1;
            s = a[i] | b[i];
            f1 = i1 | a[i];
            s1 = j | b[i];
            if(s != s1 || f != f1)ans += c[j][i1];
        }
        c[a[i]][b[i]]++;
    }
    cout << ans << "\n";
    return 0;
}