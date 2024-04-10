#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
const long long MOD = 998244353;
int divs[N];
long long inv[N];
bool used[N];

long long modpow(long long a, long long b){
    long long ret = 1;
    while(b){
        if(b & 1){
            ret *= a;
            ret %= MOD;
        }
        b >>= 1;
        a *= a;
        a %= MOD;
    }
    return ret;
}

void init(){
    for(int i = 1; i < N; i++){
        divs[i] = i;
        inv[i] = modpow((long long) i, MOD - 2);
    }
    for(int i = 2; i < N; i++){
        if(divs[i] != i) continue;
        if(i >= 1000) continue;
        for(int j = i * i; j < N; j += i) divs[j] = i;
    }
}

struct jxy{
    int j;
    int x;
    int y;
};

long long ans;
long long inv_;
int nume[N];
int deno[N];
int max_[N];
void dfs(int i, vector<vector<jxy>> &edges, long long now){
    ans += now * inv_ % MOD;
    ans %= MOD;
    for(auto jxy: edges[i]){
        if(used[jxy.j]) continue;
        used[jxy.j] = true;
        int x = jxy.y;
        while(x > 1){
            int d = divs[x];
            if(deno[d] >= 1){
                deno[d]--;
                inv_ *= d;
                inv_ %= MOD;
            }
            else{
                nume[d]++;
                now *= d;
                now %= MOD;
            }
            x /= d;
        }
        
        x = jxy.x;
        while(x > 1){
            int d = divs[x];
            if(nume[d] >= 1){
                nume[d]--;
                now *= inv[d];
                now %= MOD;
            }
            else{
                deno[d]++;
                if(deno[d] > max_[d]) max_[d] = deno[d];
                inv_ *= inv[d];
                inv_ %= MOD;
            }
            x /= d;
        }
        dfs(jxy.j, edges, now);
        
        x = jxy.x;
        while(x > 1){
            int d = divs[x];
            if(deno[d] >= 1){
                deno[d]--;
                inv_ *= d;
                inv_ %= MOD;
            }
            else{
                nume[d]++;
                now *= d;
                now %= MOD;
            }
            x /= d;
        }
        
        x = jxy.y;
        while(x > 1){
            int d = divs[x];
            if(nume[d] >= 1){
                nume[d]--;
                now *= inv[d];
                now %= MOD;
            }
            else{
                deno[d]++;
                if(deno[d] > max_[d]) max_[d] = deno[d];
                inv_ *= inv[d];
                inv_ %= MOD;
            }
            x /= d;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vector<jxy>> edges(n, vector<jxy>());
    for(int i = 0; i < n - 1; i++){
        int ii, j, x, y;
        cin >> ii >> j >> x >> y;
        ii--; j--;
        int g = gcd(x, y);
        x /= g;
        y /= g;
        edges[ii].push_back({j, x, y});
        edges[j].push_back({ii, y, x});
    }
    ans = 0;
    inv_ = 1;
    for(int i = 0; i <= n; i++){
        used[i] = false;
        nume[i + 1] = 0;
        deno[i + 1] = 0;
        max_[i + 1] = 0;
    }
    used[0] = true;
    dfs(0, edges, 1);
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < max_[i]; j++){
            ans *= (long long)i;
            ans %= MOD;
        }
    }
    cout << ans << "\n";
    
}

int main(void){
    init();
    int t;
    cin >> t;
    
    while(t--) solve();
    
}