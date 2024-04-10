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

map <pii, int> mp, mp1;

int ask_and(int i, int j){
    if(i > j)swap(i, j);
    if(mp.find(m_p(i, j)) != mp.end()){
        return mp[m_p(i, j)];
    }
    int x;
    cout << "and " << i + 1 << " " << j + 1 << endl;
    cin >> x;
    mp[m_p(i, j)] = x;
    return x;
}

int ask_or(int i, int j){
    if(i > j)swap(i, j);
    if(mp1.find(m_p(i, j)) != mp1.end()){
        return mp1[m_p(i, j)];
    }
    int x;
    cout << "or " << i + 1 << " " << j + 1 << endl;
    cin >> x;
    mp1[m_p(i, j)] = x;
    return x;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector <ll> ans(n);
    for(int i = 0; i < n; i += 3){
        vector <int> pos;
        int r = min(n - 1, i + 2);
        int l = r - 2;
        for(int j = l; j <= r; j++){
            pos.p_b(j);
        }
        for(int a = 0; a < 3; a++){
            for(int b = a + 1; b < 3; b++){
                ans[pos[a]] |= ask_and(pos[a], pos[b]);
                ans[pos[b]] |= ask_and(pos[a], pos[b]);
            }
        }
        int x = ask_or(pos[0], pos[1]) & ask_or(pos[1], pos[2]);
        x ^= x & ask_and(pos[0], pos[2]);
        ans[pos[1]] |= x;
        ans[pos[0]] |= ask_or(pos[0], pos[1]) ^ ans[pos[1]];
        ans[pos[2]] |= ask_or(pos[2], pos[1]) ^ ans[pos[1]];
    }
    sort(all(ans));
    cout << "finish " << ans[k - 1] << endl;
}

int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    //cin >> t;
    t = 1;

    while(t--){
        solve();
    }

    return 0;
}