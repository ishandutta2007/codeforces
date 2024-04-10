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

int p[N], sz[N];
vector <int> h[N];
bool f[N];

set <int> s[N];
multiset <int> rofl[N];

int get(int x){
    if(p[x] != x)p[x] = get(p[x]);
    return p[x];
}

void unite(int a, int b){
    if(sz[a] > sz[b]){
        swap(a, b);
    }
    a = get(a), b = get(b);
    p[a] = b;
    sz[b] += sz[a];
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= 2 * n; i++){
        p[i] = i;
        sz[i] = 1;
    }

    int m1, m2;
    cin >> m1 >> m2;
    while(m1--){
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    while(m2--){
        int a, b;
        cin >> a >> b;
        unite(n + a, n + b);
    }

    set <int> mul;
    multiset <int> h1;

    for(int i = 1; i <= n; i++){
        rofl[get(n + i)].insert(i);
        h[get(i)].p_b(i);
        h1.insert(get(n + i));
        mul.insert(get(i));
    }

    int ans = 0;
    vector <pii> st;

    while(mul.size() > 0){
        set <int> :: iterator it;
        it = mul.begin();
        int a = *it;
        mul.erase(it);
        for(auto i : h[a]){
            rofl[get(n + i)].erase(i);
            h1.erase(h1.find(get(n + i)));
            f[i] = 1;
        }
        while(h[a].size()){
            int x = h[a].back();
            h[a].pop_back();
            while(!h1.empty() && *h1.begin() != get(n + x)){
                int cl = *h1.begin(), cx = *rofl[cl].begin();
                st.p_b({x, cx});
                int ra, rb;
                ra = get(n + x);
                rb = get(n + cx);
                if(sz[ra] > sz[rb]){
                    for(auto j : rofl[rb]){
                        if(!f[j]){
                            h1.erase(h1.find(get(n + j)));
                            rofl[ra].insert(j);
                            h1.insert(ra);
                        }
                    }
                    rofl[rb].clear();
                    p[rb] = ra;
                }else{
                    for(auto j : rofl[ra]){
                        if(!f[j]){
                            h1.erase(h1.find(get(n + j)));
                            rofl[rb].insert(j);
                            h1.insert(rb);
                        }
                    }
                    rofl[ra].clear();
                    p[ra] = rb;
                }
                mul.erase(get(cx));
                for(auto val : h[get(cx)]){
                    rofl[get(n + val)].erase(val);
                    h1.erase(h1.find(get(n + val)));
                    h[a].p_b(val);
                    f[val] = 1;
                }
            }
            while(!h1.empty() && *--h1.end() != get(n + x)){
                int cl = *--h1.end(), cx = *rofl[cl].begin();
                st.p_b({x, cx});
                mul.erase(get(cx));
                int ra, rb;
                ra = get(n + x);
                rb = get(n + cx);
                if(sz[ra] > sz[rb]){
                    for(auto j : rofl[rb]){
                        if(!f[j]){
                            h1.erase(h1.find(get(n + j)));
                            rofl[ra].insert(j);
                            h1.insert(ra);
                        }
                    }
                    rofl[rb].clear();
                    p[rb] = ra;
                }else{
                    for(auto j : rofl[ra]){
                        if(!f[j]){
                            h1.erase(h1.find(get(n + j)));
                            rofl[rb].insert(j);
                            h1.insert(rb);
                        }
                    }
                    rofl[ra].clear();
                    p[ra] = rb;
                }
                for(auto val : h[get(cx)]){
                    rofl[get(n + val)].erase(val);
                    h1.erase(h1.find(get(n + val)));
                    h[a].p_b(val);
                    f[val] = 1;
                }
            }
        }
    }

    cout << st.size() << "\n";
    for(auto i : st){
        cout << i.fi << " " << i.se << "\n";
    }
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