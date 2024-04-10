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

ll pref[MAXN];

string s;
bool fl[MAXN];
void kek(ll l, ll r){
    string ans = s.substr(l - 1, r - l + 1);
    vout(ans);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    cin >> s;
    string s1;
    ll m = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            m++;
            s1 += s[i];
        }else if(m > 0){
            s1 += s[i];
            m--;
        }
    }
    ll sc = 0;
    string s2 = s1;
    for(int i = s2.size(); i > 0; ){
        i--;
        if(s2[i] == '('){
            if(sc < 1){
                fl[i] = 1;
                sc--;
           }
        }sc++;
    }
    s1.clear();
    for(int i = 0; i < s2.size(); i++)if(!fl[i])s1 += s2[i];
    for(int i = 0; i < s1.size(); i++)fl[i] = 0;
    ll pos = 0;
    ll kol = 0;
    ll bb = s1.size();
    while(bb > k){
        while(s1[kol] == ')' || fl[kol])kol++;
        while(s1[pos] != ')' || fl[pos])pos++;
        fl[pos] = 1;
        fl[kol] = 1;
        bb -= 2;
    }
    string ans;
    for(int i = 0; i < s1.size(); i++)if(!fl[i])ans += s1[i];
    vout(ans);
    return 0;
}