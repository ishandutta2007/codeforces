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

char tosmall(char a){
    if('a' <= a && a <= 'z')return a;
    a -= 'A';
    a += 'a';
    return a;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    ll sc = 0;
    ll uk = 0;
    vector <ll> a(3);
    while(n--){
        ll x;
        cin >> x;
        a[uk] += x;
        uk = (uk + 1) % 3;
    }
    ll ans = *max_element(all(a));
    if(a[0] == ans)vout("chest");
    if(a[1] == ans)vout("biceps");
    if(a[2] == ans)vout("back");
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}