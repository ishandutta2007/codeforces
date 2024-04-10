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
    ll n, m;
    cin >> n >> m;
    string s, s1;
    cin >> s >> s1;
    int kek = s.find("*");

    if(kek == -1){
        if(s == s1)vout("YES");
        vout("NO");
    }

    string ss1, ss2;

    ss1 = s.substr(0, kek);
    ll ku = ss1.size();
    if(s1.size() < ku)vout("NO");
    ss2 = s1.substr(0, ku);
    if(ss1 != ss2)vout("NO");

    s.erase(0, ku + 1);
    s1.erase(0, ku);
    ss1 = s;
    reverse(all(ss1));
    reverse(all(s1));
    ku = ss1.size();
    if(s1.size() < ku)vout("NO");
    ss2 = s1.substr(0, ku);
    if(ss1 != ss2)vout("NO");

    vout("YES");
    return 0;
}