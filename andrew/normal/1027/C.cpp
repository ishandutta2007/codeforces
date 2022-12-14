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


map <ll, ll> mp;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--){
        ld ans = 1e18;
        ll x, y, x1, y1;
        ll mn = 1e18;
        mp.clear();
        ll n;
        cin >> n;
        while(n--){
            ll x;
            cin >> x;
            mp[x]++;
        }
        map <ll, ll> :: iterator it = mp.begin();
        for(; it != mp.end(); ++it){
            ll xx = it -> fi, val = it -> se;
            ld hex1 = xx;
            if(val > 3){
                if(sqr(4 * hex1) / sqr(hex1) < ans){
                    ans = sqr(4 * hex1) / sqr(hex1);
                    x = y = x1 = y1 = xx;
                }
            }
            if(val > 1){
                if(mn != 1e18){
                    ld hex1 = xx, hex2 = mn;
                    if(sqr(2 * (hex1 + hex2)) / (hex1 * hex2) < ans){
                        ans = sqr(2 * (hex1 + hex2)) / (hex1 * hex2);
                        x = y = mn;
                        x1 = y1 = xx;
                    }
                }
                mn = xx;
            }
        }
        mn = 1e18;
        for(it = mp.end(); it != mp.begin();){
            --it;
            ll xx = it -> fi, val = it -> se;
            ld hex1 = xx;
            if(val > 1){
                if(mn != 1e18){
                    ld hex1 = xx, hex2 = mn;
                    if(sqr(2 * (hex1 + hex2)) / (hex1 * hex2) < ans){
                        ans = sqr(2 * (hex1 + hex2)) / (hex1 * hex2);
                        x = y = mn;
                        x1 = y1 = xx;
                    }
                }
                mn = xx;
            }
        }
        cout << x << " " << y << " " << x1 << " " << y1 << "\n";
    }
    return 0;
}