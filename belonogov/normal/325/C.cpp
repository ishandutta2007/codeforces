#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
#define plus plusssss

const int maxn = 1e5 + 10;
const int inf = 1e9;
const int INF2 = 314e6;

vector < int > d[maxn];
vector < int > cnt[maxn];
vector < int > sum[maxn];
vector < vector < int > > b[maxn];
vector < pair < int, int > > e[maxn];
set < pair < int, int > > q;
int ansmin[maxn];
bool use[maxn];
int ansmax[maxn];
int cnt2[maxn];

inline int plus(int a, int b){
    return (a + b > INF2) ? INF2 : a + b;
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, v, x, count;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++){
    scanf("%d%d", &v, &count); v--;
    vector < int > temp;
    int diamond = 0;
    for(int j = 0; j < count; j++){
        scanf("%d", &x);
        if (x == -1){
        diamond++;
        continue;
        }
        temp.pb(x - 1);
    }
    d[v].pb(diamond);
    b[v].pb(temp);
    }
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < (int)b[i].size(); j++)
        for(int k = 0; k < (int)b[i][j].size(); k++)
        e[b[i][j][k]].pb(mp(i, j));
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < (int)b[i].size(); j++){
        cnt[i].pb(b[i][j].size());
        sum[i].pb(d[i][j]);
    }
    
    for(int i = 0; i < n; i++)
    ansmin[i] = inf;

    for(int i = 0; i < n; i++){
    int cost = inf;
    for(int j = 0; j < (int)b[i].size(); j++)
        if (b[i][j].size() == 0 && d[i][j] < cost)
        cost = d[i][j];
    if (cost != inf){
        q.insert(mp(cost, i));
        ansmin[i] = cost;
        use[i] = 1;
    }
    }   
//     for(int i = 0; i < n; i++)
//  epr("%d ", ansmin[i]);
//     epr("\n");
    
    while(!q.empty()){
    int v = q.begin()->sc;
    q.erase(q.begin());
    for(int i = 0; i < (int)e[v].size(); i++){
        pair < int, int > pr = e[v][i];
        cnt[pr.fr][pr.sc]--;
        sum[pr.fr][pr.sc] = plus(sum[pr.fr][pr.sc], ansmin[v]);
        if (cnt[pr.fr][pr.sc] == 0 && sum[pr.fr][pr.sc] < ansmin[pr.fr]){
        q.erase(mp(ansmin[pr.fr], pr.fr));
        ansmin[pr.fr] = sum[pr.fr][pr.sc];
        q.insert(mp(ansmin[pr.fr], pr.fr));
        }
    }
    }
    
    for(int i = 0; i < n; i++)
    if (ansmin[i] == inf)
        ansmin[i] = -1;
    ///ansmax
    for(int i = 0; i < n; i++)
    e[i].clear();
    
    for(int i = 0; i < n; i++){
    cnt2[i] = 0;
    for(int j = 0; j < (int)b[i].size(); j++){
        bool flag = 1;
        for(int k = 0; k < (int)b[i][j].size(); k++)
        if (ansmin[b[i][j][k]] == -1)
            flag = 0;
        if (!flag){
        cnt[i][j] = 0;
        sum[i][j] = 0;
        continue;
        }
        cnt2[i]++;
        cnt[i][j] = b[i][j].size();
        sum[i][j] = d[i][j];
        for(int k = 0; k < (int)b[i][j].size(); k++)
        e[b[i][j][k]].pb(mp(i, j));
    }
    }
    

    for(int i = 0; i < n; i++){
    for(int j = 0; j < (int)b[i].size(); j++)
        if (b[i][j].size() == 0)
        cnt2[i]--;
    if (cnt2[i] == 0){
        int cost = 0;
        for(int j = 0; j < (int)b[i].size(); j++)
        cost = max(cost, sum[i][j]);
        ansmax[i] = cost;
        q.insert(mp(cost, i));
    }
    }
//     for(int i = 0; i < n; i++)
//  epr("%d ", ansmax[i]);
//     epr("\n");
    
    while(!q.empty()){
    int v = q.begin()->sc;
    q.erase(q.begin());
    for(int i = 0; i < (int)e[v].size(); i++){
        pair < int, int > pr = e[v][i];
        sum[pr.fr][pr.sc] = plus(sum[pr.fr][pr.sc], ansmax[v]);
        cnt[pr.fr][pr.sc]--;
        if (cnt[pr.fr][pr.sc] == 0)
        cnt2[pr.fr]--;
        if (cnt2[pr.fr] == 0){
        int cost = 0;
        for(int j = 0; j < (int)sum[pr.fr].size(); j++)
            cost = max(cost, sum[pr.fr][j]);
        ansmax[pr.fr] = cost;
        q.insert(mp(cost, pr.fr));
        }
    }
    }
    for(int i = 0; i < n; i++){
    if (ansmin[i] == -1){
        ansmax[i] = -1;
        continue;
    }
    if (ansmax[i] == 0){
        ansmax[i] = -2;
        continue;
    }
    }
    
    for(int i = 0; i < n; i++)
    printf("%d %d\n", ansmin[i], ansmax[i]);
    
       
 
    return 0;
}