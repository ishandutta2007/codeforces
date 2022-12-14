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

bool is(char a){
    if('a' <= a && a <= 'z')return 1;
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--){
        string s, s1, s2;
        ll x;
        cin >> x;
        cin >> s;
        bool fl = 0;
        bool fl1 = 0;
        ll l = 0, r = x - 1;
        for(int i = 0; i < (x + 1) / 2; i++){
            if(l == r){
                if(s[i] < 'z')s[i]++;
                else s[i]--;
            }else{
                bool fll = 0;
                for(int i1 = -1; i1 < 2; i1++)if(i1 != 0){
                    for(int j = -1; j < 2; j++)if(j != 0)if(is(char(s[l] + i1)) && is(char(s[r] + j)) && char(s[l] + i1) == char(s[r] + j)){
                        fll = 1;
                        s[l] += i1;
                        s[r] += j;
                        break;
                    }
                    if(fll)break;
                }
                if(!fll)fl1 = 1;
            }
            l++;
            r--;
        }
        //cout << s << endl;
        if(fl1){
            cout << "NO\n";
            continue;
        }
        s2 = s;
        reverse(all(s2));
        if(s2 == s)fl = 1;
        if(fl)cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}