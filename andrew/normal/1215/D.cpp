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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll sc1, kol1, sc2, kol2;
    sc1 = kol1 = sc2 = kol2 = 0;

    for(int i = 0; i < n; i++){
        if(i < n / 2){
            if(s[i] == '?')kol1++;
            else sc1 += s[i] - '0';
        }else{
            if(s[i] == '?')kol2++;
            else sc2 += s[i] - '0';
        }
    }

    ll k = min(kol1, kol2);
    kol1 -= k;
    kol2 -= k;

    if(kol1 == 0){
        swap(sc1, sc2);
        swap(kol1, kol2);
    }

    if(kol1 == 0){
        if(sc1 == sc2)vout("Bicarp");
        vout("Monocarp");
    }

    if(sc1 >= sc2)vout("Monocarp");

    if(kol1 / 2 * 9 + sc1 != sc2)vout("Monocarp");
    vout("Bicarp");

    return 0;
}