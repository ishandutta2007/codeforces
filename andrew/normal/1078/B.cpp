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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

ll kol[1001];

bitset <10011> a[101], b[101];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    set <ll> s;
    ll su = 0;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        s.insert(x);
        kol[x]++;
        su += x;
    }

    if(s.size() < 3)vout(n);

    ll ans = 0;

    for(int i = 1; i <= 100; i++)if(kol[i]){
        for(int j = 1; j <= 100; j++){
                a[j].reset();
        }
        a[0][0] = 1;
        for(int j = 1; j <= 100; j++)if(i != j){
            for(int i1 = 1; i1 <= kol[j]; i1++){
                for(int val = n - kol[i]; val > 0; val--){
                    a[val] |= (a[val - 1] << j);
                }
            }
        }

        for(int j = kol[i]; j > 0; j--){
            bool fl = 0;

            for(int i1 = 0; i1 < j; i1++){
                if(a[j - i1][i * (j - i1)])fl = 1;
            }
            bool flag = 0;
            ll count = n - j, sum = su - j * i;

            for(int i1 = kol[i] - j + 1; i1 <= kol[i]; i1++)if(i1 <= count && i * i1 <= sum){
                if(a[count - i1][sum - i * i1])flag = 1;
            }

            if(!flag || fl == 0)ans = max(ans, ll(j));
        }

    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
/*
9
4 4 4 4 2 1 2 2 11
*/