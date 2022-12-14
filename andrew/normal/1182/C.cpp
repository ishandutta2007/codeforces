#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


map <pll, string> c;

bool fl[1001];

bool f[1000005][26];

vector <pair<string, string>> End, Begin;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    fl['a'] = 1;
    fl['e'] = 1;
    fl['o'] = 1;
    fl['i'] = 1;
    fl['u'] = 1;

    while(n--){
        string s;
        cin >> s;
        ll kol = 0;
        ll last = 0;
        for(auto i : s){
            if(fl[i]){
                last = i - 'a';
                kol++;
            }
        }

        if(!f[kol][last])c[{kol, last}] = s, f[kol][last] = 1;
        else{
            End.p_b({c[{kol, last}], s});
            f[kol][last] = 0;
        }

    }


    string d;

    for(int i = 1; i <= 1e6; i++){
        d.clear();
        for(int j = 0; j < 26; j++)if(f[i][j]){
            if(d.empty())d = c[{i, j}]; else{
                Begin.p_b({d, c[{i, j}]});
                d.clear();
            }
        }
    }

    vector <pair <pair <string, string>, pair <string, string> > > ans;

    ll answer = 0;

    for(int i = 1; i <= End.size(); i++){
        if(Begin.size() + End.size() - i >= i)answer = i;
    }

    if(!answer)vout(0);

    while(End.size() > answer){
        Begin.p_b(End.back());
        End.pop_back();
    }

    for(int i = 0; i < answer; i++){
        ans.p_b({{Begin[i].fi, End[i].fi}, {Begin[i].se, End[i].se}});
    }

    cout << ans.size() << "\n";

    for(auto i : ans)cout << i.fi.fi << " " << i.fi.se << "\n" << i.se.fi << " " << i.se.se << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}