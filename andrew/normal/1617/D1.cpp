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

bool ask(vector <int> a){
    cout << "?";
    for(auto i : a) cout << " " << i;
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void solve(){
    int n;
    cin >> n;
    vector <vector <int>> good, bad;

    for(int i = 1; i <= n; i += 3){
        vector <int> arr;
        for(int j = 0; j < 3; j++)arr.p_b(i + j);
        if(ask(arr))good.p_b(arr);
        else{
            bad.p_b(arr);
        }
    }

    vector <int> f(n + 1, -1);

    vector <int> gg = good[0], b = bad[0];    

    bool find = 0;

    vector <int> aa, bb;

    for(int i = 0; i < 3; i++){
        vector <int> arr;
        arr.p_b(b[0]), arr.p_b(b[1]);
        arr.p_b(gg[i]);
        if(ask(arr))aa.p_b(gg[i]); else bb.p_b(gg[i]);
    }

    vector <int> rofl;

    if(aa.empty()){
        f[b[0]] = 0;
        f[b[1]] = 0;
        bb.clear();
        rofl.p_b(b[0]);

        for(int i = 0; i < 3; i++){
            vector <int> arr;
            arr.p_b(gg[1]), arr.p_b(gg[0]);
            arr.p_b(b[i]);
            if(!ask(arr))aa.p_b(b[i]); else bb.p_b(b[i]);
        }

        if(aa.empty()){
            f[gg[0]] = f[gg[1]] = 1;            
            rofl.p_b(gg[0]);
        }else{
            f[gg[2]] = 1;
            rofl.p_b(gg[2]);
        }
    }else{
        rofl.p_b(b[0]);
        rofl.p_b(b[1]);
    }

    for(int i = 1; i <= n; i++){
        if(i == rofl[0] || i == rofl[1]) continue;
        if(f[i] == -1){
            rofl.p_b(i);
            if(ask(rofl)) f[i] = 1;
            else f[i] = 0;
            rofl.pop_back();
        }
    }

    rofl.clear();

    for(int i = 1; i <= n; i++) if(f[i] == 0){
        rofl.p_b(i);
        break;
    }

    for(int i = 1; i <= n; i++) if(f[i] == 1){
        rofl.p_b(i);
        break;
    }

    assert(rofl.size() == 2);

    for(int i = 1; i <= n; i++){
        if(f[i] == -1){
            rofl.p_b(i);
            if(ask(rofl)) f[i] = 1;
            else f[i] = 0;
            rofl.pop_back();
        }
    }
    vector <int> bad_person;
    for(int i = 1; i <= n; i++) if(f[i] == 0){
        bad_person.p_b(i);
    }
    cout << "! " << sz(bad_person);
    for(auto i : bad_person) cout << " " << i;
    cout << endl;
}

int main(){


    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    

    return 0;
}