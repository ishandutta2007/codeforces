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

ll kol[MAXN], kol1[MAXN], ct, ct1;

vector <ll> v[MAXN], v1[MAXN];
vector <ll> ve, ve1;


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            ct++;
            ve.p_b(i);
        }else{
            kol[s[i] - 'a'];
            v[s[i] - 'a'].p_b(i);
        }
    }

    cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            ct1++;
            ve1.p_b(i);
        }else{
            kol1[s[i] - 'a'];
            v1[s[i] - 'a'].p_b(i);
        }
    }

    vector <pll> ans;

    for(int i = 0; i < 26; i++){
        while(!v[i].empty() && !v1[i].empty()){
            ans.p_b({v[i].back(), v1[i].back()});
            v[i].pop_back();
            v1[i].pop_back();
        }
    }

    for(int i = 0; i < 26; i++){
        while(!v[i].empty() && !ve1.empty()){
            ans.p_b({v[i].back(), ve1.back()});
            v[i].pop_back();
            ve1.pop_back();
        }
    }

    for(int i = 0; i < 26; i++){
        while(!v1[i].empty() && !ve.empty()){
            ans.p_b({ve.back(), v1[i].back()});
            v1[i].pop_back();
            ve.pop_back();
        }
    }

    while(!ve.empty() && !ve1.empty()){
        ans.p_b({ve.back(), ve1.back()});
        ve.pop_back();
        ve1.pop_back();
    }

    cout << ans.size() << "\n";
    for(auto i : ans)cout << i.fi + 1 << " " << i.se + 1 << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}