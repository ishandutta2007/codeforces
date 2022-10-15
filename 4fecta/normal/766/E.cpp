#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define np(v) next_permutation(v.begin(), v.end())
#define pll pair < long long, long long>
#define all(a) a.begin(), a.end()
#define ull unsigned long long
#define pii pair < int, int >
#define sz(a) (int)a.size()
#define sqr(x) ((x) * (x))
#define y1 stupid_cmath
#define vi vector <int>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

ll n, a[100100], b[100100];
ll cnt[100100][2];
ll sum;
vector <int> g[100100];

void dfs(int v, int pr = -1){
    cnt[v][0] = cnt[v][1] = 0;
    cnt[v][b[v]]++;
    for(int i = 0; i < g[v].size(); ++i){
        int to = g[v][i];
        if(to != pr){
            dfs(to, v);
            sum += cnt[to][0] * cnt[v][1] + cnt[to][1] * cnt[v][0];
            cnt[v][b[v]] += cnt[to][0];
            cnt[v][b[v] ^ 1] += cnt[to][1];
        }
    }
    sum += b[v];
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 2, u, v; i <= n; ++i){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll ans = 0;
    for(int i = 0; i <= 20; ++i){
        sum = 0;
        for(int j = 1; j <= n; ++j){
            if(a[j] & (1 << i)){
                b[j] = 1;
            }else{
                b[j] = 0;
            }
        }
        dfs(1);
        ans += (sum << i);
    }
    cout << ans << endl;
}