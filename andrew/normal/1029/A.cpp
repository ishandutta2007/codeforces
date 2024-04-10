#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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
    ll n, k;
    string s, s1;
    cin >> n >> k;
    cin >> s1;
    s = s1;
    k--;
    while(k--){
        bool fl1 = 0;
        for(int i = n - 1; i > 0; i--){
            ll uk = s.size() - 1;

            bool fl = 0;
            for(int j = i - 1; j >= 0; j--){
                if(s1[j] != s[uk])fl = 1;
                uk--;
            }
            if(!fl){
                string kek = s1.substr(i);
                s += kek;
                fl1 = 1;
                break;
            }
        }
        if(!fl1)s += s1;
    }
    cout << s << endl;
    return 0;
}