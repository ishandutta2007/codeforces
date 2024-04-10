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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("teamwork.in","r",stdin);
    //freopen("balance.in","w",stdout);


    ll n;
    cin >> n;
    ll m = 2 * n - 2;
    vector <string> a(m);
    vector <char> ans(m);

    vector <bool> f(m);

    for(int i = 0; i < m; i++)cin >> a[i];

    for(int i = 0; i < m; i++)if(a[i].size() == n - 1){
        for(int j = 0; j < m; j++)if(j != i && a[j].size() == 1){
            string s = a[i] + a[j];

            string c;

            bool mb = 1;

            for(int i1 = 0; i1 < n - 1; i1++){
                bool fl = 0;
                c += s[i1];

                for(int k = 0; k < m; k++)if(!f[k] && a[k] == c){
                    fl = 1;
                    f[k] = 1;
                    ans[k] = 'P';
                    break;
                }

                if(!fl)mb = 0;

            }

            c.clear();

            for(int i1 = n - 1; i1 > 0; i1--){
                bool fl = 0;
                c = s[i1] + c;

                for(int k = 0; k < m; k++)if(!f[k] && a[k] == c){
                    fl = 1;
                    f[k] = 1;
                    ans[k] = 'S';
                    break;
                }

                if(!fl)mb = 0;
            }

            for(int i1 = 0; i1 < m; i1++)f[i1] = 0;

            if(mb){
                for(int i = 0; i < m; i++)cout << ans[i];
                cout << "\n";
                return 0;
            }

        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}