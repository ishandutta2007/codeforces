#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

ll b[5300][5300];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    string a;
    for(int i = '0'; i <= '9'; i++)a += char(i);
    for(int i = 'A'; i <= 'F'; i++)a += char(i);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n / 4; j++){
            char c;
            cin >> c;
            int k = a.find(c);
            for(int i1 = 3; i1 >= 0; i1--){
                if((1ll << i1) & k)b[i][(j - 1) * 4 + 4 - i1] = 1;
            }
        }
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        ll last = b[i][1], kol = 1;
        for(int j = 2; j <= n; j++){
            if(b[i][j] != last){
                if(!ans)ans = kol; else ans = __gcd(ans, kol);
                kol = 0;
            }
            kol++;
            last = b[i][j];
        }
        if(!ans)ans = kol; else ans = __gcd(ans, kol);
    }

    for(int i = 1; i <= n; i++){
        ll last = b[1][i], kol = 1;
        for(int j = 2; j <= n; j++){
            if(b[j][i] != last){
                if(!ans)ans = kol; else ans = __gcd(ans, kol);
                kol = 0;
            }
            kol++;
            last = b[j][i];
        }
        if(!ans)ans = kol; else ans = __gcd(ans, kol);
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}