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

ll p[26], p1[26];

bool check(){
    for(int i = 0; i < 26; i++)if(p[i] > p1[i])return 0;
    return 1;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll ans = 0;
    string a, b;
    cin >> a >> b;
    if(b.size() > a.size())vout(0);
    ll k = b.size(), n = a.size();
    for(int i = 0; i < k; i++){
        if(a[i] != '?')p[a[i] - 'a']++;
        p1[b[i] - 'a']++;
    }

    for(int i = 0; i < n - k + 1; i++){
        if(check())ans++;
        if(i + 1 == n - k + 1)break;
        if(a[i] != '?')p[a[i] - 'a']--;
        if(a[i + k] != '?')p[a[i + k] - 'a']++;
    }

    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}