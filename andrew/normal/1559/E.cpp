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
const long long mod = 998244353;
const long long N = 3e5 + 10;


template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <int> c[N];

vector <int> dp[N], u[N];
int len[N];

void up(int &a, int b){
    a += b;
    if(a >= mod){
        a -= mod;
    }
    if(a < 0){
        a += mod;
    }
}

int func(int n, int x){
    return n / x;
}

int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    int ans = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j * i <= m; j++){
            c[i].p_b(j);
        }
        len[i] = m / i;
        dp[i].resize(len[i] + 10);
        u[i].resize(len[i] + 10);
    }

    vector <int> l(n + 1), r(n + 1);

    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j * i <= m; j++){
            if(l[0] <= i * j && i * j <= r[0])up(dp[i][j], 1);
        }
    }

    for(int i = 1; i < n; i++){
        for(int g = 1; g <= m; g++){
            int le = func(l[i] - 1, g), ri = func(r[i], g);
            int l1, r1;
            if(le == ri){
                for(auto &j : dp[g]){
                    j = 0;
                }
                continue;
            }
            le++;
            for(auto j : c[g]){
                l1 = j + le, r1 = j + ri + 1;
                if(l1 <= len[g]){
                    up(u[g][l1], dp[g][j]);
                }
                if(r1 <= len[g]){
                    up(u[g][r1], -dp[g][j]);
                }
            }
            int s = 0;
            for(auto j : c[g]){
                up(s, u[g][j]);
                dp[g][j] = s;
                u[g][j] = 0;
            }
        }
    }
    
    vector <int> answer(m + 1);

    for(int i = m; i > 0; i--){
        answer[i] = 0;
        for(auto j : c[i]){
            up(answer[i], dp[i][j]);
        }
        for(int j = 2 * i; j <= m; j += i){
            up(answer[i], -answer[j]);
        }
    }

    cout << answer[1] << "\n";

    return 0;
}