#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T> T nxt(){T a; cin >> a; return a;}

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

string Less(string s){
    if(s.size() % 2)return s;
    string s1 = s.substr(0, s.size() / 2), s2 = s.substr(s.size() / 2);
    s1 = Less(s1), s2 = Less(s2);
    if(s1 + s2 < s2 + s1)return (s1 + s2);
    return (s2 + s1);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s1, s2;
    cin >> s1 >> s2;
    s1 = Less(s1);
    s2 = Less(s2);
    if(s1 != s2)vout("NO");
    cout << "YES\n";
    return 0;
}