#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll ans[11][11];

ll Dt[11][11];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    set < pair <ll, ll> > st;

    ll to, val;
    pll xe;

    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++)Dt[i][j] = ll(1e18) + 1;
                st.insert({0ll, i});
                while(!st.empty()){
                    xe = *st.begin();
                    st.erase(st.begin());
                    to = xe.se + x;
                    if(to >= 10)to -= 10;
                    val = xe.fi + 1;
                    if(Dt[i][to] > val){
                        st.erase({Dt[i][to], to});
                        Dt[i][to] = val;
                        st.insert({Dt[i][to], to});
                    }
                    to = xe.se + y;
                    if(to >= 10)to -= 10;
                    val = xe.fi + 1;
                    if(Dt[i][to] > val){
                        st.erase({Dt[i][to], to});
                        Dt[i][to] = val;
                        st.insert({Dt[i][to], to});
                    }
                }
            }
            ll Res = 0;
            ll Last = s[0] - '0';
            for(int i = 1; i < s.size(); i++){
                Res += Dt[Last][s[i] - '0'] - 1;
                if(Res > 1e18)Res = 1e18;
                Last = s[i] - '0';
            }
            ans[x][y] = Res;
            if(ans[x][y] == 1e18)ans[x][y] = -1;
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)cout << ans[i][j] << " ";
        cout << "\n";
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}