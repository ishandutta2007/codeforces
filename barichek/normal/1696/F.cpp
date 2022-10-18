//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4")

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

#if __APPLE__
#define D for (bool _FLAG = true; _FLAG; _FLAG = false)
#define LOG(...) print(#__VA_ARGS__" ::", __VA_ARGS__) << endl
template <class ...Ts> auto &print(Ts ...ts) { return ((cerr << ts << " "), ...); }
#else
#define D while (false)
#define LOG(...)
#endif

const int max_n = 100+2, inf = 1000111222;

vector<int> reb[max_n];
int d[max_n][max_n];
bitset<max_n> not_used;
string s[max_n][max_n];
bitset<max_n> goods[max_n][max_n];

void set_edge(int u,int v)
{
    reb[u].pb(v);
    reb[v].pb(u);
}

void dfs(int now,int pred)
{
    not_used[now]=0;
    while (1){
        int go=(not_used&goods[now][pred])._Find_first();
        if (go!=max_n){
            set_edge(now,go);
            dfs(go,now);
        }
        else{
            break;
        }
    }
}

void dfs_d(int start,int now,int pred,int dist)
{
    d[start][now]=dist;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs_d(start,wh,now,dist+1);
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            goods[i][j].reset();
        }
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            cin>>s[i][j];
            for (int k=0;k<n;k++){
                if (s[i][j][k]=='1'){
                    goods[k][i][j]=1;
                    goods[k][j][i]=1;
                }
            }
        }
    }
    vector<int> guys;
    for (int i=0;i<n;i++){
        guys.pb(i);
    }

    for (int b=1;b<n;b++){
        not_used.reset();
        for (int i=0;i<n;i++){
            not_used[i]=1;
            reb[i].clear();
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                d[i][j]=inf;
            }
        }

        set_edge(0,b);
        not_used[0]=0;
        not_used[b]=0;
        dfs(0,b);
        dfs(b,0);
        bool ok=1;
        for (int i=0;i<n;i++){
            if (not_used[i]){
                ok=0;
                break;
            }
        }
        if (ok){
            // cout<<"ok :: "<<0<<" "<<b<<"\n";
            for (int i=0;i<n;i++){
                dfs_d(i,i,-1,0);
            }

            bool is_ok_tree=1;
            random_shuffle(all(guys));
            for (auto i:guys){
                if (!is_ok_tree){
                    break;
                }
                for (int j=i+1;j<n && is_ok_tree;j++){
                    for (int k=0;k<n;k++){
                        is_ok_tree&=(1 ^ (s[i][j][k]=='1') ^ (d[i][k]==d[j][k]));
                        // if (!(1 ^ (s[i][j][k]=='1') ^ (d[i][k]==d[j][k]))){
                        //     cout<<d[i][k]<<" "<<d[j][k]<<"\n";
                        //     cout<<i<<" "<<j<<" "<<k<<"\n";
                        // }
                    }
                }
            }
            if (is_ok_tree){
                cout<<"Yes"<<"\n";
                for (int i=0;i<n;i++){
                    for (int j=i+1;j<n;j++){
                        if (d[i][j]==1){
                            cout<<i+1<<" "<<j+1<<"\n";
                        }
                    }
                }
                return;
            }
        }
    }
    cout<<"No"<<"\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    srand(time(0)^ll(new char));

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}