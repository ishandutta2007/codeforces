#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

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

bool fl[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie (0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fl['a'] = 1;
    fl['o'] = 1;
    fl['u'] = 1;
    fl['i'] = 1;
    fl['e'] = 1;
    string s;
    cin >> s;
    for(int i = 1; i < s.size(); i++)if(!fl[s[i]] && !fl[s[i - 1]] && s[i - 1] != 'n')vout("NO");
    char c = s.back();
    if(!fl[c] && c != 'n')vout("nO");
    vout("YeS");
    return 0;
}