#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 998244353;
const int N = 1e6 + 200;
//const int N = 100;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve(){
    string s, t;
    cin >> s >> t;

    string rofl;

    for(auto i : s) if(i != 'a' && i != 'b' && i != 'c') rofl += i;

    if(t == "abc"){
        string res;        
        map <char, int> mp;

        for(auto i : s) mp[i]++;
        for(int i = 0; i < mp['a']; i++) res += 'a';
        if(!mp['a']){
            for(int i = 0; i < mp['b']; i++) res += 'b';
            for(int i = 0; i < mp['c']; i++) res += 'c';
        }else{
            for(int i = 0; i < mp['c']; i++) res += 'c';
            for(int i = 0; i < mp['b']; i++) res += 'b';
        }
        sort(all(rofl));
        res += rofl;
        cout << res << "\n";
    }else{
        sort(all(s));
        cout << s << "\n";
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    

    return 0;
}