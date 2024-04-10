#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
int M[2];
struct str{
    int r[2];
    str(int x = 0){
        for(int i = 0; i < 2; ++i)
            r[i] = x;
    }
    str& operator += (str b){
        for(int i = 0; i < 2; ++i)
            r[i] = (r[i]+b.r[i])%M[i];
        return *this;
    }
    friend str operator + (str a, str b){
        return a+=b;
    }
    str& operator -= (str b){
        for(int i = 0; i < 2; ++i)
            r[i] = (r[i]-b.r[i] + M[i])%M[i];
        return *this;
    }
    friend str operator - (str a, str b){
        return a-=b;
    }
    str& operator *= (str b){
        for(int i = 0; i < 2; ++i)
            r[i] = (1LL*r[i]*b.r[i])%M[i];
        return *this;
    }
    friend str operator * (str a, str b){
        return a*=b;
    }
};
bool operator == (str a, str b){
    for(int i = 0; i < 2; ++i)
        if(a.r[i]!=b.r[i])
            return false;
    return true;
}
int n, m , k;
str s[9][9];
int ans = 0;
str a = 0;
void gen(int pos, str now){
    if(pos == k){
        if(now == a)
            ans++;
    }else{
        for(int i = 0; i <= pos; ++i)
            gen(pos+1, now+s[pos][i]);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    M[0] = 1000000007;
    M[1] = 1000000009;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].pb({w, v});
    }
    for(int i = 0; i < n; ++i)
        sort(all(g[i]));
    vector<str> val(n);
    for(int i = 0; i < n; ++i)
        val[i] = rand();
    for(int i = 0; i < k; ++i){
        for(int j = 0; j <= i; ++j){
            for(int v = 0; v < n; ++v){
                if(g[v].size() == i+1)
                    s[i][j] = s[i][j]+val[g[v][j].s];
            }
        }
    }
    for(int i = 0; i < n; ++i)
        a += val[i];
    gen(0, 0);
    cout << ans;
    return 0;
}