//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
 
#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif
 
#define F first
#define S second
#define MP make_pair
#define PB push_back
 
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
 
const int max_n = 3e5+10, inf = 1000111222;
 
vector<int> reb[max_n];
int p[max_n];
bool used[max_n];
 
int tin[max_n];
int tout[max_n];
int T;
 
bool is_pred(int u,int v)
{
    return tin[u]<=tin[v] && tin[v]<=tout[u];
}
 
map<pii,bool> edge_from_tree;
 
void dfs(int now,int pred)
{
    tin[now]=++T;
    p[now]=pred;
    used[now]=1;
 
    for (auto wh:reb[now]){
        if (!used[wh]){
            edge_from_tree[mp(now,wh)]=1;
            edge_from_tree[mp(wh,now)]=1;
//            cout<<"dfs "<<now<<"-"<<wh<<"\n";
            dfs(wh,now);
        }
    }
    tout[now]=T;
}
 
int ans[max_n];
 
vector<int> answers[max_n];
 
int lol[max_n];
vector<int> reb1[max_n];
int deg[max_n];
int pp2[max_n];
 
void dfs2(int now,int pred)
{
    pp2[now]=pred;
    used[now]=1;
    for (auto wh:reb1[now]){
        if (!used[wh]){
            deg[now]++;
            dfs2(wh,now);
        }
    }
}
 
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        reb[u].pb(v);
        reb[v].pb(u);
    }
 
    dfs(1,-1);
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;i++){
        int u,v;
        scanf("%d%d",&u,&v);
 
        auto mark_ans=[&](int a)
        {
            while (a!=1){
                ans[a]^=1;
                a=p[a];
            }
        };
 
        mark_ans(u);
        mark_ans(v);
 
        vector<int> cur_ans;
        while (!is_pred(u,v)){
            cur_ans.pb(u);
            u=p[u];
        }
        cur_ans.pb(u);
        vector<int> ans_2;
        while (v!=u){
            ans_2.pb(v);
            v=p[v];
        }
        reverse(all(ans_2));
        for (auto j:ans_2){
            cur_ans.pb(j);
        }
        answers[i]=cur_ans;
    }
    int ans_no=0;
    for (int now=1;now<=n;now++){
        for (int wh:reb[now]){
            if (edge_from_tree.count(mp(now,wh)) && ((is_pred(now,wh) && ans[wh]==1) || (is_pred(wh,now) && ans[now]==1))){
                reb1[now].pb(wh);
                reb1[wh].pb(now);
            }
        }
    }
    queue<int> qq;
    memset(used,0,sizeof(used));
    for (int i=1;i<=n;i++){
        if (!reb1[i].empty() && !used[i]){
            dfs2(i,-1);
        }
    }
    for (int i=1;i<=n;i++){
        if (!reb1[i].empty() && deg[i]==0){
            qq.push(i);
        }
    }
    while (!qq.empty()){
        int now=qq.front();
        qq.pop();
 
        int to=pp2[now];
        if (to!=-1){
            if (lol[now]==0){
                ans_no++;
            }
 
            deg[to]--;
            if (deg[to]==0){
                qq.push(to);
            }
            if (lol[to]==1){
                ans_no--;
            }
            lol[to]^=1;
        }
    }
 
    if (ans_no){
        cout<<"NO"<<"\n";
        cout<<ans_no<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
        for (int i=0;i<q;i++){
            cout<<len(answers[i])<<"\n";
            for (auto j:answers[i]){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
}