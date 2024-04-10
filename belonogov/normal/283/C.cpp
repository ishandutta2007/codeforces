#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define next nexttttt


const int maxn = 2e5 + 10;
const int MOD = 1e9 + 7;

bool in[maxn];
bool use[maxn];
int next[maxn];
int dp[maxn];
int a[maxn];
vector < int > go;
long long t;


void dfs(int v, int sum){
   // epr("%d\n", v);
    use[v] = 1;
   sum += a[v];
    go.pb(sum);
    if (next[v] == -1) return;

    t -= sum;
    dfs(next[v], sum);
}


int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, q, v, u;
    scanf("%d%d%I64d", &n, &q, &t);
    memset(next, -1, sizeof(next));
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < q; i++){
        scanf("%d%d", &v, &u); v--; u--;
        next[v] = u;
        in[u] = 1;
    }
    for(int i = 0; i < n; i++)
        if(!in[i])
            dfs(i, 0);
    for(int i = 0; i < n; i++)
        if (!use[i]){
            cout << "0\n";
            return 0;
        }
    //for(int i = 0; i < (int)go.size(); i++)
    //    epr("%d ", go[i]);
   // epr("\n");
    //epr("t %d\n", t);
    if (t < 0){
        cout << "0\n";
        return 0;
    }
    dp[0] = 1;

    for(int i = 0; i < (int)go.size(); i++){
        for(int k = 0; k + go[i] <= t; k++){
            dp[k + go[i]] += dp[k];
            while (dp[k + go[i]] >= MOD)
                dp[k + go[i]] -= MOD;
        }

    }
    cout << dp[t];


    return 0;
}