#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 

const int maxn = 1e5;
const int inf = (int)1e9;

vector < int > a[maxn];
vector < int > b[maxn];
bool use[maxn];

void dfs(int v){
    int l;
    use[v] = 1;
    for(int i = 0; i < (int)a[v].size(); i++){
        l = a[v][i];
        for(int j = 0; j < (int)b[l].size(); j++)
            if (!use[b[l][j]])
    dfs(b[l][j]);
    }
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, k;
    bool flag = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        if (k) flag = 1;
        a[i].resize(k);
        for(int j = 0; j < k; j++){
            scanf("%d", &a[i][j]); a[i][j]--;
            b[a[i][j]].pb(i);
        }
    }
    if (!flag){
        cout << n << endl;
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
        if (!use[i])
            dfs(i), cnt++;
    cout << cnt - 1 << endl;

    return 0;
}