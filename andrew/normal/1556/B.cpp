#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

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
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const long long mod = 1e9 + 7;
const long long N = 3e5 + 10;


template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll f(vector <int> &a, int x){
    vector <int> b[2];
    for(int i = 0; i < a.size(); i++){
        b[a[i]].p_b(i);
    }
    reverse(all(b[0]));
    reverse(all(b[1]));
    ll s = 0;
    for(int i = 0; i < a.size(); i++, x ^= 1){
        if(b[x].empty()){
            return inf;
        }
        s += max(0, b[x].back() - i);
        b[x].pop_back();
    }
    return s;
}

void solve(){
    int n;
    cin >> n;
    vector <int> a(n);

    for(auto &i : a){
        int x;
        cin >> x;
        i = x % 2;
    }

    long long ans = f(a, 0);
    ans = min(ans, f(a, 1));

    if(ans == inf){
        cout << "-1\n";
    }else{
        cout << ans << "\n";
    }
}

int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    // t = 1;

    while(t--){
        solve();
    }

    return 0;
}