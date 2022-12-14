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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string a;
    cin >> a;

    ll k;
    cin >> k;

    ll n = 0, kola = 0, kolb = 0;

    string ans;

    for(int i = 0; i < a.size(); i++){
        if(a[i] == '?')kola++; else
            if(a[i] == '*')kolb++; else n++;
    }


    if(n < k){
        if(!kolb)vout("Impossible");
        for(int i = 0; i < a.size(); i++){
            if(a[i] == '*'){
                while(n < k){
                    ans += ans[ans.size() - 1];
                    n++;
                }
            }else if(a[i] != '?')ans += a[i];
        }

    }else{
        if(kola + kolb < n - k)vout("Impossible");
        for(int i = 0; i < a.size(); i++){
            if(a[i] == '*' || a[i] == '?'){
                if(n > k){
                    n--;
                    ans.erase(ans.size() - 1);
                }
            }else ans += a[i];
        }
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}