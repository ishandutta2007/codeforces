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

const int max_n = 2e5+10, inf = 1000111222;

int f[30];
vector<int> reb[max_n];
int pos_in_f[max_n];

bool closed_to_go[max_n];
int sz[max_n];
int predok[max_n];
vector<int> visited;

void add_candidate(vector<int>& candidates,int c)
{
    candidates.pb(c);
}

void dfs(int now,int pred,vector<int>& candidates,int all_sz_pos)
{
//    cout<<"dfs :: "<<now<<" "<<pred<<"\n";
    sz[now]=1;
    predok[now]=pred;
    for (auto wh:reb[now]){
        if (wh!=pred){
            if (!closed_to_go[wh]){
                dfs(wh,now,candidates,all_sz_pos);
                sz[now]+=sz[wh];
            }
        }
    }
    if (pos_in_f[sz[now]]==all_sz_pos-1 || pos_in_f[sz[now]]==all_sz_pos-2){
        add_candidate(candidates,now);
    }
}

bool check(int v,int all_sz_pos);

bool get_check(int v,int sz_v,int candidate,int pred_can,int sz_can)
{
    bool flag=rand()&1;

    if (!flag){
        closed_to_go[candidate]=1;
        if (!check(v,pos_in_f[sz_v-sz_can])){
            return 0;
        }
        closed_to_go[candidate]=0;
    }
    else{
        closed_to_go[pred_can]=1;
        if (!check(candidate,pos_in_f[sz_can])){
            return 0;
        }
        closed_to_go[pred_can]=0;
    }

    flag^=1;

    if (!flag){
        closed_to_go[candidate]=1;
        if (!check(v,pos_in_f[sz_v-sz_can])){
            return 0;
        }
        closed_to_go[candidate]=0;
    }
    else{
        closed_to_go[pred_can]=1;
        if (!check(candidate,pos_in_f[sz_can])){
            return 0;
        }
        closed_to_go[pred_can]=0;
    }

    return 1;
}

bool check(int v,int all_sz_pos)
{
//    cout<<"check :: "<<v<<" "<<all_sz_pos<<"\n";
    if (all_sz_pos<=3){
        return 1;
    }
    int sz_v=f[all_sz_pos];
    vector<int> candidates;
    dfs(v,-1,candidates,all_sz_pos);
//    cout<<"candidates :: "<<candidate1<<" "<<candidate2<<"\n";
    random_shuffle(all(candidates));
    vector<int> predoks(0);
    vector<int> szs(0);
    for (auto i:candidates){
        predoks.pb(predok[i]);
        szs.pb(sz[i]);
    }
    for (int i=0;i<len(candidates);i++){
        if (get_check(v,sz_v,candidates[i],predoks[i],szs[i])){
            return 1;
        }
    }
    return 0;
}

const bool debug=0;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    srand(time(0));

    f[1]=1;
    f[2]=1;
    for (int i=3;i<30;i++){
        f[i]=f[i-1]+f[i-2];
    }

    for (int i=2;i<30;i++){
        if (f[i]<max_n){
            pos_in_f[f[i]]=i;
        }
    }

    int n;
    if (debug){
        n=f[25];
        cout<<"nnn :: "<<n<<"\n";
        assert(n<=2e5);
    }
    else{
        scanf("%d",&n);
    }
    for (int i=1;i<n;i++){
        int u,v;
        if (debug){
            u=i;
            v=i+1;
        }
        else{
            scanf("%d%d",&u,&v);
        }
        reb[u].pb(v);
        reb[v].pb(u);
    }
    if (!pos_in_f[n]){
        cout<<"No"<<"\n";
        return 0;
    }

    if (check(1,pos_in_f[n])){
        cout<<"Yes"<<"\n";
    }
    else{
        cout<<"No"<<"\n";
    }
}