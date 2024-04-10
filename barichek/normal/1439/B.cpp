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
 
const int max_n = 1e5+10, inf = 1000111222;
 
bool deleted[max_n];
bool in_q[max_n];
set<int> reb[max_n];
int cnt[max_n];
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<int, int, hash<int>> ht;
 
vector<pii> all_reb;
 
ht lol_set[max_n];
 
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        deleted[i]=0;
        in_q[i]=0;
        reb[i].clear();
        cnt[i]=0;
        lol_set[i].clear();
    }
    all_reb.clear();
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        reb[u].insert(v);
        reb[v].insert(u);
 
        cnt[u]++;
        cnt[v]++;
 
        all_reb.pb(mp(u,v));
        all_reb.pb(mp(v,u));
        
        lol_set[u][v]=1;
        lol_set[v][u]=1;
    }
 
    sort(all(all_reb));
 
    auto have_edge=[&](int u,int v)
    {
        return lol_set[u].find(v)!=lol_set[u].end();
        // auto it = lower_bound(all(all_reb),mp(u,v));
        // if (it!=all_reb.end() && (*it)==mp(u,v)){
        //     return 1;
        // }
        // else{
        //     return 0;
        // }
    };
 
    auto check_for_clique=[&](const set<int>& s)
    {
        vector<int> ss(all(s));
        for (int i=0;i<len(ss);i++){
            for (int j=i+1;j<len(ss);j++){
                if (!have_edge(ss[i],ss[j])){
                    return 0;
                }
            }
        }
        return 1;
    };
 
    auto noone_in_q=[&](const set<int>& s)
    {
        for (auto i:s){
            if (in_q[i]){
                return 0;
            }
        }
        return 1;
    };
 
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (cnt[i]<k){
            q.push(i);
            in_q[i]=1;
        }
        if (cnt[i]==k-1){
            if (noone_in_q(reb[i]) && check_for_clique(reb[i])){
                cout<<2<<"\n";
                cout<<i;
                for (auto j:reb[i]){
                    cout<<" "<<j;
                }
                cout<<"\n";
                return;
            }
        }
    }
 
    while (!q.empty()){
        int now=q.front();
        deleted[now]=1;
        q.pop();
 
        while (!reb[now].empty()){
            int wh=*reb[now].begin();
            reb[now].erase(reb[now].begin());
 
            if (!deleted[wh]){
                reb[wh].erase(now);
                cnt[wh]--;
                if (cnt[wh]==k-1){
                    if (noone_in_q(reb[wh]) && check_for_clique(reb[wh])){
                        cout<<2<<"\n";
                        cout<<wh;
                        for (auto j:reb[wh]){
                            cout<<" "<<j;
                        }
                        cout<<"\n";
                        return;
                    }
                }
 
                if (cnt[wh]==k-1 && !in_q[wh]){
                    q.push(wh);
                    in_q[wh]=1;
                }
            }
        }
    }
 
    for (int i=1;i<=n;i++){
        if (!deleted[i]){
            vector<int> ans;
            for (int j=1;j<=n;j++){
                if (!deleted[j]){
                    ans.pb(j);
                }
            }
 
            cout<<1<<" "<<len(ans)<<"\n";
            for (auto j:ans){
                cout<<j<<" ";
            }
            cout<<"\n";
            return;
        }
    }
 
    cout<<-1<<"\n";
}
 
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int test;
    cin>>test;
    while (test--){
        solve();
    }
}